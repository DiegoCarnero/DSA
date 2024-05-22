### B+ trees
La información está almacenada en los **nodos hoja**, todas al mismo nivel. Estos están ligados a **nodos internos**. Si una clave es menor que los índices en los nodos internos, está en la lista apuntada por el puntero de su izquierda, y el de su derecha si es mayor:
```
[ p1 | k1 | p2 | k2 | p3 ]
```
Si kX es menor que k1, estará en el conjunto al que apunta p1.

M = máximo nº de hijos
ceil(M/2) = mínimo nº de hijos
L = máximo nº de elementos en cada hoja.
ceil(L/2) = mínimo nº de elementos en cada hoja.

Nodos en un mismo nodo interno son "hermanos". El nodo más a la derecha de una rama es "primo" del nodo más a la izquierda de la siguiente. A efectos prácticos nodos primos y hermanos son lo mismo.

El nodo raiz tiene al menos dos punteros, y los nodos internos tiene al menos m/2 y maximo m.

Los elementos en los nodos hijos están ordenados.

Las claves k1, k2, ... kn en un nodo interno son los valores más bajos de los nodos que contienen, empezando por el segundo nodo hoja:
```
    [ | 15 | | 18 | ]
    /       \       \
    10      15      18
    11      16      19
            17
```

- [CS3 Data Structures & Algorithms](https://opendsa-server.cs.vt.edu/OpenDSA/Books/CS3/html/BTree.html)
- [Douglas Fish - B+ tree Basics](https://www.youtube.com/playlist?list=PLsEFMZUL5KsOqKHhxquVleVkM9LFLFSo0)