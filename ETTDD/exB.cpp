```cpp
#include <iostream>

using namespace std;

int main() {
    int arr[10] = {3, 7, 12, 18, 25, 31, 44, 56, 70, 88};
    int x;

    cout << "Digite um valor para procurar: ";
    cin >> x;

    int ciclos = 0;
    bool encontrado = false;

    for (int i = 0; i < 10; i++) {
        ciclos++;

        if (arr[i] == x) {
            encontrado = true;

            cout << "Valor encontrado: " << arr[i] << endl;
            cout << "Ciclos: " << ciclos << endl;

            break;
        }
    }

    if (!encontrado) {
        cout << "Valor nao encontrado." << endl;
        cout << "Ciclos: " << ciclos << endl;
    }

    return 0;
}
```
