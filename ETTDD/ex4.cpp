#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<string, int> tabela;

    tabela["um"] = 1;
    tabela["dois"] = 2;
    tabela["tres"] = 3;

    cout<<"Valor: "<<tabela["um"]<<endl;
    cout<<"Valor: "<<tabela["dois"]<<endl;
    cout<<"Valor: "<<tabela["tres"]<<endl;

    return 0;
}
