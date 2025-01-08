#include <iostream>

int main(void) {
    int a;
    int b;
    std::cin >> a >> b;
    
    for (int i = 0; i < b; ++i)
    {
        for (int j = 0; j < a; ++j)
        {
            std::cout << '*';
        }
        
        std::cout << std::endl;
    }
    
    return 0;
}