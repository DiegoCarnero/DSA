### Definición
Estructuras de datos se usan para procesan, recuperar y almacenar datos, no solo organizarlos.
### Clasificación
- Lineal: elementos organizados lineal o secuencialmente, y cada elemento está ligado a los abyacentes. Pueden ser:
    - Estáticas: tamaño de memoria fijo (Arrays).
    - Dinámicas: no tienen tamaño fijo, y pueden ser actualizadas (Queue, stack, linked list)
- No lineal: los elementos no están organizados de forma secuencial. No podemos recorrer todos los elementos de una sola pasada (Graphs, Trees)
### Definiciones
- Estructuras lineales: secuenciales, preservan el orden, Tamaño fijo o dinámico. Muy eficientes de acceder.
    - Arrays: almacena elementos del mismo tipo de forma contigua en memoria. Se organiza en base a un indice, lo que facilita la búsqueda la recolección de datos. Se puede extender su funcionalidad con arrays multidimensionales. Es la base de estructuras más complejas como stacks, queeue, heaps, hash tables, ...
    - Linked list: estructura lineal en la que los elementos no se almacenan de forma contigua en memoria, enlazados mediante punteros, lo que facilita la inserción y borrado. No requiere saber el tamaño de los elementos previo a inicialización.  El primer nodo se denomina 'Head'. El puntero del último elemento apunta a NULL.
    - Stack: Ordenado last-in-first-out (LIFO). El insertado y recolectado de datos se denomina 'push' y 'pop' respectivamente, y se hacen un elemento cada vez y en un extremo de la pila. Acceder a un elemento sin retirarlo se denomina 'peek'.
    - Queue: lista ordenada first-in-first-out (FIFO).
- Estructuras no lineales:
    - Tree: El elemento al principio se deonima 'roo', y cada nodo se desglosa en una nueva 'layer'. <br>
    Terminología:
        - Edge: enlace entre dos nodos. Para N nodos habrá N-1 'edges'
        - Degree: total de children directos de un nodo.
        - Height: total de 'edges' desde el nodo leaf más profundo relativo a un nodo.
        - Depth: total de 'edges' desde root a un nodo en particular.
        -Path: secuencia de 'edges' entre dos nodos cualquiera. 'Length of path' es el número total de nodos.
        - Parent node: nodo predecesor al nodo actual.
        - Child node: nodo(s) sucesor(es) del nodo actual.
        - Root node: nodo origen del tree.No tiene parents. Un tree no vacio debe tener a) un solo nodo root y b) un camino desde cualquier otro nodo del tree.
        - Leaf/External node: nodos sin children.
        - Ancestor node: cualquier nodo en el camino desde el actual a root.
        - Descendant node: cualquier sucesor en el camino desde un leaf al nodo acutal.
        - Sibling: nodos children de un mismo parent.
        - Layer/Level: cuenta los 'edges' en el camino desde root al nodo actual.
        - Internal node: nodos con al menos un child.
        - Subtree: cualquier nodo y sus descendientes (puede tenercualqueir profundidad).<br>

        Tipos:

        - Binary Tree: cada nodo solo tiene: datos, puntero al child izq, puntero al child drch
        - Binary Search Tree: limitaciones adicionales: nodos a las izq del root tiene keys menos que el key del root, mismo para nodos a las drcha de root, y no hay duplicados.
        - Heap: complete binary tree. Puede ser min heap (los valores de los children aumenta respecto al valor del parent node) y max heap (los valores de los children decrecen respecto al valor del parent node)
        - Hashing DS: mapea una clave con cada nodo apra facilitar el acceso. La eficiencia depende de la funcion usada. 
        - Matrix
        - Trie (de 'retrieval'): usado para almacenar cadenas de texto. Eficiente para pattern matching. Strings con un mismo prefijo vienen de un mismo nodo. Con M siendo la longitud máxima de un string, y N el número de claves en el tree, el time complexity de un BST es M*log(N), mientras que para Tries es O(M).
    - Graph: consiste en vertices/nodos y 'edges', conectado . Se denota como G(V, E). Linked lists, trees y Heaps son tipos de graphs. <br>
    Tipos:
        - Finite: número de edges y vertices limitado.
        - Infinite: número de edges y vertices indeterminado.
        - Trivial: un único vertice.
        - Simple: cada par de nodos tienen un único edge.
        - Multi: varios edges entre un mismo par de nodos.
        - Null: nodos no conectados.
        - Pseudograph: además de 'edges' contiene bucles (edge que sale y termina en el mismo nodo)
        - Regular: Todos los nodos tienen el mismo degree.
        - Weighted: se asigna pesos a cada edge.
        - Directed (digraph): los edges tienen dirección.
        - Undirected
        - Connected: si siempre hay un path entre dos vertices cualquier.
        - Disconnected
        - Cyclic: si tiene al menos un ciclo (puedes volver a donde empezaste).
        - Acyclic: si no hay un ciclo.
        - Directed Acyclic (DAG): edges direccionados pero no hay un ciclo.
        - Subgraph: vertices y edges que es un subset de otro grafo.

    Representación:<br>
```
0 - 1
| /
2 - 3
```

- Adjacency matrix: filas y columnas denotan los vertices, y cada entrada de la matrix representa el peso del edge entre esos vertices.

    ||0|1|2|3
    |-|-|-|-|-|
    **0**|0|1|1|0
    **1**|1|0|1|0
    **2**|1|1|0|1
    **3**|0|0|1|0

- Adjacency list: representado como una linked list, con punteros enlazando vertices conectados.<br>
0 -> 1 -> 2<br>
1 -> 0 -> 2<br>
2 -> 0 -> 1 -> 3<br>
3 -> 2<br>

    Comparación:
    |Acción|Adjacencay Matrix|Adjacency List|
    |-|-|-|
    Añadir edge|O(1)|O(1)
    Eliminar edge|O(1)|O(N)
    Inicialización|O(N*N)|O(N)

### Recursos
- [Optimizing Binary Search](https://youtu.be/1RIPMQQRBW)
- [Perfect Hash Table](https://youtu.be/DMQ_HcNSOAI)
- ["Algorithms", Robert Sedgewick](https://www.youtube.com/playlist?list=PLMhLnbR_fjukCewhwIuT64dwSttMz9Y64)