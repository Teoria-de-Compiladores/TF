# AudioScoreLang: Compilación de un Lenguaje Musical a Audio Digital (WAV)

**Universidad Peruana de Ciencias Aplicadas**
**Curso:** Teoría de Compiladores (2025-2)
**Sección:** 1731

**Integrantes - Grupo 10:**
* **Meza Polo, Rodrigo Alejandro** (U202224016)
* **Figueroa Larragan, Marsi Valeria** (U202220990)

---

## 📋 Resumen

El presente proyecto introduce **AudioScoreLang**, un lenguaje específico de dominio (DSL) diseñado para la composición musical algorítmica. A diferencia de los secuenciadores tradicionales, este lenguaje permite describir piezas musicales mediante una sintaxis estructurada que soporta **bucles, patrones reutilizables y notación musical directa**.

El sistema implementado constituye un compilador completo que integra:
1.  **Frontend:** Análisis léxico y sintáctico con **ANTLR4**.
2.  **Backend:** Generación de Código Intermedio (**LLVM IR**) con optimizaciones y gestión de flujo de control.
3.  **Ejecución:** Motor **JIT** (Just-In-Time) para reproducción inmediata y Runtime en C para la síntesis digital de señales (DSP).

En conjunto, AudioScoreLang demuestra cómo el diseño de lenguajes formales y la infraestructura de LLVM pueden aplicarse para crear herramientas creativas, abstrayendo la complejidad matemática del audio digital.

---

## 1. Problemática y Motivación

La generación autónoma de audio digital a partir de descripciones simbólicas (como notas, duraciones y estructuras musicales) sigue siendo un reto técnico relevante dentro del campo de la síntesis sonora y los lenguajes formales. Aunque existen herramientas profesionales como SuperCollider o Pure Data, estas requieren conocimientos avanzados en programación y diseño de sistemas de audio, lo cual dificulta su adopción por estudiantes o desarrolladores que buscan un entorno más accesible para construir piezas musicales de forma programática.

Desde una perspectiva técnica, la síntesis digital implica traducir instrucciones abstractas (por ejemplo, “tocar A4 por 500 ms”) a señales discretas que representen correctamente una onda sonora. Esto exige comprender conceptos como muestreo, cuantización, amplitud, y generación de tonos sinusoidales, cuya complejidad es detallada en obras de referencia del dominio del audio digital.

**Sin embargo, la mayoría de herramientas simplificadas suelen ser estrictamente secuenciales o declarativas, careciendo de las capacidades de abstracción propias de los lenguajes de programación modernos. La composición musical, por naturaleza, es repetitiva y estructurada (coros, compases rítmicos, variaciones); por tanto, la falta de estructuras de control de flujo (como bucles) y modularización (patrones reutilizables) obliga al usuario a escribir código redundante y difícil de mantener.**

Por otro lado, el formato WAV requiere una estructura rígida que incluya cabeceras específicas y datos codificados en orden little-endian. Para un usuario sin conocimientos de bajo nivel, generar un WAV válido implica manipular bytes, tamaños de bloques y cálculos matemáticos que distan de la intención creativa del compositor.

En este contexto surge la motivación para desarrollar **AudioScoreLang**, un lenguaje diseñado para permitir que los usuarios especifiquen música mediante una sintaxis clara y accesible, mientras que el compilador se encarga de traducir dichas instrucciones a LLVM IR y posteriormente a audio real a través de un runtime en C. La propuesta no solo integra conceptos musicales básicos, **sino que introduce paradigmas de programación estructurada aplicados a la música. Al incorporar sentencias de control (`loops`) y definición de bloques reutilizables (`patterns`), AudioScoreLang busca reducir la brecha entre la composición simbólica lineal y la composición algorítmica.**

---

## 2. Objetivos

