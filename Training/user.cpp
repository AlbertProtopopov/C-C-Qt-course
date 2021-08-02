#include <iostream>
#include "user.h"

  void User::set_name(std::string name) // public метод класса для установки имени пользователя
  {
      this->name = name; // используем скрытый константный указатель класса "this"
  }                      // и оператор выбора членов структур/классов через указатель "->"
  void User::get_name() // public метод класса для вывода в консоли имени пользователя
  {
      std::cout << name << std::endl; // вывод на консоль
  }