#include "FilterClass.h"
#include <iostream>
#include <cstring>

int main() 
{
    while ((true)) {
    setlocale(LC_CTYPE, "rus");
    string file;
    std::cout << std::endl << "������� ��� ����� (� �������, text.txt):" << std::endl;
    std::cin >> file;
    string pattern;
    std::cout << "������� ������:" << std::endl;
    std::cin >> pattern;
    std::cout <<"���������:" << std::endl;
    FilterClass filtr(file, pattern);}
    //��������� ������ ���� ����������� �����. ��� �������� �������������� ����������� �����...
}