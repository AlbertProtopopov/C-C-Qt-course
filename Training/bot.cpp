#include "bot.h"

Bot::Bot(){};

Bot::Bot(std::string name) // перегруженный конструктор
    {
        set_name(name); // вызов метода
    }