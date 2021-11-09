#include <iostream>
#include <iomanip>

/*using namespace std;*/

int main(){
    int num;

    std::cout << "Hello World" << std::endl;
    std::cout << "give a number: ";
    std::cin >> num;

    std::cout << "in decimal: ";   
    std::cout << num << std::endl;
    std::cout << "in hex: ";
    std::cout << std::hex << num << std::endl;
    
    return 0;
}
