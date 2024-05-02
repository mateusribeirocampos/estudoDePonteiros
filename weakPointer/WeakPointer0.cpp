/*onteiro Fraco (weak_ptr):
O weak_ptr é usado em conjunto com shared_ptr para evitar referências cíclicas e vazamentos de memória.
Ele não incrementa o contador de referências, mas pode ser bloqueado em um shared_ptr para acessar o objeto.
Ele é útil para situações em que você precisa de uma referência temporária para um objeto gerenciado por shared_ptr.*/

#include <memory>
#include <iostream>

int main() {
    std::shared_ptr<int> ptr = std::make_shared<int>(42);
    std::weak_ptr<int> weakPtr = ptr;
    if (auto sharedPtr = weakPtr.lock()) {
        std::cout << *sharedPtr << std::endl;  // Imprime 42
    } else {
        std::cout << "O objeto foi liberado." << std::endl;
    }
    return 0;
}
