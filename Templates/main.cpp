#include <iostream>
#include <vector>
 
int main()
{
    unsigned count;     // количество вводимых чисел в вектор
    std::vector<int> numbers;
 
    // вводим количество чисел
    std::cout << "Enter vector count: ";
    std::cin >> count;    // вводим число
    // вводим значения для вектора
    std::cout << "Enter " << count << " numbers" << std::endl;
    int n;
    for(unsigned i{}; i < count; i++)
    {
 
        std::cin >> n;          // вводим число
        numbers.push_back(n);   // добавляем число в вектор
    }
 
    // выводим массив в обратном порядке
    for (unsigned i {1}; i <= count; ++i)
    {
        std::cout << numbers[count - i] << "\t";
    }
    std::cout << std::endl;
}