#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {

    unordered_multimap<string, int> notas;

    notas.insert(make_pair("Ana", 8));
    notas.insert(make_pair("Ana", 7));
    notas.insert(make_pair("Ana", 9));
    notas.insert(make_pair("Bruno", 6));

    cout << "Ana tem " << notas.count("Ana") << " notas." << endl;

    auto intervalo = notas.equal_range("Ana");
    cout << "Notas de Ana: ";
    for (auto it = intervalo.first; it != intervalo.second; it++) {
        cout << it->second << " ";
    }
    cout << endl;

    notas.erase("Ana");
    cout << "Tamanho apos remover Ana: " << notas.size() << endl;

    return 0;
}
