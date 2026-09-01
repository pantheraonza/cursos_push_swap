*Este proyecto ha sido creado como parte del currículo de 42 por acamelo y
criredon.*

# push_swap

## 1. Descripción general y objetivo del proyecto

`push_swap` ordena una lista de enteros usando dos stacks (`a` y `b`) y únicamente las operaciones `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb` y `rrr`. El programa no imprime los números ordenados: imprime la secuencia de operaciones necesaria para conseguirlo.

Introduce una idea importante: que se aprenda a elegir algoritmos según su **complejidad**, es decir, cómo crece el número de operaciones cuando aumenta la cantidad de datos. 

El proyecto trabaja cuatro ideas principales: **stacks**, donde solo se manipulan posiciones concretas; **índice de desorden**, que permite adaptar la estrategia a la entrada; **complejidad Big-O**, que permite comparar cómo escala un algoritmo; **algoritmos de ordenación**, especialmente de selección y extracción, partición por chunks y Radix Sort.

## 2. Instrucciones

### 2.1. Compilación, Instalación y Ejecución

``` bash
make
./push_swap 4 67 3 87 23
./push_swap --simple 4 67 3 87 23
./push_swap --medium 4 67 3 87 23
./push_swap --complex 4 67 3 87 23
./push_swap --adaptive 4 67 3 87 23
```

El Makefile incluye `all`, `clean`, `fclean` y `re` y compila con
`cc -Wall -Wextra -Werror`.

### 2.2. Ejemplos de Uso

``` bash
./push_swap 2 1
sa
```

Comprobación con el checker proporcionado:

``` bash
ARG="4 67 3 87 23"
./push_swap --complex $ARG | ./checker_linux $ARG
# OK
```

Número de operaciones:

``` bash
ARG="4 67 3 87 23"
./push_swap $ARG | wc -l
```

## 3. Recursos

### 3.1. Referencias clásicas consultadas:

-   Cormen, Leiserson, Rivest y Stein, *Introducción a los algoritmos*:
    capítulos **"Crecimiento de funciones"** y **"Ordenación en tiempo
    lineal"**, especialmente Radix Sort.
-   Kernighan y Ritchie, *El lenguaje de programación C*: capítulos
    **"Punteros y arrays"** y **"Estructuras"**, base para comprender
    nodos y listas enlazadas.

### 3.2. Tutoriales y Repositorios de Programadores Expertos

Se utilizaron como fuente de estudios, referencia y contraste:

https://www.youtube.com/watch?v=OaG81sDEpVk&t=1473s

https://www.youtube.com/watch?v=0_5lzKurS74

https://www.youtube.com/watch?v=XiuSW_mEn7g

https://www.youtube.com/watch?v=M2cCN7Gzl9U

https://github.com/hu8813/tester_push_swap

### 3.3. Uso de Inteligencia Artificial

La IA se utilizó como apoyo para explicar conceptos, comparar arquitecturas, revisar riesgos, aclarar y apoyar la solución de errores, proponer casos de prueba y ayudar con la documentación. 

## 4. Decisiones técnicas, ejecución y estructura de datos

### 4.1. Decisiones Técnicas - ¿Qué arquitectura se eligió y por qué?

Se utiliza una **lista enlazada simple**. Cada nodo guarda el valor original, su índice ordenado y un puntero al siguiente nodo. Esta solución evita estructuras innecesarias y permite representar directamente cada stack. Los valores se convierten previamente en índices `0..n-1`. Así, los algoritmos trabajan con posiciones relativas y no con los valores originales.

### 4.2 ¿Cuál es el flujo del proceso y la estructura de datos del proyecto?

``` text
INICIO
  |
  v
Leer flags de estrategias deseadas y números
  |
  v
¿Entrada válida? ---- no ----> Error
  |
 sí
  v
Crear stack A
  |
  v
Asignar índices
  |
  v
Calcular desorden
  |
  v
Seleccionar y ejecutar estrategia
  |
  +--> Simple
  +--> Medium
  +--> Complex
  +--> Adaptive
  |
  v
Ejecutar e imprimir operaciones
  |
  v
Liberar memoria
  |
  v
FIN
```

Archivos principales:

-   `0_main.c`: coordina el programa.
-   `1_detect_flags.c`: interpreta las flags.
-   `2_parse_numbers.c`: valida y convierte argumentos.
-   `3_prepare_stack.c`: crea, indexa y libera el stack.
-   `4_calculate_disorder.c`: calcula el índice de desorden.
-   `5_1_execute_strategy.c`: selecciona la estrategia.
-   `5_2_sort_simple.c`: algoritmo simple.
-   `5_3_sort_medium.c`: algoritmo por chunks.
-   `5_4_sort_complex.c`: Radix Sort.
-   `5_5_sort_adaptative.c`: estrategia adaptativa.
-   `6_*_operations_*.c`: operaciones permitidas.

### 4.3 ¿Qué fundamentos hicieron falta para comprender el proyecto?

