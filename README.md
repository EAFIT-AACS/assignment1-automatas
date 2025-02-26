[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/Uzapeobl)

Project -> Minimization Algorithm

Members -> Sebastian Salazar Henao and Emmanuel Felipe Cortes Rincón

Class number -> Lenguajes Formales / Classroom Monday C2561 - SI2002-1 (7308)

Specs -> We are using Windows 11, working with C++ version 17

Instructions -> Download the text archive "dfas" and put it into "Minimization Algorithm" file. Please don't change the info of the txt, or if you want to put in it others DFA's, please follow the same structure.

Explanation -> El programa utiliza un algoritmo conocido como "algoritmo de minimización de estados de Hopcroft" o "algoritmo de partición" para identificar estados equivalentes en un DFA. Aquí está la explicación de la lógica implementada:
Para estructurar los datos el programa define una estructura Automata para representar un DFA, que incluye el número de estados, alfabeto, estados finales y tabla de transiciones. Se utiliza un vector estructura para almacenar varios autómatas.
La función loadDfas lee datos de un archivo de texto y carga la información de múltiples DFAs alamacenados en el archivo Dfas.txt.
Cada DFA tiene su número de estados, alfabeto, estados finales y tabla de transiciones.
Algoritmo de encontrar equivalencias (función checkStateEquivalence): Este es el núcleo del programa y utiliza el algoritmo de partición de Hopcroft para encontrar estados equivalentes.
La lógica es la siguiente:
a. Partición inicial: Inicialmente, divide los estados en dos grupos:
Función separateStates: Esta función clasifica los estados en finales (marcados con clase 1) y no finales (marcados con clase 2).
b. Refinamiento iterativo: En cada iteración, refina las clases existentes según el comportamiento de los estados.
Dos estados están en la misma clase solo si:
Actualmente están en la misma clase, para cada símbolo del alfabeto, las transiciones desde estos estados conducen a estados que están en la misma clase
c. Proceso de refinamiento: Para cada estado, crea una "firma" o "clave" que consiste en su clase actual más las clases de los estados a los que transita.
Estados con la misma firma se colocan en la misma nueva clase.
Este proceso continúa hasta que no haya más cambios en las clases.
d. Identificación de pares equivalentes: Una vez que el proceso de refinamiento se completa, los estados en la misma clase son equivalentes.
El programa crea pares de estados equivalentes de cada clase que tenga más de un estado.
Como resultado el programa imprime los pares de estados equivalentes encontrados para cada DFA.
Los pares tienen la forma (estado1, estado2) indicando que estos estados son equivalentes.

