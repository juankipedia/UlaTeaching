# Asignación N°3 - Programación 3 B-2018

### Preparadores
Julio Lugo
Juan Diego Morón


## Introducción

Esta tarea cuenta para tu calificación definitiva del laboratorio. En ella estudiarás los conceptos básicos de los árboles generales y una Introducción a la Teoría de Juegos mediante procesos de decisión modelados usando estructuras de datos. En la clase anterior estudiaste los recorridos prefijo y sufijo, para esta tarea ahora debes investigar el recorrido por niveles.

## Contenido

El día de hoy, WolfTube, emprendimiento de gran éxito en el Silicon Valley, tiene un pequeño problema. Quieren desarrollar una red neuronal pero ninguno de ellos sabe algo de Machine Learning, de manera que están buscando la manera de imitarlo. Uno de sus ingenieros propuso usar un árbol de decisión que permitiese modelar la red neuronal. Para no quedar mal con sus colegas, decidió explicar la implementación: Sean *{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22}* la lista de valores que hacen vida en el árbol. Para entender la topología del árbol, vamos a asumir lo siguiente: El **primer elemento de la entrada siempre será la raíz del árbol**. Luego, **cada nodo del árbol, a excepción del último, debe tener estrictamente cuatro hijos**. Luego de introducir los cuatro hijos correspondientes a un nodo, los siguientes hijos serán hijos del hermano siguiente, y en caso de no haber más hermanos a quien asignar hijos, entonces serán hijos de los hijos del primer hermano. A efectos prácticos, sigue la topología de un **árbol equilibrado**. En ese sentido, para nuestro ejemplo, tendríamos que 1 es la **raíz**, *2, 3, 4, 5* son los **hijos de la raíz**, *6, 7, 8 y 9* serían **hijos de 2**; *10, 11, 12 y 13* **hijos de 3**; *14, 15, 16, 17* **hijos de 4**; *18, 19, 20 y 21* **hijos de 5**, y finalmente *22* se convertiría en **hijo de 6**.

Cada camino entre nodos del árbol debe ser modelado y constituido por un par: *(par de valores relacionados, probabilidad de pasar por dicho camino)*.
Estos caminos **deben representarlos con una estructura aparte** (se recomienda usar un [mapa](http://www.cplusplus.com/reference/map/map/) ). Luego de construido el árbol, se deberá procesar una entrada de datos para definir las probabilidades finales de los caminos. Por cada nodo recibido en la entrada, deberán **realizar una búsqueda de dicho nodo en el árbol realizando un recorrido prefijo**, y en cada llamado recursivo, **actualizar los valores de probabilidad** de los caminos. Finalmente, deberás imprimir los caminos de ese árbol, junto a su probabilidad.

## Entrada

Recibirás inicialmente el valor de N (1 < N <= 10^9),  seguido de una lista de N  enteros P (1<= P <= 10 ^ 6) sin repetición siguiendo el orden de inserción indicado arriba.
Posteriormente, se dará una lista de N*N entradas. Cada uno de los elementos  de esta lista representa una **búsqueda** ( puede aceptar repetidos) sobre el árbol haciendo uso del recorrido prefijo, que modificarán las probabilidades de sus caminos.

```
6
1 6 8 9 4 15
6 6 6 6 6 6
6 6 6 6 6 6
6 6 6 6 6 6
6 6 6 6 6 6
6 6 6 6 6 6
1 1 1 9 4 15
```


## Salida

El valor de probabilidad final de cada camino definido. El orden de impresión debe seguir un estricto recorrido por niveles, con el siguiente formato: (*padre, hijo, probabilidad*). La probabilidad debe imprimirse con máximo dos decimales.

```
(1 6) 0.92
(1 8) 0.06
(1 9) 0.06
(1 4) 0.03
(6 15) 0.08
```

## Pista

Debes considerar **cada camino recorrido en tu búsqueda**. Por ejemplo, para buscar el 4, debes recorrer todos los caminos en el árbol, puesto que es un recorrido en prefijo. Otro dato a considerar es el número de veces que se "ve" un nodo. En ese sentido, la formula del cálculo de la probabilidad se resume en: *m/n*, donde **m** es el número de veces que se pasa por un camino en particular en todos los recorridos de las búsquedas, y **n** el número total de entradas procesadas.


## Envío

Deben enviar el código al siguiente correo: juandiegp17@gmail.com con el asunto **[PR3-TAREA3]**.