**Stack:** estructura donde el elemento superior es el punto principal de acceso.

**Lista enlazada:** conjunto de nodos conectados mediante punteros. Permite mover nodos sin copiar todos los elementos.

**Índice normalizado:** posición que tendría un valor si todos estuvieran ordenados. Simplifica comparaciones y Radix Sort.

**Índice de desorden:** proporción entre pares invertidos y pares totales. Se calcula antes de realizar movimientos.

**Big-O:** describe cómo aumenta el trabajo al crecer `n`. En este proyecto se mide principalmente por las operaciones de Push_swap emitidas.

La estrategia adaptativa usa los umbrales exigidos por el subject:

-   desorden `< 0.2` → objetivo `O(n)`;
-   `0.2 <= desorden < 0.5` → objetivo `O(n√n)`;
-   desorden `>= 0.5` → objetivo `O(n log n)`.

La estrategia adaptativa selecciona directamente uno de los tres algoritmos según el índice de desorden: sort_simple() para desorden < 0.2, sort_medium() para 0.2 <= desorden < 0.5 y sort_complex() para desorden >= 0.5.

El algoritmo simple extrae mínimos repetidamente. El intermedio divide los índices en grupos de tamaño cercano a `√n`. El complejo aplica Radix Sort: en cada pasada examina un bit del índice, enviando un grupo a `b` y manteniendo el otro en `a`.

### 4.4. ¿Cuáles algoritmos fueron considerados y cuáles fueron elegidos en el proyecto?

El subject permite escoger distintas familias de algoritmos para cada nivel de complejidad. En esta implementación se ha priorizado una solución fácil de entender y adaptar a las operaciones de `push_swap`: extracción del mínimo para la estrategia simple, chunks/rangos para la estrategia intermedia, LSD Radix Sort para la compleja y una estrategia adaptativa que selecciona el método según el índice de desorden.

### TABLA RESUMEN DE LAS ESTRATEGIAS Y ALGORITMOS SELECCIONADOS

| Estrategia | Algoritmo seleccionado | Complejidad objetivo | Idea principal |
|---|---|---|---|
| **Simple** | **Minimum Extraction (Métodos simples de extracción del mínimo/máximo)** | **O(n²)** | Buscar el mínimo, llevarlo al `top` y moverlo temporalmente a `b`. |
| **Intermedia** | **Chunk-based / Range-based Sorting (Orden basado en chunks / Estrategias de orden basadas en rangos)** | **O(n√n)** | Dividir los índices en rangos de tamaño aproximado `√n` y procesarlos por grupos. |
| **Compleja** | **LSD Radix Sort (Adaptación del orden radix LSD)** | **O(n log n)** | Recorrer los bits de los índices desde el menos significativo usando `pb`, `ra` y `pa`. |
| **Adaptativa** | **Custom Adaptive Sorting Algorithm (Algoritmo adaptativo personalizado)** | **O(n) / O(n√n) / O(n log n)** | Elegir la estrategia según el desorden: sort_simple() si < 0.2, sort_medium() si 0.2 <= desorden < 0.5 y sort_complex() si >= 0.5 |

