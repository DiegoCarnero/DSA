Bottom-up Dynamic programming: los valores de entrada van disminuyendo progresivamente.

## Cuantas soluciones monedas
Cómo garantizar que no hay duplicados? Elegir solamente monedas superiores a la actual. 
Con las monedas ordenadas en la lista, solamente podemos incrementar el índice de la moneda que estamos usando.

   O
 / | \\
1  2  5

Combinaciones posibles. Empezando en 5x1

| |5|4|3|2|1|0|
|-|-|-|-|-|-|-|
1|4|3|2|2|1|1
2|1|1|0|1|0|1
5|1|0|0|0|0|1

Cuantas formas de sumar 1 con moneds de 5? 1 - 5 = -4. Menos cuatro está fuera de la tabla así que hay 0 maneras.
Necesitamos toda la tabla en memoria si recorremos las celdas de izq a derecha.<br>
Recorreindo las celdas  ab-drch a arr-izq, solamente necesitamos dos filas en memoria, consiguiendo O(n) ya que nunca miramos más abajo que la fila siguiente.

Ej:
<br>moneda:2 cantidad:2
<br>Desplazamos dos celdas a la drch. hay un 1. Celda de abajo, hay un cero = Hay una solución
<br>
<br>moneda:1 cantidad:4
<br>Desplazamos una celda a la drch. hay un 2. Celda de abajo, hay un 1 = Hay 3 soluciones

## Interleaving strings
Si ambos strings contienen una letra válida, cómo decidimos cual coger? **Backtracking**.
<br>
Solo hay que hacer un seguimiento de qué índice de los strings originales usamos. Cuando toque hacer una decisión hay que ver si podemos completar el resto del string con lo que nos queda (True o False, un True es suficiente).

s1 = aabcc
s2 = dbbca
s3 = aadbbcbcac

Condición: podemos crear el final del string con los últimos caracteres de los strings de entrada? T=True, F=False
|||0|1|2|3|4||
|-|-|-|-|-|-|-|-|
| | |d|b|b|c|a||
1|a||||||
2|a||||||
3|b||||||
4|c||||||
5|c||||||
||||||F|F|T|

Los valores fuera de la tabla indica que hemos quedado sin caracteres en alguno de lo strings.