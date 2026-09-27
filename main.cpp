#include "LinkedList.h"

#include <iostream>

int main() {
    LinkedList list;
    list.push_back(20);
    list.push_back(30);
    list.push_front(10);

    list.print(std::cout); // 10 -> 20 -> 30 -> nullptr
    std::cout << "Size: " << list.size() << '\n';
    std::cout << "Contains 20: " << std::boolalpha << list.contains(20) << '\n';

    list.remove(20);
    list.print(std::cout); // 10 -> 30 -> nullptr

    list.clear();
    std::cout << "Empty: " << list.empty() << '\n';
}
