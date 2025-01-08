#include <iostream>
#include <string>

int main(void) {
    int a;
    int b;
    std::cin >> a >> b;
    
    std::string str;
    str.append(a, '*');
    
    for (int i = 0; i < b; ++i)
    {        
        std::cout << str << std::endl;
    }
    
    return 0;
}