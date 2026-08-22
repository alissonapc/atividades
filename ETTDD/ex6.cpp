#include <iostream>
#include <deque>
#include <string>
#include <limits>
using namespace std;

int main() {
    deque<string> prioritarios;
    deque<string> comuns;

    int opcao;
    do {
        cout << " MENU DE ATENDIMENTO"<<endl;
        cout << "1 - Atendimento PRIORITARIO"<<endl;
        cout << "2 - Atendimento COMUM"<<endl;
        cout << "3 - Chamar proximo"<<endl;
        cout << "4 - Listar fila"<<endl;
        cout << "0 - Sair"<<endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcao) {
            case 1: {
                cout << "Nome do atendimento prioritario: ";
                string nome;
                getline(cin, nome);
                prioritarios.push_back(nome);
                cout << nome << " adicionado a fila PRIORITARIA.\n";
                break;
            }
            case 2: {
                cout << "Nome do atendimento comum: ";
                string nome;
                getline(cin, nome);
                comuns.push_back(nome);
                cout << nome << " adicionado a fila COMUM.\n";
                break;
            }
            case 3: {
                if (!prioritarios.empty()) {
                    cout << "Atendendo (PRIORITARIO): " << prioritarios.front() << endl;
                    prioritarios.pop_front();
                } else if (!comuns.empty()) {
                    cout << "Atendendo (COMUM): " << comuns.front() << endl;
                    comuns.pop_front();
                } else {
                    cout << "Nenhum atendimento na fila.\n";
                }
                break;
            }
            case 4: {
                cout << "\n-- Fila PRIORITARIA --\n";
                if (prioritarios.empty()) cout << "(vazia)\n";
                for (auto& n : prioritarios) cout << "- " << n << endl;

                cout << "\n-- Fila COMUM --\n";
                if (comuns.empty()) cout << "(vazia)\n";
                for (auto& n : comuns) cout << "- " << n << endl;
                break;
            }
            case 0:
                cout << "Encerrando o sistema de atendimento.\n";
                break;
            default:
                cout << "Opcao invalida!\n";
        }

    } while (opcao != 0);

    return 0;
}
