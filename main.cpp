// Libraries
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// Structure
struct Automata {

    int states;
    vector<char> alphabet;
    vector<int> finals;
    vector<vector <int>> functions;

};


int main()
{

    cout << "Version de C++: " << __cplusplus << endl;

    /*
    // Number of cases
    int numberOfCases;

    ifstream file("dfa_cases.txt"); // Abre el archivo
    
    if (file.fail())
    {
        cout << "Error al abrir el archivo..." << endl;
        return;
    }
    
    

    // Automata´s Array
    Automata array[numberOfCases];
*/
    return 0;
}

