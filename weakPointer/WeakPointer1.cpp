#include <iostream>
#include <memory>

using namespace std;

int main()
{
    // Criando um objeto usando um shared_ptr
    shared_ptr<int> sharedPtr = make_shared<int>(42);

    // Criando um weak_ptr a partir do shared_ptr
    weak_ptr<int> weakPtr = sharedPtr;

    // Verificando se o objeto ainda existe
    if (!weakPtr.expired())
    {
        // Acessando o objeto através do weak_ptr
        cout << "O valor eh: " << *weakPtr.lock() << endl;
    }
    else
    {
        cout << "O objeto nao existe mais." << endl;
    }

    // Liberando a referência do shared_ptr
    sharedPtr.reset();

    // Verificando novamente se o objeto ainda existe
    if (!weakPtr.expired())
    {
        cout << "O valor eh: " << *weakPtr.lock() << endl;
    }
    else
    {
        cout << "O objeto nao existe mais." << endl;
    }

    return 0;
}
