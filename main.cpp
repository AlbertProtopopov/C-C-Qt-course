/******************************************************************************
код проверен на onlinegdb.com (C++, C++ 14, C++ 17)
*******************************************************************************/
#include "add.h" // вставляем копию add.h в этот файл в этом месте
#include "user.h"
#include "bot.h"

using namespace std;

int main()
{
    User user; // создание объекта класса User
    Bot bot("bot"); // создание объекта класса Bot
    user.get_name();
    bot.get_name();
    User * ptr_user; // создание укзателя на класс User
    Bot * ptr_bot; // создаине указателя на класс Bot
    
    ptr_user = &user; // копирование адреса объекта user
    ptr_user->get_name(); // вызов метода объекта user
    ptr_user = &bot; // копирование адреса объекта bot
    ptr_user->get_name(); // вызов метода объекта bot
    
    ptr_bot = &bot;
    ptr_bot->get_name();
    add::Summ summ(999); // создание объекта класса Summ из просттранства имен add
    // перегруженным конструктором с параметором типа int
    summ.add(10, 5); // выввод на консоль результата метода add
    
    return 0;
}
