#include <iostream>
#include <string>
#include <exception>
// Factory method Pattern: defines a method, that is implemnented within subclasses to decide which objects to instantiate.
// Doesn't violate ocp principle.
class User {
    public:
    virtual void create() const {
        std::cout << "User" << std::endl;
    };
    //virtual ~User(); // commenté juste psq après faut le redefinir dans chaque putain de method
};
class Admin: public User {
    public:
        void create() const override {
            std::cout << "Admin created" << std::endl;
        }

};
// Problem with simple factory: violates OCP principle, it means when we have a new type, u have to modify the method, instead of extending the class.
class Normal: public User {
        public:
            void create() const override {
                std::cout << "Normal created" << std::endl;
            }
};
class Viewer: public User {
    public:
        void create() const override {
            std::cout << "Viewer created" << std::endl;
        }

};

class Moderator: public User {
        public:
            void create() const override {
                std::cout << "Moderator created" << std::endl;
            }
};
class TypesFactory {
    public:
        virtual User* create(std::string userType) const = 0;
        virtual ~TypesFactory() = default;
};

class UserFactory : public TypesFactory {
    public:
        User* create(std::string userType) const override  {
            if(userType == "Admin"){
                return new Admin();
            }
            if(userType == "Normal"){
                return new Normal();
            }
            throw std::invalid_argument("Type not supported");
    }
};
class ViewersFactory : public TypesFactory {
    public:
        User* create(std::string userType) const override {
            if(userType == "Viewer"){
                return new Viewer();
            }
            if(userType == "Moderator"){
                return new Moderator();
            }
            throw std::invalid_argument("Type not supported");
    }
};
int main() {
    TypesFactory* usersFactory = new UserFactory();
    TypesFactory* viewersFactory = new ViewersFactory();
    User* user1 = usersFactory->create("Admin");
    user1->create();
    User* user2 = viewersFactory->create("Viewer");
    user2->create();
    return 0;
}