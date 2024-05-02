/*Ponteiro Compartilhado (shared_ptr):
O shared_ptr permite que vários ponteiros compartilhem a propriedade de um objeto alocado na memória.
Ele mantém um contador interno para controlar o número de referências ao objeto.
Quando o último shared_ptr que possui a propriedade do objeto é destruído, a memória é liberada.*/

#include <memory>
#include <iostream>

int main() {
    std::shared_ptr<int> ptr1(new int(42));
    std::shared_ptr<int> ptr2 = ptr1;
    std::cout << *ptr1 << std::endl;  // Imprime 42
    return 0;  // A memória é liberada automaticamente ao sair do escopo
}
