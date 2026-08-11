#include <iostream>
#include <vector>
#include <numeric>   // Para std::accumulate
#include <algorithm> // Para std::sort
#include <cmath>     // Para std::sqrt e std::pow
#include <iomanip>   // Para std::fixed e std::setprecision

// Função para calcular a Média
double calcularMedia(const std::vector<double>& dados) {
    if (dados.empty()) return 0.0;

    double soma = std::accumulate(dados.begin(), dados.end(), 0.0);
    return soma / dados.size();
}

// Função para calcular a Mediana
double calcularMediana(std::vector<double> dados) {
    if (dados.empty()) return 0.0;

    // Ordena os dados para encontrar a mediana
    std::sort(dados.begin(), dados.end());
    size_t n = dados.size();

    if (n % 2 != 0) {
        // Se a quantidade de elementos for ímpar, pega o elemento central
        return dados[n / 2];
    } else {
        // Se for par, faz a média dos dois elementos centrais
        return (dados[(n / 2) - 1] + dados[n / 2]) / 2.0;
    }
}

// Função para calcular a Variância Amostral
double calcularVariancia(const std::vector<double>& dados, double media) {
    if (dados.size() <= 1) return 0.0;

    double somaQuadradosDiferenca = 0.0;
    for (double x : dados) {
        somaQuadradosDiferenca += std::pow(x - media, 2);
    }

    // Variância amostral (divide por n - 1)
    return somaQuadradosDiferenca / (dados.size() - 1);
}

// Função para calcular o Desvio Padrão
double calcularDesvioPadrao(double variancia) {
    return std::sqrt(variancia);
}

int main() {
    int n;

    std::cout << "Quantos números deseja inserir? ";
    std::cin >> n;

    if (n <= 1) {
        std::cout << "É necessário inserir pelo menos 2 números para calcular a variância amostral." << std::endl;
        return 1;
    }

    std::vector<double> numeros(n);
    std::cout << "Digite os " << n << " números:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "Número " << (i + 1) << ": ";
        std::cin >> numeros[i];
    }

    // Processamento através das funções
    double media = calcularMedia(numeros);
    double mediana = calcularMediana(numeros); // Passado por valor pois ordena a cópia
    double variancia = calcularVariancia(numeros, media);
    double desvioPadrao = calcularDesvioPadrao(variancia);

    // Exibição dos resultados formatados
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\n=== RESULTADOS ESTATÍSTICOS ===\n";
    std::cout << "Média:         " << media << "\n";
    std::cout << "Mediana:       " << mediana << "\n";
    std::cout << "Variância:     " << variancia << "\n";
    std::cout << "Desvio Padrão: " << desvioPadrao << "\n";

    return 0;
}
