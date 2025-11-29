AudioScoreLang/
├── grammar/
│   └── AudioScore.g4
├── gen/                 # aquí ANTLR generará los .h/.cpp del parser/lexer
├── src/
│   ├── AudioIR.h        # definición de la IR musical (SongIR, Event, etc.)
│   ├── AudioIRBuilder.h # visitor que convierte AST → IR musical
│   ├── AudioIRBuilder.cpp
│   ├── CodeGenLLVM.h    # genera el archivo .ll (LLVM IR en texto)
│   ├── CodeGenLLVM.cpp
│   └── main.cpp         # punto de entrada: usa ANTLR, builder y codegen
├── runtime/
│   └── runtime_audio.c  # implementación de init_audio, play_note, etc.
└── build/               # donde dejarás compilados, .ll, ejecutable, etc.

mkdir -p tools
cd tools
wget https://www.antlr.org/download/antlr-4.13.1-complete.jar
ls

cd ..
java -jar tools/antlr-4.13.1-complete.jar -Dlanguage=Cpp -visitor \
  -o gen grammar/AudioScore.g4

pacman -Syu antlr4-runtime
pacman -Ql antlr4-runtime | grep antlr4-runtime.h

Compilar los .cpp generados de ANTLR
g++ -std=c++17 \
  -I/usr/include/antlr4-runtime \
  -Igen/grammar \
  -c gen/grammar/*.cpp

Compilar tus fuentes (src/)
g++ -std=c++17 \
  -I/usr/include/antlr4-runtime \
  -Igen/grammar \
  -c src/main.cpp src/AudioIRBuilder.cpp src/CodeGenLLVM.cpp


Enlazar todo con la librería antlr4-runtime
g++ -std=c++17 \
  *.o \
  -L/usr/lib \
  -lantlr4-runtime \
  -o audioscorec


Probar el compilador y el runtime
cat > song.aud << 'EOF'
tempo 100;
C4 q;
D4 q;
E4 h;
rest e;
EOF
---
cat > song_estrellita.aud << 'EOF'
tempo 100;

C4 q;
C4 q;
G4 q;
G4 q;
A4 q;
A4 q;
G4 h;

F4 q;
F4 q;
E4 q;
E4 q;
D4 q;
D4 q;
C4 h;

G4 q;
G4 q;
F4 q;
F4 q;
E4 q;
E4 q;
D4 h;

G4 q;
G4 q;
F4 q;
F4 q;
E4 q;
E4 q;
D4 h;

C4 q;
C4 q;
G4 q;
G4 q;
A4 q;
A4 q;
G4 h;

F4 q;
F4 q;
E4 q;
E4 q;
D4 q;
D4 q;
C4 h;
EOF


Generar LLVM IR:
mkdir -p build
./audioscorec song.aud build/song.ll
./audioscorec song_estrellita.aud build/song.ll

Compilar IR + runtime:
clang build/song.ll runtime/runtime_audio_wav.c -lm -o build/song_exe

Ejecutar:
./build/song_exe

=========================
1) Regenerar ANTLR
java -jar tools/antlr-4.13.1-complete.jar -Dlanguage=Cpp -visitor \
  -o gen grammar/AudioScore.g4

2) Compilar ANTLR
g++ -std=c++17 -I/usr/include/antlr4-runtime -Igen/grammar -c gen/grammar/*.cpp

3) Compilar tus fuentes
g++ -std=c++17 -I/usr/include/antlr4-runtime -Igen/grammar \
  -c src/main.cpp src/AudioIRBuilder.cpp src/CodeGenLLVM.cpp

4) Enlazar
g++ -std=c++17 *.o -lantlr4-runtime -o audioscorec

5) Generar IR
mkdir -p build
./audioscorec song.aud build/song.ll

6) Compilar con nuevo runtime WAV
clang build/song.ll runtime/runtime_audio_wav.c -lm -o build/song_exe

7) Ejecutar
./build/song_exe


======================
final

java -jar tools/antlr-4.13.1-complete.jar -Dlanguage=Cpp -visitor \
  -o gen grammar/AudioScore.g4

mkdir -p build
cd build

en lugar de Compilar los .cpp generados de ANTLR y Compilar tus fuentes (src/)
cmake ..
cmake --build .

cd ..
./build/audioscorec song_estrellita.aud build/song.ll
clang build/song.ll runtime/runtime_audio_wav.c -lm -o build/song_exe

./build/song_exe
======================
# TF
# TF
