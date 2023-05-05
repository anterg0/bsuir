#include <iostream>
#include "liba.cpp"
int main() {
    Unique<int> myInt(new int(42));
    std::cout << *myInt << std::endl;
    *myInt = 100;
    std::cout << *myInt << std::endl;
    if (!myInt.isNull())
    {
        std::cout << "The pointer is not null." << std::endl;
    }
    myInt = Unique<int>(new int(200));
    std::cout << *myInt << std::endl;
    return 0;
}
