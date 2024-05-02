#include <iostream>
#include <memory>

using namespace std;

int main(){
    // Criando um objeto usando um unique_ptr
    unique_ptr<int> Ptr1(new int(42));

    // Criando um unique_ptr a partir de outro unique_ptr
    unique_ptr<int> Ptr2 = make_unique<int>(*Ptr1);

    // Criando um unique_ptr usando a função make_unique
    unique_ptr<int> Ptr3 = make_unique<int>(10);

    // verificando o valor do ponteiro
    cout << "Ptr1: " <<  *Ptr1 << ", " << "Ptr2: " << *Ptr2 << ", " << "Ptr3: " << *Ptr3 << endl;

    // Verificando se o objeto ainda existe
    if(Ptr1){
        cout << "O valor eh: " << *Ptr1 << endl;
    }else{
        cout << "O objeto Ptr1 nao existe mais." << endl;
    }

    // Verificando se o objeto ainda existe
    if(Ptr2){
        cout << "O valor eh: " << *Ptr2 << endl;
    }else{
        cout << "O objeto Ptr2 nao existe mais." << endl;
    }

    // Verificando se o objeto ainda existe
    if(Ptr3){
        cout << "O valor eh: " << *Ptr3 << endl;
    }else{
        cout << "O objeto Ptr3 nao existe mais." << endl;
    }

    // Liberando a referência do unique_ptr
    Ptr2.reset();

    return 0;
}
