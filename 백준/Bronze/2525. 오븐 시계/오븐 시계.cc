#include <iostream>

int main()
{
    int Hour, Minute, CookTime;
    std::cin >> Hour >> Minute >> CookTime;
    
    int TotalCookTime = (Hour * 60) + Minute + CookTime;
    
    std::cout << (TotalCookTime / 60) % 24 << " " << TotalCookTime % 60;
}