### 2.1. Objetivo General
Desarrollar **AudioScoreLang**, un lenguaje de dominio específico (DSL) basado en la infraestructura de **ANTLR4** y **LLVM**, diseñado para la **composición musical algorítmica**. El proyecto busca transformar descripciones simbólicas y **estructuras de control de flujo** en audio digital (WAV), mediante un proceso de compilación integral que abarca el análisis léxico-sintáctico, la **generación y optimización de código intermedio (LLVM IR)**, la ejecución inmediata (JIT) y la síntesis de señales a través de un runtime nativo en C.

### 2.2. Objetivos Específicos
* **Definir una gramática formal extendida** para el lenguaje AudioScoreLang empleando **ANTLR4**, estableciendo reglas léxicas y sintácticas que soporten no solo elementos musicales básicos (notas, silencios, tempo), sino también **estructuras de control de flujo (bucles) y abstracción procedural (patrones)**.
* **Implementar el análisis léxico y sintáctico** para construir el Árbol de Sintaxis Abstracta (AST), asegurando la detección temprana de errores y la correcta interpretación de la jerarquía del programa.
* **Diseñar el backend del compilador en C++**, traduciendo el AST a **LLVM Intermediate Representation (LLVM IR)**. Este proceso incluye la gestión de memoria en el Stack y el uso de **Bloques Básicos (Basic Blocks) y saltos condicionales** para soportar la lógica no lineal de los bucles y las llamadas a subrutinas musicales.
* **Desarrollar un Runtime System nativo en C** encargado de la síntesis digital de señales (DSP), implementando la generación matemática de ondas sinusoidales, la conversión a formato PCM y la gestión de cabeceras binarias.
* **Integrar el motor de ejecución Just-In-Time (JIT) de LLVM**, configurando el **enlazado dinámico manual** (*Dynamic Linking*) entre el código generado en memoria y las funciones del Runtime, permitiendo la reproducción inmediata.
* **Aplicar técnicas de optimización de código** mediante el **PassManager de LLVM (O2)**, analizando y transformando el grafo de flujo del código intermedio para eliminar redundancias.
* **Validar la robustez y fidelidad del compilador** mediante una batería de pruebas que incluya casos de estrés, verificación de frecuencias y manejo de errores sintácticos.

---

## 3. Propuesta de Solución

La solución propuesta consiste en el diseño y desarrollo de **AudioScoreLang**, un lenguaje formal que permite describir piezas musicales no solo de manera lineal, sino mediante una sintaxis estructurada y algorítmica. Este lenguaje es traducido a audio digital mediante un proceso de compilación avanzado basado en la infraestructura de **LLVM**.

Para lograr esto, la arquitectura integra tres componentes principales:

1.  **Gramática (ANTLR4):** Esta capa ha sido extendida para soportar estructuras de alto nivel como bucles de repetición (`loops`) y la definición de patrones melódicos reutilizables (`patterns`). Genera un Árbol de Sintaxis Abstracta (AST) jerárquico que captura la lógica compositiva.
2.  **Backend (AudioDriver):** Basado en C++ y LLVM. Para soportar la lógica no lineal introducida por los bucles, el backend gestiona explícitamente el flujo de control mediante la creación de **Bloques Básicos (`BasicBlocks`)** y la inserción de instrucciones de salto condicional (`Branching`). Asimismo, implementa un sistema de gestión de símbolos para almacenar y recuperar los patrones musicales.
3.  **Runtime System (C):** Responsable de la síntesis digital de señales (DSP). Abstrae la complejidad de la manipulación de archivos binarios, encargándose de la construcción del formato WAV (PCM Little-Endian).

Con la integración de estas capas, AudioScoreLang opera en dos modos: **Generación de Archivos** (Compilación tradicional) y **Ejecución JIT** (Reproducción inmediata en memoria).

---

## 4. Fundamentos Teóricos Musicales y Matemáticos

