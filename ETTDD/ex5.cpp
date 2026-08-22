#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool verificar(string expressao) {
    stack<char> pilha;

    for (char c : expressao) {
        if (c == '(') {
            pilha.push(c);
        }
        else if (c == ')') {
            if (pilha.empty()) {
                return false;
            }
            pilha.pop();
        }
    }

    return pilha.empty();
}

int main() {
    string expressao;

    cout << "Digite a expressao: ";
    getline(cin, expressao);

    if (verificar(expressao)) {
        cout << "correto" << endl;
    } else {
        cout << "incorreto" << endl;
    }

    return 0;
}
