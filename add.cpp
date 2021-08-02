#include <iostream>
#include "add.h"
//#include "add.h"

add::Summ::Summ(){}

add::Summ::Summ(int i)
{
    std::cout << i << std::endl;
}

void add::Summ::add(int x, int y)
{
    std::cout << x + y << std::endl;
}