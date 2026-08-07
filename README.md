```cpp
#include <iostream>

using namespace std;

int main() {
    int arr[10] = {3, 7, 12, 18, 25, 31, 44, 56, 70, 88};
    int x;

    cout << "Digite um valor para procurar: ";
    cin >> x;

    int inicio = 0;
    int fim = 9;
    int ciclos = 0;
    bool encontrado = false;

    while (inicio <= fim) {
        ciclos++;

        int meio = (inicio + fim) / 2;

        if (arr[meio] == x) {
            encontrado = true;

            cout << "Valor encontrado: " << arr[meio] << endl;
            cout << "Ciclos: " << ciclos << endl;

            break;
        }

        if (x < arr[meio]) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }

    if (!encontrado) {
        cout << "Valor nao encontrado." << endl;
        cout << "Ciclos: " << ciclos << endl;
    }

    return 0;
}
```
