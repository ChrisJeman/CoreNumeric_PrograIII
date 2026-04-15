# CoreNumeric - Tarea 2 de Programacion III

## Equipo
Axel Ylachoque - 
Itta Saavedra

## Descripción

Se impleemnto en el proyecto una librería numérica genérica utilizando:

- Templates
- Concepts
- Variadic templates
- Fold expressions
- Restricciones en tiempo de compilación

COn ello se buscaba diseñar una API moderna, segura y expresiva similar a la STL.

---

## Concepts implementados

### Iterable
El Iterable permite iterar sobre un contenedor usando `begin()` y `end()`.

### Addable
Restringe tipos que soportan la operación suma.

### Divisible
En este caso restringe tipos que pueden dividirse por un `size_t`.

### Comparable (Concept propio)
Permite comparar elementos usando el operador `>`.

---

## Funciones implementadas

- `sum`
- `mean`
- `variance`
- `max`
- `transform_reduce`

---

## Variadic Templates

- `sum_variadic`
- `mean_variadic`
- `variance_variadic`
- `max_variadic`

---

## Ejemplo de uso


include < iostream >
include < vector >
include "core_numeric.h"

using namespace std;

int main() {

    vector<double> v{1.0,2.0,3.0};

    cout << core_numeric::sum(v) << endl;
    cout << core_numeric::mean(v) << endl;
    cout << core_numeric::variance(v) << endl;
    cout << core_numeric::max(v) << endl;

    auto r = core_numeric::transform_reduce(v, [](double x){
        return x * x;
    });

    cout << r << endl;

    cout << core_numeric::sum_variadic(1,2,3,4) << endl;
    cout << core_numeric::mean_variadic(1.0,2.0,3.0,4.0) << endl;
    cout << core_numeric::variance_variadic(1.0,2.0,3.0,4.0) << endl;
    cout << core_numeric::max_variadic(1.0,2.7,3.0,4.0) << endl;

    return 0;
}

## Ejemplo de salida esperada
6
2
0.666667
3
14
10
2.5
1.25
4
