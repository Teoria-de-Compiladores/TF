# AudioScoreLang 🎵 -> 💻 -> 🔊

**Compilador de Lenguaje Musical a Audio Digital (WAV)**
*Curso: Teoría de Compiladores (2025-2)*
*Universidad Peruana de Ciencias Aplicadas (UPC)*

## 👥 Autores - Grupo 10
* **Rodrigo Meza Polo** (U202224016)
* **Marsi Valeria Figueroa** (U202220990)

## 📖 Descripción
**AudioScoreLang** es un lenguaje de dominio específico (DSL) diseñado para la **composición musical algorítmica**. Permite a los usuarios describir música utilizando una sintaxis clara que soporta notas, ritmos y estructuras de control avanzadas.

El compilador traduce este código fuente a **LLVM IR** (Intermediate Representation) y utiliza un motor **JIT (Just-In-Time)** para sintetizar audio en formato WAV en tiempo real, o bien generar archivos para su compilación estática.

## 🚀 Características Principales

### 🎼 Lenguaje Musical
* **Notación Intuitiva:** Escritura sencilla de notas (ej. `C4`, `F#5`) y duraciones (`q`=negra, `h`=blanca, `e`=corchea).
* **Gestión de Tempo:** Control preciso de la velocidad en BPM (`tempo 120;`).

### 🎛️ Estructuras de Control y Modularidad
* **Bucles (`loop`):** Repetición de bloques musicales con gestión de flujo de control (Branching).
* **Patrones (`pattern`):** Definición de melodías reutilizables como subrutinas.
* **Invocación (`play`):** Reutilización de patrones mediante llamadas (Inlining).

### ⚙️ Tecnología del Compilador
* **Frontend:** Análisis léxico y sintáctico robusto con **ANTLR4**.
* **Backend:** Generación de código intermedio **LLVM IR**.
* **Optimización:** Integración del **PassManager** de LLVM (Nivel O2).
* **Runtime:** Sistema de síntesis de señal digital (DSP) nativo en **C**.
* **Ejecución JIT:** Reproducción inmediata en memoria sin pasos intermedios.

## 🛠️ Requisitos del Sistema

Para compilar y ejecutar este proyecto necesitas:

* **CMake** (3.20 o superior)
* **Compilador C++** (Clang o GCC con soporte C++17)
* **LLVM 14+** (Librerías Core, ExecutionEngine, Support, Native)
* **ANTLR4 Runtime**

## ⚙️ Instrucciones de Construcción (Build)

Sigue estos pasos para compilar el proyecto desde cero:

```bash
# 1. Clonar el repositorio
git clone [https://github.com/Teoria-de-Compiladores/TF.git](https://github.com/Teoria-de-Compiladores/TF.git)
cd src

# 2. Crear el directorio de compilación
mkdir build && cd build

# 3. Configurar con CMake
cmake ..

# 4. Compilar el ejecutable
make

# 5. Ejecutar el compilador
./audioscorec <archivo_entrada.aud> [flags]

Banderas (Flags)
-O: Activa las optimizaciones del código intermedio (LLVM O2 PassManager).
-jit: Ejecuta el código en memoria y reproduce el audio inmediatamente.
```

## 📂 Estructura del Proyecto

* **/grammar**: Definición de la gramática AudioScore.g4 (Lexer/Parser).
* **/src**: Código fuente C++ del compilador.
* **AudioDriver.h**: Backend y generación de IR (Visitor).
* **AudioMain.cpp**: Punto de entrada y configuración JIT.
* **/runtime**: Código C para la síntesis de audio (runtime_audio_wav.c).
* **/docs**: Documentación e Informe Final del proyecto.
* **/examples**: Archivos .aud de prueba (Mario, Star Wars, etc.).

## 📜 Licencia
Este proyecto fue desarrollado con fines académicos para el curso de Teoría de Compiladores de la UPC.
