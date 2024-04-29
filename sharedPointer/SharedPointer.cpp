#include <iostream>
#include <memory>

using namespace std;

class SharedPointer{
    public:
    SharedPointer(){
        cout << "Construtor eh chamado " << endl;
    }
    ~SharedPointer(){
        cout << "Contrutor eh destruido " << endl;
    }
};

int main() {

    // Criando um shared pointer para manipular o ojeto da classe
    shared_ptr<SharedPointer> ponteiro1(new SharedPointer());
    {
        // criando outro shared pointer e inicializando ele com o ponteiro criando anteriormente
        shared_ptr<SharedPointer> ponteiro2 = ponteiro1;

        // Ambos shared pointer no mesmo objeto, e o contador de referencia tem aumentado em 2
        cout << "Dentro do escopo interno" << endl;

        // Verificando o número de ponteiros
        if (ponteiro1.use_count() == 1) {
            cout << "Existem apenas 1 ponteiro" << endl;
        } else {
            cout << "Existem " << ponteiro1.use_count() << " ponteiros" << endl;
        }
    }
    // O ponteiro2 deixara o escopo interno e será destruido e decrementado para 1
    cout << "Fora do escopo interno" << endl;

            // Verificando o número de ponteiros
        if (ponteiro1.use_count() == 1) {
            cout << "Existem apenas 1 ponteiro" << endl;
        } else {
            cout << "Existem " << ponteiro1.use_count() << " ponteiros" << endl;
        }

    return 0;
}