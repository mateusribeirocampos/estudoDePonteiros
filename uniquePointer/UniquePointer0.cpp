/*Ponteiro Único (unique_ptr):
O unique_ptr é um ponteiro inteligente que gerencia a alocação de memória para um único objeto.
Ele garante que apenas um unique_ptr possua a propriedade de um recurso alocado na memória.
Quando um unique_ptr é destruído, ele automaticamente libera a memória que está alocada.*/

#include <memory>
#include <iostream>

int main() {
    std::unique_ptr<int> ptr(new int(42));
    std::cout << *ptr << std::endl;  // Imprime 42
    return 0;  // A memória é liberada automaticamente ao sair do escopo
}
