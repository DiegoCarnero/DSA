## AVL
Soluciona el problema del orden de inserción del BST. 
Ejs:
- insertar en un BST valores como `[30, 20, 15, 10, 5, 1]` con un criterio como `new_key < node_key` resulta en un arbol sin rama drcha.
- insertar en un BST valores como `[30, 10, 20]` con un criterio como `new_key < node_key` resulta en un arbol como el primer paso de [LR rotation](####LR-rotation)
#### Operations
Cada nodo debe tener 0 o 2 hojas.
#### Nomenclatura
Número es la altura del desbalanceo. Positivo si le falta la hoja derecha, negativo si falta la izquierda. Ver [LR rotation](####LR-rotation) y [RL rotation](####RL-rotation).

Balanced Factor(X) = height(left Subtree (X)) – height(right Subtree(X))
```
5 (-2)                 5 (2)
 \                    /
  6 (-1)             4 (1)
   \                /
    9 (0)          3 (0)
```
- #### LL rotation:

    Mover los nodos una posición a la izq. El nodo del medio se convierte en el nuevo padre, y el padre previo en la hoja izq.
```
5 (-2)                6 (0)
 \                  /       \
  6 (-1)   ->      5 (0)    9 (0)
   \
    9 (0)
``` 
- #### RR rotation

    Mover los nodos una posición a la drch. El nodo del medio se convierte en el nuevo padre, y el padre previo en la hoja izq.
```
    5 (2)              4 (0)
   /                 /       \
  4 (1)    ->      3 (0)      5 (0)
 /
3 (0)
``` 
- #### LR rotation:


```
    6 (2)            6 (2)              5 (0)
   /        LL      /        RR       /       \                          
  4 (-1)    ->     5 (-1)    ->     4 (0)      6 (0)
    \             /             
    5 (0)        4 (0)
``` 
- #### RL rotation:

```
    4 (-2)           4 (-2)                 5 (0)
     \         RR     \          LL       /       \                          
      6 (1)    ->      5 (-1)    ->     4 (0)      6 (0)
     /                  \          
    5 (0)                6 (0)
``` 
