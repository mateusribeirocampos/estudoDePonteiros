#include <iostream>
#include <memory>
using namespace std;

class Cachorro {
    //shared_ptr<Cachorro> petAmigo;
    weak_ptr<Cachorro> petAmigo; // Declaração de um weak_ptr para representar a amizade entre cachorros
public:
    string petNome; // Variável para armazenar o nome do cachorro
    void latir() { // Método para fazer o cachorro latir
        cout << "Cachorro " << petNome << " regras!" << endl;
    }
    Cachorro(string nome){ // Construtor da classe Cachorro
        cout << "Cachorro foi criado: " << nome << endl; // Mensagem de criação do cachorro
        petNome = nome; // Atribuição do nome do cachorro
    }
    ~Cachorro() { // Destrutor da classe Cachorro
        cout << "Cachorro destruido: " << petNome << endl; // Mensagem de destruição do cachorro
    }
    void facaAmigo(shared_ptr<Cachorro> f) { // Método para estabelecer amizade entre cachorros
        petAmigo = f; // Estabelece a relação de amizade usando um shared_ptr
    }
    void mostrarAmigos() { // Método para mostrar os amigos do cachorro
        if(!petAmigo.expired()) // Verifica se o weak_ptr ainda aponta para um objeto válido
            cout << "Meu amigo eh: " << petAmigo.lock()->petNome << endl; // Mostra o nome do amigo
        cout << "Ele eh propriedade de: " << petAmigo.use_count() << " ponteiros. " << endl; // Mostra quantos shared_ptr possuem uma referência para o amigo
    }
};

int main()
{
    shared_ptr<Cachorro> pD(new Cachorro("Gunner")); // Criação de um cachorro Gunner usando um shared_ptr
    shared_ptr<Cachorro> pD2(new Cachorro("Smokey")); // Criação de um cachorro Smokey usando um shared_ptr
    pD->facaAmigo(pD2); // Gunner faz amizade com Smokey
    pD2->facaAmigo(pD); // Smokey faz amizade com Gunner
    pD->mostrarAmigos(); // Gunner mostra seus amigos

    return 0;
}
