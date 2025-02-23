// Libraries
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure
struct Automata {
    int number_states;
    vector<string> alphabet;
    vector<int> finals;
    vector<vector <int>> functions;
};

// Automata´s Dinamic Array
vector<Automata> automatasArray;

// Functions
void loadDfas(int num_cases, ifstream& file, vector<Automata>& automatasArray);
void showDfasArray(const vector<Automata>& automatas);
void separateStates(Automata dfa);

int main()
{

    // Open the file
    ifstream file("dfas.txt");
    if (file.fail())
    {
        cout << "Error al abrir el archivo..." << endl;
        return 1;
    }

    // Number of cases
    int num_cases;
    file >> num_cases;
    file.ignore();
    cout << "Number of cases: " << num_cases << endl;

    // Load the DFA's from the txt and load them into the Automatas' Array
    loadDfas(num_cases, file, automatasArray);
    
    // Show the DFA's
    showDfasArray(automatasArray);
    
    separateStates(automatasArray[0]);

    file.close();
    
    return 0;
}

void loadDfas(int num_cases, ifstream& file, vector<Automata>& automatasArray){

    for (int i = 0; i < num_cases; i++) {
        int num_states;

        file >> num_states;

        file.ignore(); // Ignore line break

        // Read the alphabet
        string line, symbol;
        getline(file, line);
        stringstream ss(line);
        vector<string> alphabetDFA;
        while (ss >> symbol) alphabetDFA.push_back(symbol);

        // Read final states
        getline(file, line);
        stringstream ss2(line);
        vector<int> final_states;
        int state;
        while (ss2 >> state) final_states.push_back(state);

        // Read Transition Table
        vector<vector<int>> transition_table(num_states, vector<int>(alphabetDFA.size()));
        for (int j = 0; j < num_states; j++) {
            for (int k = 0; k < alphabetDFA.size(); k++) {
                file >> transition_table[j][k];
            }
        }

        Automata dfa;

        dfa.number_states = num_states;
        dfa.alphabet = alphabetDFA;
        dfa.finals = final_states;
        dfa.functions = transition_table;

        automatasArray.push_back(dfa);
    }
}

void showDfasArray(const vector<Automata>& automatasArray){

    for (int i = 0; i < automatasArray.size(); i++)
    {
        cout << "\nDFA " << i + 1 << " - States: " << automatasArray[i].number_states << endl;

        cout << "Alphabet: ";
        for (const string &s : automatasArray[i].alphabet) cout << s << " ";
        cout << endl;

        cout << "Final States: ";
        for (int s : automatasArray[i].finals) cout << s << " ";
        cout << endl;

        cout << "Transitions:" << endl;
        for (int j = 0; j < automatasArray[i].number_states; j++) {
            cout << "Estado " << j << ": ";
            for (int k = 0; k < automatasArray[i].alphabet.size(); k++) {
                cout << automatasArray[i].functions[j][k] << " ";
            }
            cout << endl;
        }
    }
}

void separateStates(Automata dfa) {
    int n = dfa.number_states;

    vector<int> totalStates;
    vector<int> finalStates = dfa.finals;
    vector<int> nonFinalStates;

    // Fill the vector totalStates with all states of the DFA
    for (int i = 0; i < n; i++) {
        totalStates.push_back(i);
    }

    // Classify the states in Finals and Non-Finals
    for (int state : totalStates) {
        if (find(finalStates.begin(), finalStates.end(), state) == finalStates.end()) {
            nonFinalStates.push_back(state);
        }
    }

    // Show Non-Final states
    cout << "Non-Final states: ";
    for (int state : nonFinalStates) {
        cout << state << " ";
    }
    cout << endl;

    // Show Final states
    cout << "Final States: ";
    for (int state : finalStates) {
        cout << state << " ";
    }
    cout << endl;

}

