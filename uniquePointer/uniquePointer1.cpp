#include <iostream>
#include <memory>
using namespace std;

struct DeletePointer {
    void operator()(int* p) {
        cout << "Deletando o ponteiro" << endl;
        delete p;
    }
};

int main(){
    // Criando um objeto usando um unique_ptr com o valor 5
    unique_ptr<int> p1(new int(5));

    // Criando um unique_ptr usando a função make_unique e inicializando com o valor 10
    unique_ptr<int> p2 = make_unique<int>(10);

    // Movendo o ponteiro único de p1 para p3
    unique_ptr<int> p3 = move(p1);

    // Verificando se p1 é nulo antes de desreferenciá-lo
    if(p1) {
        cout << "p1: " << *p1 << endl;
    } else {
        cout << "p1 eh nulo" << endl;
    }

    // Imprimindo os valores apontados pelos ponteiros
    cout << "p2: " << *p2 << ", p3: " << *p3 << endl;

    // Verificando se o ponteiro p2 possui um objeto
    if(p2) {
        cout << "p2 = " << *p2 << " possui o objeto" << endl;
    } else {
        cout << "p2 nao possui o objeto" << endl;
    }

    // verificando se o ponteiro p3 possui um objeto
    if(p3) {
        cout << "p3 = " << *p3 << " possui o objeto" << endl;
    } else {
        cout << "p3 nao possui o objeto" << endl;
    }

    // Liberando a referência do ponteiro p2
    p2.reset();

    // Liberando a referência do ponteiro p3
    p3.reset();

        // Verificando se o ponteiro p2 possui um objeto
    if(p2) {
        cout << "p2 = " << *p2 << " possui o objeto" << endl;
    } else {
        cout << "p2 nao possui o objeto" << endl;
    }

    // verificando se o ponteiro p3 possui um objeto
    if(p3) {
        cout << "p3 = " << *p3 << " possui o objeto" << endl;
    } else {
        cout << "p3 nao possui o objeto" << endl;
    }

    // DeletePointer é um objeto que sobrescreve o operador de chamada de função
    // para deletar o ponteiro passado como argumento
    unique_ptr<int, DeletePointer> p4(new int(20), DeletePointer());

    return 0;
}