**TABLA DE LAS FAMÍLIAS DE ALGORITMOS Y JUSTIFICACIÓN**
| Nivel | Algoritmo | Explicación en 1 frase | Cuándo es indicado | Dificultad de implementación | Utilización en este proyecto |
|---|---|---|---|---|---|
| **Simple — O(n²)** | **Selection Sort (Adaptación del orden por selección)** | Busca repetidamente el menor elemento pendiente y lo coloca en su posición definitiva. | Listas pequeñas cuando se prioriza una lógica sencilla. | 🟢 Muy fácil | **Sí, como principio.** `sort_simple()` busca repetidamente el mínimo antes de extraerlo hacia `b`. |
| **Simple — O(n²)** | **Minimum/Maximum Extraction (Métodos simples de extracción del mínimo/máximo)** | Busca repetidamente el menor o mayor elemento, lo lleva al `top` y lo extrae para reconstruir el orden. | Cuando mover extremos entre stacks resulta natural y fácil de visualizar. | 🟢 Muy fácil | **Sí.** `sort_simple()` localiza el mínimo, lo lleva arriba, hace `pb` y finalmente devuelve los elementos con `pa`. |
| **Simple — O(n²)** | **Bubble Sort (Adaptación del orden burbuja)** | Compara elementos vecinos y los intercambia cuando están en orden incorrecto hasta ordenar el conjunto. | Principalmente aprendizaje o listas muy pequeñas. | 🟢 Muy fácil | **No.** |
| **Simple — O(n²)** | **Insertion Sort (Adaptación del orden por inserción)** | Toma cada elemento y lo inserta en la posición correcta respecto a los elementos ya ordenados. | Listas pequeñas o casi ordenadas. | 🟢 Fácil | **No.** |
| **Intermedio — O(n√n)** | **Chunk-based Sorting (Orden basado en chunks, dividiendo en √n chunks)** | Divide los índices en grupos de tamaño aproximado `√n` y procesa cada grupo por separado. | Entradas medianas donde se quiere limitar el rango tratado en cada etapa. | 🟡 Media-baja | **Sí.** `sort_medium()` calcula un tamaño de chunk aproximado a `√n` y procesa los rangos uno a uno. |
| **Intermedio — O(n√n)** | **Range-based Sorting (Estrategias de orden basadas en rangos)** | Procesa los elementos cuyo índice pertenece al rango activo y después avanza al siguiente intervalo. | Cuando los valores ya están convertidos en índices consecutivos. | 🟡 Media-baja | **Sí.** `push_chunk()` mueve a `b` los nodos comprendidos entre `first_index` y `last_index`. |
| **Intermedio — O(n√n)** | **Block Partitioning (Métodos de partición basados en bloques)** | Divide el conjunto en bloques y procesa los elementos de cada bloque antes de reconstruir el orden. | Cuando interesa reducir el conjunto activo en cada fase. | 🟡 Media | **No.** |
| **Intermedio — O(n√n)** | **Bucket Sort with √n Buckets (Adaptaciones del orden por buckets con √n buckets)** | Agrupa los elementos en aproximadamente `√n` buckets según su rango antes de reconstruir el orden. | Cuando los valores están normalizados y pueden agruparse fácilmente por intervalos. | 🟡 Media | **No.** |
| **Complejo — O(n log n)** | **Radix Sort, LSD or MSD (Adaptación del orden radix, LSD o MSD)** | Ordena los elementos procesando sucesivamente sus dígitos o bits según su peso. | Entradas grandes con índices normalizados. | 🟡 Media | **Sí, LSD.** `sort_complex()` procesa los bits desde el menos significativo usando `pb`, `ra` y `pa`. |
| **Complejo — O(n log n)** | **Merge Sort (Adaptación del orden por fusión utilizando dos stacks)** | Divide los datos en grupos y los fusiona ordenadamente hasta reconstruir el conjunto completo. | Cuando se busca una complejidad estable `O(n log n)`. | 🔴 Difícil | **No.** |
| **Complejo — O(n log n)** | **Quick Sort (Adaptación del orden rápido con partición por stacks)** | Elige pivotes, separa menores y mayores y ordena después cada partición. | Cuando pueden realizarse particiones eficientes alrededor de pivotes. | 🔴 Difícil | **No.** |
| **Complejo — O(n log n)** | **Heap Sort (Adaptación del orden por montículos)** | Organiza los elementos como un montículo para extraer repetidamente el mayor o menor. | Cuando la estructura permite acceder eficientemente a las relaciones del montículo. | 🔴 Muy difícil | **No.** |
| **Complejo — O(n log n)** | **Binary Indexed Tree / Fenwick Tree (Algoritmos de árbol binario indexado)** | Usa una estructura de árbol indexado para realizar consultas y actualizaciones de información acumulada eficientemente. | Problemas avanzados que necesitan consultas rápidas sobre índices. | 🔴 Muy difícil | **No.** |
| **Adaptativo — según desorden** | **Custom Adaptive Sorting Algorithm (Algoritmo adaptativo personalizado)** | Calcula el desorden inicial y selecciona una estrategia diferente según el nivel detectado. | Cuando se quiere adaptar el método al estado inicial de la entrada. | 🟡 Media | **Sí.** sort_adapt() utiliza sort_simple() para < 0.2, sort_medium() para 0.2 <= desorden < 0.5 y sort_complex() para >= 0.5. |

### 4.4. Colaboración del equipo  en la ejecución del proyectoo

El proyecto se estructuró por bloques funcionales, repartiendo el trabajo entre ambas estudiantes: Alison Camelo (acamelo) se encargó del tratamiento de la entrada (validación y parseo), preparación de los stacks y cálculo del desorden, mientras que Cristina Redondo (criredon) desarrolló la estructura funcional, las estrategias de ordenación y la integración del programa. Ambas colaboraron en las pruebas, corrección de errores, adecuación a la Norminette y validación final.

### 4.5. Mitigación de riesgos del proyecto

Antes de entregar deben probarse: entrada vacía, un número, números ya ordenados, negativos, `INT_MIN`, `INT_MAX`, duplicados, texto, overflow y todas las flags.

Prueba funcional:

``` bash
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker_linux $ARG
```

Prueba de memoria:

``` bash
valgrind --leak-check=full ./push_swap 5 4 3 2 1
```

Prueba mínima de rendimiento:

``` bash
ARG="$(shuf -i 1-10000 -n 100)"
./push_swap $ARG | wc -l
# < 2000

ARG="$(shuf -i 1-10000 -n 500)"
./push_swap $ARG | wc -l
# < 12000
```

## 5. Conclusión

`push_swap` enseña que ordenar correctamente no es suficiente: también importa **cómo escala la solución**. El aprendizaje central es analizar una entrada, representar los datos y escoger una estrategia cuya cantidad de operaciones sea adecuada para cada situación.