### 4.1. Representación musical de notas y octavas
En la música occidental, una nota se define por su altura (pitch). Las notas se organizan en un conjunto de 12 semitonos por octava: `C, C#, D, D#, E, F, F#, G, G#, A, A#, B`.
Cada octava duplica la frecuencia de la anterior ($A4 = 440 Hz$, $A5 = 880 Hz$).

### 4.2. Número MIDI y conversión a frecuencia
La relación entre el número MIDI y la frecuencia en Hertz está definida por:

$$f = 440 \times 2^{\frac{midi - 69}{12}}$$

Esta fórmula es crítica en el backend LLVM del compilador, ya que transforma una instrucción musical abstracta en un parámetro matemático directo para la generación del sonido.

### 4.3. Duraciones rítmicas
La duración en milisegundos se calcula mediante el **Tempo** (BPM) y la figura musical:

$$ms = \frac{60000}{BPM} \times \text{proporción}$$

### 4.4. Síntesis y Procesamiento Digital de Señales
El audio generado por el runtime se basa en los principios de muestreo digital:
* **Sample Rate:** $44100 Hz$ (Estándar CD).
* **Señal Sinusoidal:** $x(t) = \sin(2\pi f t)$.
* **Conversión a PCM:** $pcm = \lfloor \sin(2\pi f t) \times 32767 \rfloor$.

### 4.5. Estructura del formato WAV
Un archivo WAV sigue el estándar RIFF y contiene un encabezado de 44 bytes seguido de los datos PCM. En AudioScoreLang, el runtime escribe un encabezado vacío, genera los datos, y finalmente regresa al inicio del archivo (`fseek`) para corregir los tamaños antes de cerrar.

---

## 5. Arquitectura de la Solución

### 5.1. Gramática en ANTLR - Definición del Lenguaje
La gramática ha sido extendida para soportar composición algorítmica.

**Estructura válida de un archivo .aud:**

| Elemento | Descripción | Ejemplo |
| :--- | :--- | :--- |
| `tempo` | Define la velocidad (BPM). | `tempo 120;` |
| `pattern` | Define un bloque de música reutilizable. | `pattern coro { ... }` |
| `play` | Invoca/ejecuta un patrón. | `play coro;` |
| `loop` | Repite una secuencia $N$ veces. | `loop 4 { ... }` |
| `Nota` | Instrucción atómica de sonido. | `C4 q` |

### 5.2. Backend del Compilador - AudioDriver (LLVM)
El **AudioDriver** gestiona la generación de código y el **Grafo de Flujo de Control (CFG)**.

#### 5.2.5. Procesamiento semántico
* **Implementación de `visitLoopStmt`:** Para soportar la instrucción `loop N`, el backend genera una estructura de control real en LLVM IR utilizando **Bloques Básicos**.
    1.  Crea tres bloques lógicos: `loop.header` (condición), `loop.body` (cuerpo) y `loop.end` (salida).
    2.  Gestiona un contador en el Stack (`alloca`).
    3.  Inserta saltos condicionales (`CreateCondBr`) para controlar la iteración.
* **Implementación de `visitPatternDecl`:** Almacena el sub-árbol sintáctico en un mapa interno, permitiendo su reutilización posterior mediante la instrucción `play` (Inlining).

#### 5.2.6. Generación del LLVM IR
El producto final es un módulo de LLVM IR. El compilador inserta directivas `declare` para las funciones externas y genera llamadas `call` con los argumentos matemáticos calculados.

#### 5.2.7. Optimización del Módulo
Se integra el **PassManager** de LLVM (`-O2`), el cual aplica transformaciones como propagación de constantes y eliminación de código muerto para mejorar la eficiencia del binario generado.

### 5.3. Runtime del Sistema
Componente en C encargado de la síntesis. Expone la función `write_sine_note`, la cual implementa la discretización de la onda sinusoidal y la escritura en formato Little-Endian.

![Figura: Implementación de write_sine_note]

