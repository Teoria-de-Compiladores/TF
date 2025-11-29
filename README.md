1. Generar ANTLR
mkdir -p gen/grammar

java -jar tools/antlr-4.13.1-complete.jar \
  -Dlanguage=Cpp -visitor \
  -o gen/grammar \
  src/AudioScore.g4

2. Configurar y compilar con CMake
rm -rf build
mkdir build
cd build

cmake ../src
cmake --build . -j4

El ejecutable quedara como : ./audioscorec

3. Probar el compilador + runtime
# 1. Crear una canción
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

# 2. Generar LLVM IR
./audioscorec song_estrellita.aud song.ll

# 3. Compilar IR + runtime
clang song.ll ../runtime/runtime_audio_wav.c -lm -o song_exe

# 4. Ejecutar y generar output.wav
./song_exe

----------------
CON JIT Y OPTIMIZACION
rm -rf build
mkdir build
cd build

cmake ../src
cmake --build . -j4

./audioscorec song_estrellita.aud
genera sólo sinopt.ll.

./audioscorec song_estrellita.aud -O
genera sinopt.ll + optimized.ll.

./audioscorec song_estrellita.aud -jit
genera sinopt.ll y ejecuta el JIT, creando output.wav.

./audioscorec song_estrellita.aud -O -jit
aplica O2, escribe optimized.ll y JIT ejecuta la versión optimizada.