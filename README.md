*Project* -> Minimization Algorithm

*Members* -> Sebastian Salazar Henao and Emmanuel Felipe Cortes Rincón

*Class number* -> Formal Languages / Classroom Monday C2561 - SI2002-1 (7308)

*Specs* -> We are using Windows 11, working with C++ version 17

*Instructions* -> Download the text file "dfas" and place it in the "Minimization Algorithm" folder. Please do not alter the content of the txt file, or if you wish to add other DFAs, follow the same structure.

*Explanation* -> Our code is developed in C++, and it essentially implements the loading and analysis of Deterministic Finite Automata (DFA) from a text file. The main objective is to identify equivalent states within each automaton, which allows for the minimization of the DFA.

To achieve this, our code is divided into different parts, each of which is fundamental for the correct development of the algorithm. Initially, we import some necessary libraries, which allow us to use certain functions and create instances that will assist us with certain processes executed in the code, such as vectors, maps, and sets. Thus, the libraries we used are as follows:

#include <iostream> -> For data input and output (cout, cin)
#include <fstream> -> For working with files
#include <string> -> For working with text strings
#include <sstream> -> For converting strings into data streams
#include <vector> -> For handling dynamic lists
#include <algorithm> -> For using functions like "find"
#include <map> -> For storing key-value pairs
#include <set> -> For handling sets (lists without duplicates)

Next, we define a structure called Automata, which represents a DFA. This structure contains four main components: number_states (which is the total number of states in the automaton), alphabet (a vector containing the symbols of the automaton's alphabet), finals (a vector with the final states of the automaton), and functions (a transition matrix, where each row represents a state and each column represents the state reached with a symbol from the alphabet).

After that, we declare a global vector "automatasArray", which stores multiple automata loaded from the txt file. Additionally, we define several functions: loadDfas() to read the DFAs from the txt file, showDfasArray() to print the information of the automata (we created this to verify if the automata were being loaded correctly, but we do not show it in the output because the activity explicitly requests to only show the equivalent states; however, if you wish to use this function, you can do so without any issues, simply call it in the main and pass the vector with the automata as an argument), separateStates() to identify the final and non-final states (this function, like the previous one, was created to check how the states of each automaton would be separated depending on whether it is a final or non-final state; similarly, it is not implemented in the output because it is not what is being asked, but it can be used if desired), and checkStateEquivalence() to find pairs of equivalent states in a Deterministic Finite Automaton (DFA).

In the main() function, the program opens a file called "dfas.txt", which contains the information of several DFAs. This file follows a specific structure (note the structure, as if it is not followed, the program will not read the automata correctly). The first line contains the number of cases to be analyzed, then the next line starts with the first automaton, and this line refers to the number of states in the automaton. The following line is the alphabet, the next line indicates the final states of the DFA, and the remaining lines indicate the transitions of the automaton (there is no need to specify the state, as when uploaded to the array we proposed in the code, the position in the vector indicates the state, in other words, it is not necessary to specify the state, as its position in the proposed array represents it). After this, the other automata are listed, following the same structure. If the file cannot be opened, an error message is displayed, and the execution ends. Then, the number of automata is read, and loadDfas() is called to store them in automatasArray. Finally, in the main, for each automaton loaded in the dynamic array, checkStateEquivalence() is executed to identify its equivalent states.

-------------- *Explanation of the Methods* --------------

[1]. The loadDfas() function reads each DFA from the txt file in a specific format. First, it obtains the number of states. Then, it reads the alphabet as a list of strings. Next, it captures the final states and, finally, constructs the transition table of the automaton in a matrix of integers. Once all the information is extracted from the txt file, an Automata structure is created and stored in automatasArray.

[2]. The showDfasArray() function displays the information of each loaded automaton in the console. It prints the number of states, the alphabet, the final states, and the transition table, iterating over each row and column of the transition matrix.

[3]. The separateStates() function classifies the states into final and non-final states of an automaton. First, it fills a vector with all the states of the DFA. Then, it checks which of these states are not in the list of final states to separate them into a new vector of non-final states.

[4]. Finally, the checkStateEquivalence() function carries out the state minimization process. Initially, it classifies the states into two groups: final and non-final. Then, the next step is to apply an iterative procedure where the transition table of each state is compared to detect similar patterns. Maps are used to group states with the same behavior, and pairs of equivalent states are generated. If two states always lead to the same equivalence classes, they are considered indistinguishable and are grouped together.

At the end, the program displays in the console (output) the pairs of equivalent states detected for each Deterministic Finite Automaton DFA.

-------------- *Logic of the checkStateEquivalence() Function* --------------

This is the core of the program, and its logic is as follows:

[a]. *Initial Partition*: Initially, it classifies the states into final (marked with class 1) and non-final (marked with class 2).

[b]. *Iterative Refinement*: In each iteration, it refines the existing classes based on the behavior of the states. Two states are in the same class only if: They are currently in the same class, and for each symbol in the alphabet, the transitions from these states lead to states that are in the same class.

[c]. *Refinement Process*: For each state, it creates a "signature" or "key" consisting of its current class plus the classes of the states it transitions to. Thus, states with the same signature are placed in the same new class. This process continues until there are no more changes in the classes.

[d]. *Identification of Equivalent Pairs*: Once the refinement process is complete, the states in the same class are equivalent.

[e]. *Final*: The program creates pairs of equivalent states from each class that has more than one state. As a result, the program prints the pairs of equivalent states found for each DFA. The pairs are in the form (state1, state2), indicating that these states are equivalent.