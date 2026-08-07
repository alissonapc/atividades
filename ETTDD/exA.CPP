#include <iostream>

using namespace std;

int main(void){
    int x = 7;
    int *px = &x;

    *px = 21;

    cout << "Valor de x agora e: " << *px << endl;

    return 0;
}
