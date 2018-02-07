#ifndef REGISTER_H
#define REGISTER_H

#include <string>

class Register
{
    public:
        Register(std::string name, int value);
        Register(std::string name);
        Register();
        const std::string getName();
        const int getValue();
        const void display();

    protected:

    private:
        std::string m_name;
        int m_value;
};

#endif // REGISTER_H
