#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
    cout << "New problem name: ";
    string new_problem;
    getline(cin, new_problem);

    ifstream input("template.cpp");
    ofstream output(new_problem + ".cpp");

    string line;
    while (getline(input, line)) {
        output << line << '\n';
    }

    input.close();
    output.close();

    cout << "Created " << new_problem << ".cpp successfully.\n";
    string command = "code \"" + new_problem + ".cpp\"";
    system(command.c_str());
    return 0;
}