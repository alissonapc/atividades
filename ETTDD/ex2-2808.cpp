#include <iostream>
#include <utility>
using namespace std;

void mostrar(int itens[], int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        cout << itens[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int itens[], int quantidade) {

    for (int i = 0; i < quantidade - 1; i++) {
        for (int j = 0; j < quantidade - 1 - i; j++) {
            if (itens[j] > itens[j + 1]) {
                swap(itens[j], itens[j + 1]);
            }
        }
    }
}

int main() {

    int itens[6] = {40, 10, 50, 20, 60, 30};

    bubbleSort(itens, 6);
    mostrar(itens, 6);

    return 0;
}
