
#include <iostream>
#include <cstring>
#include "cpf_validator.h"

using namespace std;

void replicateOut(char);
void replicateOut(char, char);
void replicateOut(char, char, bool);

int main() {

    char number[11];

    CpfValidator cpf;

    while (true) {

        cout << endl << endl;
        replicateOut(41, '-');
        cout << "Enter the CPF digits     [type X to exit]" << endl;
        replicateOut(41, '-');
        cout << "?: ";
        cin >> number;

        if (toupper(number[0]) == 'X') {
            cout << endl << endl << "--- BYE" << endl << endl;
            break;
        }

        replicateOut(6);
        cout << "--->> CPF " << (cpf.isValid(number) ? "is valid!" : "  I S   I N V A L I D !!!") << endl;
    }

}

void replicateOut(char n) {
    replicateOut(n, ' ');
}

void replicateOut(char n, char c) {
    replicateOut(n, c, true);
}

void replicateOut(char n, char c, bool jump_line) {
    for (char i = 0; i < n; i++) cout << c;
    if (jump_line) cout << endl;
}
