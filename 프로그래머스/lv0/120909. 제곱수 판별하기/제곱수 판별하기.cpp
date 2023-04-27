#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 2, temp{};
    switch (n & 0x0f)
    {
        case 0:
        case 1:
        case 4:
        case 9:
            temp = (sqrt(n) + 0.5);
            if (temp * temp == n)
            {
                answer = 1;
            }
            
        default:
            return answer;
    }
}