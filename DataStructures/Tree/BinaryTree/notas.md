## Segment tree
Estructura genérica. Aplicable a problemas de consultas de rangos.
#### Usos
- Range Sum Query (RSQ)
- Range Minimum Query (RMQ)
- Contar elementos en un rango según cierta propiedad (ej: elementos nulos, negativos, etc)

## Interval tree
Tenemos un par como clave. El inicio del intervalo funciona como la clave en un BST. Cada nodo tiene el valor máximo de la rama.

Tras inserción (igual que BST), ascendemos la rama para actualizar en valor máximo en cada nodo de esta.

Búsqueda: 

### Comparación 
Segment Trees, Interval Trees, Range Trees, Binary Indexed Trees ([link](https://www.baeldung.com/cs/tree-segment-interval-range-binary-indexed))