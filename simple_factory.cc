#include <iostream>
#include <string>
#include <exception>
// Simple Factry Pattern
class User {
    public:
    virtual void create() {
        std::cout << "User" << std::endl;
    };
    virtual ~User();
};
class Admin: public User {
    public:
        void create() {
            std::cout << "Admin created" << std::endl;
        }

};
// Problem with simple factory: violates OCP principle, it means when we have a new type, u have to modify the method, instead of extending the class.
class Normal: public User {
        public:
            void create() override {
                std::cout << "Normal created" << std::endl;
            }
};
class UserFactory {
    UserFactory() {}
    public:
        static User* create(std::string userType) {
            if(userType == "Admin"){
                return new Admin();
            }
            if(userType == "Normal"){
                return new Normal();
            }
            throw std::invalid_argument("Type not supported");
    }
};
int main() {
    User* user1 = UserFactory::create("Admin");
    user1->create();
    User* user2 = UserFactory::create("Normal");
    user2->create();
    UserFactory::create("Stranger");
    return 0;
}