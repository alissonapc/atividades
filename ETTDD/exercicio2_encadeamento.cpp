
#include <iostream>
using namespace std;

struct No {
    int valor;
    No* proximo;
};

int main() {
    No* primeiro = new No;
    primeiro->valor = 10;
    primeiro->proximo = nullptr;

    No* segundo = new No;
    segundo->valor = 20;
    segundo->proximo = nullptr;

    No* terceiro = new No;
    terceiro->valor = 20;
    terceiro->proximo = nullptr;

    primeiro->proximo = segundo;
    segundo->proximo = terceiro;
    terceiro->proximo = nullptr;

    No* atual = primeiro;

    while (atual != nullptr){
        cout<<atual->valor<< " ";
        atual = atual->proximo;
    }

    delete primeiro;
    delete segundo;
    delete terceiro;

    return 0;
}
