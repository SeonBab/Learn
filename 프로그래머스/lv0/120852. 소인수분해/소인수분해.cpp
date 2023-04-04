#include <vector>

using namespace std;

// 가장 작은 소수인 2부터 시작, n과 같은 소인수가 있을 수 있으므로 <=
// if문의 조건이 성립한다면 i는 소인수
// while을 사용해 i로 소인수분해를 더이상 할 수 없을 때 값이 저장되므로 i의 값은 중복되지 않는다.
vector<int> solution(int n) {
    vector<int> answer;
    
    for (int i = 2; i <= n; ++i)
    {

        if (n % i == 0)
        {
            while (n % i == 0)
            {
                n /= i;
            }
            
            answer.push_back(i);
        }

    }
    
    return answer;
}