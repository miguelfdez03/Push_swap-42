# 🔄 Push_swap

<h3 align="center">Algoritmo de ordenación de pilas en C</h3>

<p align="center">
  <img src="https://img.shields.io/badge/Lenguaje-C-blue" alt="Lenguaje">
  <img src="https://img.shields.io/badge/Proyecto-42-lightgrey" alt="Proyecto">
  <img src="https://img.shields.io/badge/Estado-Completado-success" alt="Estado">
</p>

---

## 📝 Descripción

Push_swap es un proyecto de la escuela 42 que desafía a los estudiantes a crear un algoritmo eficiente que ordene una pila de números enteros utilizando un conjunto limitado de operaciones entre dos pilas (A y B). El objetivo es producir una pila ordenada con el mínimo número de operaciones posible.

---

## 🎯 Objetivos del Proyecto

- Ordenar una lista aleatoria de números enteros utilizando solo las operaciones prescritas
- Desarrollar un algoritmo que utilice el mínimo número de movimientos posible
- Manejar casos extremos y gestión de errores adecuadamente
- Implementar una gestión eficiente de la memoria

---

## ⚙️ Operaciones

El programa solo puede manipular las pilas utilizando las siguientes operaciones:

| Operación | Descripción |
|-----------|-------------|
| `sa` | Intercambia los dos primeros elementos de la pila A |
| `sb` | Intercambia los dos primeros elementos de la pila B |
| `ss` | Ejecuta `sa` y `sb` simultáneamente |
| `pa` | Empuja el primer elemento de la pila B a la pila A |
| `pb` | Empuja el primer elemento de la pila A a la pila B |
| `ra` | Rota la pila A (el primer elemento se convierte en el último) |
| `rb` | Rota la pila B (el primer elemento se convierte en el último) |
| `rr` | Ejecuta `ra` y `rb` simultáneamente |
| `rra` | Rota inversamente la pila A (el último elemento se convierte en el primero) |
| `rrb` | Rota inversamente la pila B (el último elemento se convierte en el primero) |
| `rrr` | Ejecuta `rra` y `rrb` simultáneamente |

---

## 🧠 Implementación del Algoritmo

Mi implementación de Push_swap utiliza un algoritmo basado en costes para ordenar eficientemente la pila:

### Optimización para Pilas Pequeñas
- Para 2 elementos: Simple intercambio si es necesario
- Para 3 elementos: Ordenación optimizada con máximo 2 operaciones
- Para 5 elementos: Mover los elementos más pequeños a la pila B, ordenar la pila A, luego devolverlos

### Algoritmo de Costes (Para pilas más grandes)
1. **Preparación**: Empujar todos los elementos excepto 3 a la pila B, luego ordenar los 3 elementos restantes en la pila A
2. **Cálculo de Costes**: Para cada elemento en la pila B, calcular:
   - Coste para rotar el elemento a la parte superior de la pila B
   - Coste para rotar la pila A a la posición correcta para la inserción
   - Coste total combinando estas operaciones eficientemente
3. **Ejecución de Movimientos**: Encontrar el elemento con el coste total más bajo y ejecutar los movimientos para empujarlo a la pila A
4. **Rotación Final**: Después de que todos los elementos estén en la pila A, rotar para posicionar el elemento más pequeño en la parte superior

### Optimizaciones Clave
- Rotaciones combinadas (`rr`/`rrr`) cuando es posible para reducir operaciones
- Búsqueda efectiva de la posición objetivo para minimizar rotaciones
- Cálculo inteligente de la dirección de rotación (horaria o antihoraria)

---

## 🔧 Uso

### Compilación
```bash
make
```

### Ejecución del Programa
```bash
./push_swap [números]
```

Ejemplo:
```bash
./push_swap 42 1 7 33 8 -5
```

### Formatos de Entrada
El programa acepta:
- Enteros individuales como argumentos separados
- Enteros dentro del rango de INT_MIN a INT_MAX
- No se permiten valores duplicados

### Salida
El programa muestra la secuencia de operaciones para ordenar la pila, una operación por línea.

---

## 📊 Rendimiento

| Tamaño de Pila | Operaciones Promedio |
|----------------|----------------------|
| 3              | ≤ 2                  |
| 5              | ≤ 12                 |
| 100            | < 700                |
| 500            | < 5500               |

---

## 📁 Estructura del Proyecto

```
Push_swap-42/
├── Makefile
├── README.md
├── libft/            # Biblioteca C personalizada
└── src/
    ├── algorithm/
    │   ├── cost_algorithm.c       # Algoritmo principal de ordenación
    │   ├── cost_calculation.c     # Funciones de cálculo de costes
    │   ├── cost_execution.c       # Ejecución de operaciones basadas en costes
    │   ├── special_cases.c        # Algoritmos optimizados para pilas pequeñas
    │   └── utils_math.c           # Funciones de utilidad matemática
    ├── operations/
    │   ├── push.c                 # Operaciones pa, pb
    │   ├── reverse_rotate.c       # Operaciones rra, rrb, rrr
    │   ├── rotate.c               # Operaciones ra, rb, rr
    │   └── swap.c                 # Operaciones sa, sb, ss
    ├── main.c                     # Punto de entrada del programa
    ├── parsing.c                  # Validación y análisis de entrada
    ├── push_swap.h                # Archivo de cabecera principal
    ├── utils.c                    # Funciones de utilidad general
    └── utils_verify.c             # Funciones de verificación de pila
```

---

## 🛠️ Manejo de Errores

El programa implementa un manejo robusto de errores:
- Valida que todos los argumentos de entrada sean enteros válidos
- Comprueba valores duplicados
- Asegura que los enteros estén dentro del rango de INT_MIN a INT_MAX
- Maneja los fallos de asignación de memoria con elegancia

---

## 🧪 Ejemplo de Salida

Para la entrada `./push_swap 3 1 2`:
```
pb
sa
pa
```

---

## 📚 Aprendizajes Obtenidos

A través de este proyecto, he ganado experiencia en:
- Diseño y optimización de algoritmos avanzados
- Estructuras de datos (particularmente pilas)
- Gestión eficiente de memoria en C
- Resolución de problemas con restricciones
- Técnicas de optimización de rendimiento

---

## 👨‍💻 Autor

- [miguelfdez03](https://github.com/miguelfdez03)

---


- LinkedIn: https://www.linkedin.com/in/miguelfdezmunoz

---

Nota: Este repositorio se sube con el propósito de compartir mi progreso y ofrecer un recurso orientativo para aquellos que necesiten ayuda en su aprendizaje. Espero que se utilice como base de estudio y no solo para copiar y pegar soluciones.

<p align="center">🚀 Never stop learning!</p>
