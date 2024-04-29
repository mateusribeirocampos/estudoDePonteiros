#include <iostream>
using namespace std;

int main(){
    const char *nomes[] = {"Fulano", "Beltrano", "Ciclano"};
    cout << "Endereco de memoria do array: " << nomes << "\n";
    cout << "Endereco de memoria do primeiro elemento: " << &nomes[0] << "\n";
    cout << "Endereco de memoria do segundo elemento: " << &nomes[1] << "\n";
    cout << "Endereco de memoria do terceiro elemento: " << &nomes[2] << "\n\n";
    cout << "Endereco de memoria do primeiro elemento: " << nomes[0] << "\n";
    cout << "Endereco de memoria do segundo elemento: " << nomes[1] << "\n";
    cout << "Endereco de memoria do terceiro elemento: " << nomes[2] << "\n";
    
    return 0;
}