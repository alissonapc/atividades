#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

float resultado, N1, N2;

void entrada();
void saida(string operacao);
void pausa();
void adicao();
void subtracao();
void multiplicacao();
void divisao();

int main() {

	int opcao = 0;

	while(opcao != 5){

		cout << setprecision(2);
		cout << setiosflags(ios::right);
		cout << setiosflags(ios::fixed);

		cout << "\n";
		cout << "----------------------" << endl;
		cout << " programa calculadora " << endl;
		cout << "    Menu Principal    " << endl;
		cout << "\n";

		cout << "[1] - Adicao" << endl;
		cout << "[2] - subtracao" << endl;
		cout << "[3] - Multiplicacaoo" << endl;
		cout << "[4] - Divisao" << endl;
		cout << "[5] - Encerrar o Programa" << endl;
		cout << "\n";

		cout << "=> Escolha um opcao: ";
		cin >> opcao;

		if (opcao != 5) {

			switch(opcao) {
			case 1:
				adicao();
				break;

			switch(opcao)
			case 2:

				subtracao();
				break;
			switch(opcao)
			case 3:

				multiplicacao();
				break;
			switch(opcao)

			case 4:
				divisao();
				break;

			}

		}
		else {
			cout << "\nPrograma encerrado com sucesso!\n\n";
			cout << endl;
		}
	}





return 0;
}

