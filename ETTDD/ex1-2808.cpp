#include <iostream>
using namespace std;

int buscaBinaria(int itens[], int quantidade, int procurado) {

    int buscaBinaria(int itens[], int quantidade, int procurado) {
    int inicio = 0;
    int fim = quantidade - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (itens[meio] == procurado) {
            return meio;
        } else if (itens[meio] < procurado) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return -1;
}

    return -1;
}

int main() {

    int itens[7] = {10, 20, 30, 40, 50, 60, 70};

    cout << buscaBinaria(itens, 7, 60) << " ";
    cout << buscaBinaria(itens, 7, 25);

    cout << endl;
    return 0;
}
