#ifndef WIZZMANIA_SECURITY_HPP
#define WIZZMANIA_SECURITY_HPP

#include <string>

class Security {
    public:
    std::string hashPassword;
    bool isIdentical(std::string pass1, std::string pass2);
private:


};

#endif