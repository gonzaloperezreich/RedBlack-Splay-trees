# T2_logaritmos
## splay.cpp

En este archivo se encuentra la implementación del Splay Tree, no es necesario compilarlo.

## RedBlack.cpp

En este archivo se encuentra la implementación del Red Black Tree, no es necesario compilarlo.

## P31_Splay.cpp

En este archivo se genera una permutacion de [1, n] para insertar en un Splay Tree, luego se crea un vector de búsqueda de tamaño 2^28 con elementos de [1, n] con una distribución equiprobable, luego mide el tiempo que se demora en buscar todos los elementos del vector de búsqueda.

Para compilar y ejecutar el programa, ejecute las siguientes lineas de codigo en la consola:
```
g++ P31_Splay.cpp -O3 -o P31_splay // Compilación (solo se necesita hacer 1 vez)
.\P31_splay x // Ejecución
```

Donde n = 2^x.

## P31_RB.cpp

En este archivo se desarrolla un procedimiento análogo a P31_Splay.cpp, con la diferencia de que el proceso se realiza en un Red Black Tree en vez de un Splay Tree. 

Para compilar y ejecutar el programa, ejecute las siguientes lineas de codigo en la consola:
```
g++ P31_RB.cpp -O3 -o P31_RB // Compilación (solo se necesita hacer 1 vez)
.\P31_RB x // Ejecución
```

Donde n = 2^x.

## P32_Splay.cpp

En este archivo se genera una permutacion de [1, n] para insertar en un Splay Tree, luego se crea un vector de busqueda de tamaño 2^28 con elementos de [1, n] con una distribución skewed, usando para esto una función phi que indica la frecuencia de cada elemento, la cual depende de alpha. Luego mide el tiempo que se demora en buscar todos los elementos del vector de búsqueda.

Para compilar y ejecutar el programa, ejecute las siguientes lineas de codigo en la consola:
```
g++ P32_Splay.cpp -O3 -o P32_splay // Compilación (solo se necesita hacer 1 vez)
.\P32_splay x alpha // Ejecución
```

Donde n = 2^x y alpha se usa para obtener la skewness del vector de búsqueda.

## P32_RB.cpp

En este archivo se desarrolla un procedimiento análogo a P32_RB.cpp, con la diferencia de que el proceso se realiza en un Red Black Tree en vez de un Splay Tree. 

Para compilar y ejecutar el programa, ejecute las siguientes lineas de codigo en la consola:
```
g++ P32_RB.cpp -O3 -o P32_RB // Compilación (solo se necesita hacer 1 vez)
.\P32_RB x alpha // Ejecución
```

Donde n = 2^x y alpha se usa para obtener la skewness del vector de búsqueda.
