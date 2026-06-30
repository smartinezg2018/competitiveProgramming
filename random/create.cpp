#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
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
    
    string command = "code \"" + new_problem + ".cpp\"";
    system(command.c_str());
    return 0;
}