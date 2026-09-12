#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {

    unordered_map<string, string> tabela;

    tabela["Brasil"] = "Brasilia";
    tabela["Franca"] = "Paris";
    tabela["Japao"] = "Toquio";
    tabela["Egito"] = "Cairo";
    tabela["Canada"] = "Otawa";

    unordered_map<string, string>::iterator it = tabela.find("Franca");
    if (it != tabela.end()) {
        cout << "Capital da " << it->first << ": " << it->second << endl;
    }

    tabela.erase("Egito");
    cout << tabela.count("Egito") << endl;

    for (auto& p : tabela) {
        cout << p.first << " -> " << p.second << endl;
    }

    tabela["Brasil"] = "Rio de Janeiro";
    cout << tabela["Brasil"] << endl;

    return 0;
}
