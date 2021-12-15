#ifndef USER_H
#define USER_H
#include <string>

class User {
public:
    User(const std::string& id, const std::string& name, const std::string& pass)
        : _id{ id }, _name{ name }, _password{pass} {
    }

    virtual void showUserInfo() const = 0;

protected:
    const std::string _id;
    const std::string _name;
    const std::string _password;
};

#endif // !USER_H

