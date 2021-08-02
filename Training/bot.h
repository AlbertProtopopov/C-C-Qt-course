#ifndef BOT_H
#define BOT_H
#include "user.h"

class Bot: public User
{
    public:
    Bot(); // конструктор по умолчанию
    Bot(std::string name); // перегруженный конструктор
};

#endif