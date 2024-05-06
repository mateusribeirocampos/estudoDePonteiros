#include <iostream>
#include <memory>

class Person {
    private: 
    std::string user;

    public:
    int ID;

    public:
        // Constructor
        Person(const std::string& username, int id) : user(username), ID(id) {}

        // Destructor
        ~Person() {}

        // Getter for user
        std::string getUser() const {
            return user;
        }

        // Setter for user
        void setUser(const std::string& username) {
            user = username;
        }
};

int main() {

std::unique_ptr<Person> owner(new Person("John", 1));   
auto new_owner = std::move(owner);

if (owner) {
    std::cout << "new_owner possui um objeto." << std::endl;
} else {
    std::cout << "new_owner não possui nenhum objeto." << std::endl;
}

std::cout << "Owner: " << new_owner->getUser() << std::endl;
std::cout << "ID: " << new_owner->ID << std::endl;

if (new_owner) {
    std::cout << "new_owner possui um objeto." << std::endl;
} else {
    std::cout << "new_owner não possui nenhum objeto." << std::endl;
}

return 0;
}

