#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Variáveis globais para armazenar a entrada e os resultados
vector<float> dados;
float resMedia, resMediana, resVariancia, resDesvioPadrao;

// Declaração dos protótipos das funções
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

        cout << "   PROGRAMA ESTATISTICO DE DADOS   " << endl;
        cout << "          Menu Principal           " << endl;

        cout << "[1] - Calcular Media" << endl;
        cout << "[2] - Calcular Mediana" << endl;
        cout << "[3] - Calcular Variancia" << endl;
        cout << "[4] - Calcular Desvio Padrao" << endl;
        cout << "[5] - Encerrar o Programa" << endl;
        cout << "\n";

        cout << "=> Escolha uma opcao: ";
        cin >> opcao;

        if (opcao != 5) {
            entrada(); // Leitura dos dados antes de executar o cálculo selecionado

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
                    saida("Variancia Amostral", resVariancia);
                    break;

                case 4:
                    calcularVariancia(); // Necessário para o desvio padrão
                    calcularDesvioPadrao();
                    saida("Desvio Padrao", resDesvioPadrao);
                    break;

                default:
                    cout << "\nOpcao invalida! Tente novamente.\n";
                    break;
            }
        }
        else {
            cout << "\nPrograma encerrado com sucesso!\n\n";
        }
    }

    return 0;
}

// Procedimento para obter os dados do usuário
void entrada() {
    int n;
    cout << "\nQuantos numeros deseja inserir? ";
    cin >> n;

    while (n < 2) {
        cout << "Para calculos estatisticos, insira pelo menos 2 numeros: ";
        cin >> n;
    }

    dados.resize(n);
    cout << "Digite os " << n << " numeros:\n";
    for (int i = 0; i < n; i++) {
        cout << "Numero " << (i + 1) << ": ";
        cin >> dados[i];
    }
}

// Procedimento para exibir o resultado padronizado
void saida(string operacao, float resultado) {
    cout << "\n-----------------------------------" << endl;
    cout << "Resultado da " << operacao << ": " << resultado << endl;
    cout << "-----------------------------------" << endl;
}

// Procedimento para cálculo da Média
void calcularMedia() {
    float soma = 0;
    for (size_t i = 0; i < dados.size(); i++) {
        soma += dados[i];
    }
    resMedia = soma / dados.size();
}

// Procedimento para cálculo da Mediana
void calcularMediana() {
    vector<float> temp = dados;
    sort(temp.begin(), temp.end());

    size_t n = temp.size();
    if (n % 2 != 0) {
        resMediana = temp[n / 2];
    } else {
        resMediana = (temp[(n / 2) - 1] + temp[n / 2]) / 2.0;
    }
}

// Procedimento para cálculo da Variância Amostral
void calcularVariancia() {
    calcularMedia(); // Obtém a média atualizada

    float somaQuadrados = 0;
    for (size_t i = 0; i < dados.size(); i++) {
        somaQuadrados += pow(dados[i] - resMedia, 2);
    }
    resVariancia = somaQuadrados / (dados.size() - 1);
}

// Procedimento para cálculo do Desvio Padrão
void calcularDesvioPadrao() {
    resDesvioPadrao = sqrt(resVariancia);
}