### 5.4. Modo de Ejecución: Compilación vs. JIT
**AudioScoreLang** implementa dos modos:
1.  **Estático:** Genera archivos `.ll` y `.wav` en disco.
2.  **JIT (Just-In-Time):** Utiliza el `ExecutionEngine` de LLVM. El desafío principal fue el **Enlazado Dinámico Manual** (`addGlobalMapping`), necesario para conectar las funciones del IR generado en memoria con las funciones del Runtime del proceso anfitrión.

![Figura: Enlazado Dinámico en runWithJIT]

---

## 6. Plan de Validación

El plan de validación asegura que el compilador traduzca correctamente estructuras complejas.

**Estrategia de Pruebas:**
1.  **Frontend:** Verificación de detección de errores sintácticos ("Guard Clauses").
2.  **Backend:** Validación de la generación de bloques básicos para bucles y gestión del Stack.
3.  **Funcional (End-to-End):** Análisis auditivo de afinación, ritmo y transiciones entre patrones.

---

## 7. Resultados de la Validación

Se ejecutó una batería de pruebas cubriendo las nuevas funcionalidades.

**7.1. Validación de Control de Flujo (`song_patterns.aud`)**
* **Objetivo:** Verificar `loop` y `pattern`.
* **Resultado:** El compilador generó exitosamente los bloques básicos. La instrucción `play` funcionó como un mecanismo de *inlining*. El audio resultante respeta la estructura repetitiva definida sin errores de memoria.

**7.2. Validación de Frecuencias (`star_wars.aud`)**
* **Objetivo:** Validar precisión de notas y saltos de octava.
* **Resultado:** La melodía generada presenta una afinación correcta y precisión en los tiempos, validando las fórmulas matemáticas del backend.

**7.3. Validación de Robustez (`error.aud`)**
* **Resultado:** El parser interceptó el error sintáctico y detuvo la ejecución antes de invocar al backend, impidiendo la generación de archivos corruptos.

**7.4. Evidencia de Ejecución**

![Ejecución Exitosa en Consola]
*(Se observa la compilación JIT y la generación de archivos intermedios)*

![Análisis de Forma de Onda]
*(Visualización del archivo WAV generado en un editor de audio)*

---

## 8. Conclusiones

El desarrollo de AudioScoreLang ha culminado exitosamente, demostrando que es posible crear una herramienta capaz de ir mucho más allá de la simple traducción lineal de notas. En primer lugar, se logró integrar de manera efectiva un sistema de reglas gramaticales con un motor de procesamiento robusto, lo cual permitió incorporar **lógica de programación real** —como la repetición de estructuras y la reutilización de melodías— dentro del ámbito musical. Esto valida la capacidad del proyecto para modelar composiciones complejas de forma eficiente.

Por otro lado, la incorporación de un modo de **ejecución inmediata (JIT)** resultó ser un factor crítico para mejorar la experiencia de uso. Al eliminar la necesidad de crear archivos temporales y realizar la conexión de los componentes directamente en la memoria del ordenador, se redujo drásticamente el tiempo de espera entre la escritura del código y la escucha del resultado. Esta rapidez transforma al compilador en una herramienta interactiva.

Finalmente, el proyecto cumplió su objetivo fundamental de **ocultar la dificultad matemática y binaria** al usuario final. Gracias al uso de una representación intermedia y un sistema de soporte que opera en segundo plano, se logró abstraer los cálculos físicos del sonido y los detalles del formato de archivo. De esta manera, el programador puede enfocarse exclusivamente en la lógica musical de alto nivel, confiando en que el sistema se encargará automáticamente de optimizar el rendimiento.

---

## 9. Referencias Bibliográficas
1.  Puckette, M. (2007). *The Theory and Technique of Electronic Music*. UCSD.
2.  Smith, J. O. (2011). *Spectral Audio Signal Processing*. Stanford CCRMA.
3.  Microsoft. (2022). *WAVEFORMAT structure*. Microsoft Learn.
4.  LLVM Language Reference Manual. https://llvm.org/docs/LangRef.html