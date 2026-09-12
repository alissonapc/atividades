#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<string, int> tabela;

    tabela["um"] = 1;
    tabela["dois"] = 2;
    tabela["tres"] = 3;

    for (auto par : tabela) {
        cout << "Valor: " << par.second << endl;
    }

    return 0;
}
