#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0, num{}, index{};
    
    while (my_string[index])
    {
        while (my_string[index] >= '0' && my_string[index] <= '9')
        {
            num = num * 10 + (my_string[index] - '0');
            ++index;
        }
        
        answer += num;
        num = 0;
        ++index;
    }

    return answer;
}