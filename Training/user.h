#ifndef USER_H
#define USER_H

#include <string>

class User //объявление класса
{
  std::string name = "user"; // private член класса
  public:               // public члены класса
  void set_name(std::string name); // public метод класса для установки имени пользователя
  void get_name(); // public метод класса для вывода в консоли имени пользователя
};

#endif