#include <iostream>
#include <unordered_set>
using namespace std;

int main() {

    unordered_set<int> conjunto = {10, 20, 30, 20, 10, 40};
    cout << conjunto.size() << endl;

    cout << "Antes: " << conjunto.size() << endl;
    conjunto.insert(50);
    conjunto.insert(20);
    cout << "Depois: " << conjunto.size() << endl;

    cout << conjunto.count(30) << endl;

    conjunto.erase(10);
    for (int x : conjunto) {
        cout << x << " ";
    }
    cout << endl;

    unordered_set<int> ingressos;
    ingressos.insert(1001);
    ingressos.insert(1002);
    ingressos.insert(1003);

    int verificar = 1002;
    if (ingressos.count(verificar)) {
        cout << "Ingresso " << verificar << " ja foi usado." << endl;
    } else {
        cout << "Ingresso " << verificar << " liberado." << endl;
        ingressos.insert(verificar);
    }

    return 0;
}
