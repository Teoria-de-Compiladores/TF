#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

//Este módulo implementa las funciones que el LLVM IR llama para generar realmente un archivo WAV
#define SAMPLE_RATE 44100
#define TWO_PI 6.283185307179586476925286766559

static FILE *wavFile = NULL;
static int totalSamples = 0;

/* ============================================================
 *  El formato WAV obliga a que todos los nums multibyte
 *  estén escritos en little-endian. Estas funciones encapsulan
 *  esa lógica.
 * ============================================================
 */

 // Escribe un entero de 32 bits en little-endian
void write_little_endian_4(FILE *f, int value) {
    uint8_t bytes[4];
    bytes[0] = value & 0xFF;
    bytes[1] = (value >> 8) & 0xFF;
    bytes[2] = (value >> 16) & 0xFF;
    bytes[3] = (value >> 24) & 0xFF;
    fwrite(bytes, 1, 4, f);
}

// Escribe un entero de 16 bits en little-endian
void write_little_endian_2(FILE *f, int value) {
    uint8_t bytes[2];
    bytes[0] = value & 0xFF;
    bytes[1] = (value >> 8) & 0xFF;
    fwrite(bytes, 1, 2, f);
}

/* ============================================================
 *  ESCRITURA DEL HEADER WAV (con espacios sin completar)
 * ------------------------------------------------------------
 *  Un archivo WAV empieza con 44 bytes de cabecera.
 *  Como aún no sabiamos el tamaño total de audio, escribimos
 *  ceros en los campos "fileSize" y "dataSize". Luego se
 *  corrigen al final en finalize_wav().
 * ============================================================
 */
void write_wav_header_empty(FILE *f) {
    // Chunk RIFF
    fwrite("RIFF", 1, 4, f);
    write_little_endian_4(f, 0);  // (se llena al final)
    fwrite("WAVE", 1, 4, f);

    // Subchunk fmt
    fwrite("fmt ", 1, 4, f);
    write_little_endian_4(f, 16); // Tamaño del chunk fmt
    write_little_endian_2(f, 1);  // Formato PCM
    write_little_endian_2(f, 1);  // Mono
    write_little_endian_4(f, SAMPLE_RATE);
    write_little_endian_4(f, SAMPLE_RATE * 2); // byteRate = sampleRate * bits/8
    write_little_endian_2(f, 2);  // blockAlign
    write_little_endian_2(f, 16); // bitsPerSample

    // Subchunk data
    fwrite("data", 1, 4, f);
    write_little_endian_4(f, 0);  // (se llena al final)
}


//se actualiza tamaño total del archivo y tamaño de la sección de datos
void fix_wav_header_sizes(FILE *f) {
    int fileSize = ftell(f);
    int dataSize = fileSize - 44;

    // RIFF file size
    fseek(f, 4, SEEK_SET);
    write_little_endian_4(f, fileSize - 8);

    // data chunk size
    fseek(f, 40, SEEK_SET);
    write_little_endian_4(f, dataSize);
}

//Abre el archivo WAV y escribe un header provisional.
//Llamado por el compilador al inicio del programa.
void init_wav_writer() {
    wavFile = fopen("output.wav", "wb");
    write_wav_header_empty(wavFile);
    totalSamples = 0;
    printf("[runtime] WAV writer initialized\n");
}

/*
 * Genera un tono sinusoidal puro de frecuencia freqHz
 * durante durationMs milisegundos.
 *
 * Esta es la función principal que el LLVM IR llama para
 * representar una nota musical.
 */
void write_sine_note(double freqHz, int durationMs) {
    int samples = (SAMPLE_RATE * durationMs) / 1000;

    printf("[runtime] Write note %.2f Hz for %d ms\n", freqHz, durationMs);

    for (int i = 0; i < samples; i++) {
        double t = (double) i / SAMPLE_RATE;
        double sample = sin(TWO_PI * freqHz * t);

        // Convertir a PCM 16 bits
        int16_t pcm = (int16_t)(sample * 32767);
        fwrite(&pcm, sizeof(int16_t), 1, wavFile);
    }

    totalSamples += samples;
}

//Escribe silencio (sample = 0)
void write_rest(int durationMs) {
    int samples = (SAMPLE_RATE * durationMs) / 1000;

    printf("[runtime] REST for %d ms\n", durationMs);

    int16_t pcm = 0;
    for (int i = 0; i < samples; i++) {
        fwrite(&pcm, sizeof(int16_t), 1, wavFile);
    }

    totalSamples += samples;
}

void finalize_wav() {
    printf("[runtime] Finalizing WAV file...\n");

    fix_wav_header_sizes(wavFile);
    fclose(wavFile);
    printf("[runtime] WAV saved as output.wav\n");
}
