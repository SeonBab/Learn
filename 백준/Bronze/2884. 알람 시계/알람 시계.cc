#include <iostream>

int main()
{
    int H, M;
    
    std::cin >> H >> M;
    
    int TotalMinutes = H * 60 + M;
    int ResultMinutes = (TotalMinutes - 45 + 24 * 60) % (24 * 60);
    
    std::cout << ResultMinutes / 60 << " " << ResultMinutes % 60 << std::endl;
}