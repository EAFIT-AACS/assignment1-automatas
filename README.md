[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/Uzapeobl)

*Project* -> Minimization Algorithm

*Members* -> Sebastian Salazar Henao and Emmanuel Felipe Cortes Rincón

*Class number* -> Lenguajes Formales / Classroom Monday C2561 - SI2002-1 (7308)

*Specs* -> We are using Windows 11, working with C++ version 17

*Instructions* -> Download the text archive "dfas" and put it into "Minimization Algorithm" file. Please don't change the info of the txt, or if you want to put in it others DFA's, please follow the same structure.

*Explanation* -> Nuestro código está desarrollado en C++, y básicamente implementa la carga y análisis de Autómatas Finitos Deterministas (DFA) a partir de un archivo de texto. El objetivo principal es identificar estados equivalentes dentro de cada autómata, lo que permite minimizar el DFA. 

Para poder llevar esto a cabo nuestro código se divide en diferentes partes, cada una de ellas siendo fundamental para el desarrollo correcto del algoritmo. En una primera instancia, importamos algunas librerias necesarias, las cuales nos permiten usar ciertas funciones y hacer ciertas instancias que nos van a ayudar con ciertos procesos que ejecutamos en el código, como vectores, mapas y conjuntos. Así pues, las librerias que usamos fueron las siguientes:

// Libraries
#include <iostream> // Para entrada y salida de datos (cout, cin)
#include <fstream> // Para trabajar con archivos
#include <string> // Para trabajar con cadenas de texto
#include <sstream> // Para convertir strings en flujos de datos
#include <vector> // Para manejar listas dinámicas
#include <algorithm> // Para usar funciones como "find"
#include <map> // Para almacenar pares clave-valor
#include <set> // Para manejar conjuntos (listas sin repetidos)

Luego, definimos una estructura llamada Automata, la cual representa un DFA. Esta estructura contiene cuatro componentes principales: number_states (que es el número total de estados que tiene el autómata), alphabet (el cual es un vector que contiene los símbolos del alfabeto del autómata), finals (un vector con los estados finales del autómata) y functions (que es una matriz de transiciones, donde cada fila representa un estado y cada columna representa el estado al que se llega con un símbolo del alfabeto).

Despues, declaramos un vector global "automatasArray", el cual almacena múltiples autómatas cargados desde el archivo txt. Además, definimos varias funciones: loadDfas() para poder leer los DFA desde el archivo txt, showDfasArray() para imprimir la información de los autómatas (este lo hicimos con el fin de comprobar si los automatas se estaban cargando correctamente, no lo mostramos en el output porque la actividad pide explicitamente mostrar solo los estados equivalentes, sin embargo, si se desea hacer uso de esta funcion, se puede hacer sin ningún tipo de problema, simplemente debes de llamarla en el main y pasarle como argumento el vector con los automatas), separateStates() para identificar los estados finales y no finales (esta función, al igual que la anterior, la creamos con el fin de comprobar como quedarian separados los estados de cada automata dependiendo de si es un estado final o uno No-final, de igual forma, no lo implementamos en el output porque no es lo que se está pidiendo, pero si se desea, se puede usar), y checkStateEquivalence() para encontrar los pares de estados equivalentes en un Automata Finito Determinista (DFA).

En la función principal main(), el programa abre el archivo llamado "dfas.txt", el cual contiene la información de varios DFA. Este archivo sigue una estructura en particular (tener en cuenta la estructura, ya que si no se seigue dicha estructura el programa no leera bien los automatas), en la primer linea se encuentra la cantidad de casos que se van a analizar, luego en la siguiente linea empieza el primer automata, y esta linea hace referencia a la cantidad de estados que tiene el automata, el siguiente renglón es el alfabeto, la siguiente linea indica los estados finales del DFA, y el resto de lineas indican las transiciones del automata (no hace falta especificar el estado, ya que al subirse al arreglo que propusimos en el código, la posicion en el vector indica el estado), y luego de esto estan plasmados los demás autómatas, que siguen la misma estructura. Si el archivo no puede abrirse, muestra un mensaje de error y finaliza la ejecución. Luego, se lee el número de autómatas y se llama a loadDfas() para almacenarlos en automatasArray. Finalmente en el main, para cada autómata cargado en el arreglo dinámico, se ejecuta checkStateEquivalence() con el fin de identificar sus estados equivalentes.

-------------- *Explicación de los Métodos* --------------

[1]. La función loadDfas() lee cada DFA del archivo txt en un formato específico. Primero, obtiene el número de estados. Luego, lee el alfabeto como una lista de cadenas. A continuación, captura los estados finales y, finalmente, construye la tabla de transiciones del autómata en una matriz de enteros. Una vez que toda la información es extraída del archivo txt, lo que se hace es que se crea una estructura Automata y se almacena en automatasArray.

[2]. La función showDfasArray() muestra en consola la información de cada autómata cargado. Imprime el número de estados, el alfabeto, los estados finales y la tabla de transiciones, iterando sobre cada fila y columna de la matriz de transiciones.

[3]. La función separateStates() lo que hace es clasificar los estados en finales y no finales de un automata. En primer lugar, llena un vector con todos los estados del DFA. Luego, revisa cuáles de esos estados no están en la lista de estados finales para luego separarlos en una nueva vector de estados no finales.

[4]. Finalmente, la función checkStateEquivalence() es la que lleva el proceso de minimización de estados. Inicialmente, clasifica los estados en dos grupos: finales y no finales. Luego, el siguiente paso es aplicar un procedimiento iterativo donde se compara la tabla de transiciones de cada estado para así poder detectar patrones similares. Se utilizan mapas para agrupar estados con el mismo comportamiento y se generan pares de estados equivalentes. Si dos estados siempre llevan a las mismas clases de equivalencia, se consideran indistinguibles y se agrupan.

Al final, el programa muestra en consola (output) los pares de estados equivalentes que se han detectado de cada Automata Finito Determinista DFA.

-------------- *Lógica de la Función checkStateEquivalence()* --------------

Este es el núcleo del programa y su lógica es la lógica es la siguiente:

[a]. *Partición inicial*: Inicialmente, clasifica los estados en finales (marcados con clase 1) y no finales (marcados con clase 2).

[b]. *Refinamiento iterativo*: En cada iteración, refina las clases existentes según el comportamiento de los estados. Dos estados están en la misma clase solo si: Actualmente están en la misma clase, para cada símbolo del alfabeto, las transiciones desde estos estados conducen a estados que están en la misma clase

[c]. *Proceso de refinamiento*: Para cada estado, crea una "firma" o "clave" que consiste en su clase actual más las clases de los estados a los que transita. Así pues, estados con la misma firma se colocan en la misma nueva clase. Este proceso continúa hasta que no haya más cambios en las clases.

[d]. *Identificación de pares equivalentes*: Una vez que el proceso de refinamiento se completa, los estados en la misma clase son equivalentes.

[e]. *Final*: El programa crea pares de estados equivalentes de cada clase que tenga más de un estado. Como resultado el programa imprime los pares de estados equivalentes encontrados para cada DFA. Los pares tienen la forma (estado1, estado2) indicando que estos estados son equivalentes.