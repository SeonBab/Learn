#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    
    for (auto e : my_string)
    {
        // my_string에서 자연수를 찾음
        if (e <= '9' && e >= '0')
        {
            answer += e - '0';
        }
    }
    return answer;
}