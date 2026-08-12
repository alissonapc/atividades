#include <iostream>
#include <iomanip>
#include <cmath> // Apenas para sqrt() e pow()

using namespace std;

// Variáveis globais (assim como no seu exemplo)
float dados[100]; // Vetor fixo para até 100 elementos
int quantidade = 0;
float resMedia, resMediana, resVariancia, resDesvioPadrao;

// Declaração das funções e procedimentos
void entrada();
void saida(string operacao, float resultado);
void calcularMedia();
void calcularMediana();
void calcularVariancia();
void calcularDesvioPadrao();

int main() {
    int opcao = 0;

    while (opcao != 5) {
        cout << setprecision(2);
        cout << setiosflags(ios::right);
        cout << setiosflags(ios::fixed);

        cout << "\n";
        cout << "----------------------" << endl;
        cout << " programa estatistico " << endl;
        cout << "    Menu Principal    " << endl;
        cout << "----------------------" << endl;

        cout << "[1] - Media" << endl;
        cout << "[2] - Mediana" << endl;
        cout << "[3] - Variancia" << endl;
        cout << "[4] - Desvio Padrao" << endl;
        cout << "[5] - Encerrar o Programa" << endl;
        cout << "\n";

        cout << "=> Escolha uma opcao: ";
        cin >> opcao;

        if (opcao != 5) {
            
            entrada(); // Pede os dados ao usuário

            switch (opcao) {
                case 1:
                    calcularMedia();
                    saida("Media", resMedia);
                    break;

                case 2:
                    calcularMediana();
                    saida("Mediana", resMediana);
                    break;

                case 3:
                    calcularVariancia();
                    saida("Variancia", resVariancia);
                    break;

                case 4:
                    calcularVariancia(); // Necessário para o desvio padrão
                    calcularDesvioPadrao();
                    saida("Desvio Padrao", resDesvioPadrao);
                    break;

                default:
                    cout << "\nOpcao invalida!\n";
                    break;
            }

        } else {
            cout << "\nPrograma encerrado com sucesso!\n\n";
        }
    }

    return 0;
}

// Procedimento para entrada dos dados
void entrada() {
    cout << "\nQuantos numeros deseja digitar (maximo 100)? ";
    cin >> quantidade;

    while (quantidade < 2 || quantidade > 100) {
        cout << "Digite um valor entre 2 e 100: ";
        cin >> quantidade;
    }

    cout << "Digite os " << quantidade << " numeros:\n";
    for (int i = 0; i < quantidade; i++) {
        cout << "Numero " << (i + 1) << ": ";
        cin >> dados[i];
    }
}

// Procedimento para exibir o resultado
void saida(string operacao, float resultado) {
    cout << "\n----------------------" << endl;
    cout << "Resultado da " << operacao << ": " << resultado << endl;
    cout << "----------------------" << endl;
}

// Cálculo da Média
void calcularMedia() {
    float soma = 0;
    for (int i = 0; i < quantidade; i++) {
        soma += dados[i];
    }
    resMedia = soma / quantidade;
}

// Cálculo da Mediana (com ordenação Bubble Sort manual)
void calcularMediana() {
    // Cria uma cópia do vetor para ordená-lo sem alterar o original
    float temp[100];
    for (int i = 0; i < quantidade; i++) {
        temp[i] = dados[i];
    }

    // Algoritmo simples de ordenação (Bubble Sort)
    for (int i = 0; i < quantidade - 1; i++) {
        for (int j = 0; j < quantidade - i - 1; j++) {
            if (temp[j] > temp[j + 1]) {
                float aux = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = aux;
            }
        }
    }

    // Encontra a mediana no vetor ordenado
    if (quantidade % 2 != 0) {
        resMediana = temp[quantidade / 2];
    } else {
        resMediana = (temp[(quantidade / 2) - 1] + temp[quantidade / 2]) / 2.0;
    }
}

// Cálculo da Variância Amostral
void calcularVariancia() {
    calcularMedia(); // Garante que temos a média atualizada

    float somaQuadrados = 0;
    for (int i = 0; i < quantidade; i++) {
        somaQuadrados += pow(dados[i] - resMedia, 2);
    }
    resVariancia = somaQuadrados / (quantidade - 1);
}

// Cálculo do Desvio Padrão
void calcularDesvioPadrao() {
    resDesvioPadrao = sqrt(resVariancia);
}
