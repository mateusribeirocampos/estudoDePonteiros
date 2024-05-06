#include <iostream>
#include <memory>

class Person
{
private:
    std::string user;
    int Id;

public:
    std::string category;

public:
    // constructor
    Person(const std::string &username, int id, const std::string &level) : user(username), Id(id), category(level){};

    ~Person(){};

    // Getter para user e Id
    std::string getUser() const
    {
        return user;
    }
    // getter and setter
    int getId()
    {
        return Id;
    }

    void setUser(const std::string &username)
    {
        user = username;
    }

    void setId(int id)
    {
        Id = id;
    }
};

int main()
{
    std::shared_ptr<Person> SharedPerson = std::make_shared<Person>("Joao", 17, "Manager");
    std::shared_ptr<Person> SharedPerson1 = SharedPerson;

    if (SharedPerson)
    {
        std::cout << "SharedPerson: " << SharedPerson.use_count() << std::endl;
    }
    else if (SharedPerson1)
    {
        std::cout << "SharedPerson1: " << SharedPerson1.use_count() << std::endl;
    }
    else
    {
        std::cout << "Nenhum ponteiro alocado" << std::endl;
    }

    std::cout << "Person: " << SharedPerson << std::endl;
    std::cout << "Person1: " << SharedPerson1 << std::endl;

    std::cout << "Person: " << SharedPerson->getUser() << ", " << SharedPerson->getId() << " e " << SharedPerson->category << std::endl;

    std::cout << "Person: " << SharedPerson1->getUser() << ", " << SharedPerson1->getId() << " e " << SharedPerson1->category << std::endl;

    if (SharedPerson)
    {
        std::cout << "SharedPerson: " << SharedPerson.use_count() << std::endl;
    }
    else if (SharedPerson1)
    {
        std::cout << "SharedPerson1: " << SharedPerson1.use_count() << std::endl;
    }
    else
    {
        std::cout << "Nenhum ponteiro alocado" << std::endl;
    }

    SharedPerson.reset();
    SharedPerson1.reset();

    if (!SharedPerson && !SharedPerson1)
    {
        std::cout << "Objeto Person desalocado" << std::endl;
    }
    else
    {
        std::cout << "Objeto Person ainda alocado" << std::endl;
    }

    if (SharedPerson)
    {
        std::cout << SharedPerson.use_count() << std::endl;
    }
    else if (SharedPerson1)
    {
        std::cout << SharedPerson1.use_count() << std::endl;
    }
    else
    {
        std::cout << "Nenhum ponteiro alocado" << std::endl;
    }

    return 0;
}