#include <iostream>
#include <vector>
#include <string>
#include <locale>

bool compararNomes(const std::string& a, const std::string& b, const std::locale& loc) {
    const auto& collate = std::use_facet<std::collate<char>>(loc);
    // compare retorna < 0 se 'a' for menor que 'b'
    return collate.compare(a.data(), a.data() + a.size(), 
                           b.data(), b.data() + b.size()) <= 0;
}


void trocar(std::string& a, std::string& b) {
    std::string temp = a;
    a = b;
    b = temp;
}

/ Função de particionamento do QuickSort
int particionar(std::vector<std::string>& vetor, int inicio, int fim, const std::locale& loc) {
    std::string pivo = vetor[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        // Se o elemento atual for menor ou igual ao pivô em ordem alfabética
        if (compararNomes(vetor[j], pivo, loc)) {
            i++;
            trocar(vetor[i], vetor[j]);
        }
    }

    trocar(vetor[i + 1], vetor[fim]);
    return i + 1;
}

// Função principal do QuickSort (Recursiva)
void quickSort(std::vector<std::string>& vetor, int inicio, int fim, const std::locale& loc) {
    if (inicio < fim) {
        int indicePivo = particionar(vetor, inicio, fim, loc);

        quickSort(vetor, inicio, indicePivo - 1, loc);
        quickSort(vetor, indicePivo + 1, fim, loc);
    }
}

// Função utilitária para imprimir o vetor numerado
void imprimirVetor(const std::vector<std::string>& vetor) {
    for (size_t i = 0; i < vetor.size(); i++) {
        std::cout << (i + 1) << ". " << vetor[i] << "\n";
    }
}

int main() {
    // Configura o locale para português (compatível com Linux/macOS/Windows)
    std::locale loc("");

    // Nomes extraídos da imagem ("Nomes antes da ordenação")
    std::vector<std::string> nomes = {
        "Facebookson de Oliveira",
        "Walter Paraíba",
        "Bruce Lee de Taubaté",
        "Relíquia",
        "Ana Cristina",
        "Anderlaine de Oliveira",
        "Bill Gates da Silva",
        "Chuck Norris",
        "João dos Venenos",
        "Zuleide da Quebrada"
    };

    std::cout << "=== Nomes antes da ordenação ===\n";
    imprimirVetor(nomes);

    // Executa o QuickSort
    quickSort(nomes, 0, nomes.size() - 1, loc);

    std::cout << "\n=== Nomes depois da ordenação ===\n";
    imprimirVetor(nomes);

    return 0;
}
