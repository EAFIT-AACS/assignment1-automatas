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

    ifstream file("dfas.txt"); // Abre el archivo
    
    if (file.fail())
    {
        cout << "Error al abrir el archivo..." << endl;
        return 1;
    }
    
    // Number of cases
    int num_cases;
    file >> num_cases; // Leer número de casos
    file.ignore(); // Ignorar salto de línea

    cout << "Number of cases: " << num_cases << endl;

    // Automata´s Array
    Automata array[num_cases];

    return 0;
}