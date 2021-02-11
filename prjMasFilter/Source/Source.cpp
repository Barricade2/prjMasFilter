#include "FilterClass.h"
#include <iostream>
#include <cstring>

int main() 
{
    while ((true)) {
    setlocale(LC_CTYPE, "rus");
    string file;
    std::cout << std::endl << "Введите имя файла (к примеру, text.txt):" << std::endl;
    std::cin >> file;
    string pattern;
    std::cout << "Введите шаблон:" << std::endl;
    std::cin >> pattern;
    std::cout <<"Результат:" << std::endl;
    FilterClass filtr(file, pattern);}
    //Принимает только одну фильтрующую маску. Для открытие дополнитеьного функционала нужно...
}