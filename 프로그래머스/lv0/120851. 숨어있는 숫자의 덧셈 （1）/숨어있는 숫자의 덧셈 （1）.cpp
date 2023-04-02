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
            // 찾은 자연수를 char에서 int로 변환 후 연산
            answer += static_cast<int>(e) - static_cast<int>('0');
        }
    }
    return answer;
}