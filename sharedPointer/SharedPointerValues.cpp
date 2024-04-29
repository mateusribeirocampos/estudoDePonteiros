#include <iostream>
#include <memory>
using namespace std;

class SharedPointer
{
public:
    SharedPointer(int val) : value(val)
    {
        cout << "Construtor eh chamado com o valor: " << value << endl;
    }
    ~SharedPointer()
    {
        cout << "O valor eh destruido" << endl;
    }
    void setValue(int val)
    {
        value = val;
    }
    int getValue() const
    {
        return value;
    }

private:
    int value;
};

int main()
{
    shared_ptr<SharedPointer> ptr1(new SharedPointer(10));
    cout << "Valor do ponteiro 1: " << ptr1->getValue() << endl;

    ptr1->setValue(20);
    cout << "Valor do ponteiro 1: " << ptr1->getValue() << endl;

    {
        shared_ptr<SharedPointer> ptr2 = ptr1;
        cout << "Valor do ponteiro 2: " << ptr2->getValue() << endl;

        if (ptr1.use_count() == 1)
        {
            cout << "Existe apenas 1 ponteiro" << endl;
        }
        else
        {
            cout << "Existem " << ptr1.use_count() << " ponteiros" << endl;
        }

        ptr2->setValue(30);
        cout << "Valor do ponteiro 1: " << ptr1->getValue() << endl;
        cout << "Valor do ponteiro 2: " << ptr2->getValue() << endl;

        if (ptr2.use_count() == 1)
        {
            cout << "Existe apenas 1 ponteiro" << endl;
        }
        else
        {
            cout << "Existem " << ptr2.use_count() << " ponteiros" << endl;
        }
    }

    cout << "Valor do ponteiro 1: " << ptr1->getValue() << endl;

    if (ptr1.use_count() == 1)
    {
        cout << "Existe apenas 1 ponteiro" << endl;
    }
    else
    {
        cout << "Existem " << ptr1.use_count() << " ponteiros" << endl;
    }

    return 0;
}