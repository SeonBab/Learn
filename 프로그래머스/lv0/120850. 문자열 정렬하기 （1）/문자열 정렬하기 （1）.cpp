#include <string>
#include <vector>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer;
    
    // answer에 숫자만 저장
    for (auto e : my_string)
    {
        if (e <= '9' && e >= '0')
        {
            answer.push_back(static_cast<int>(e) - 48);
        }
    }
    
    // 버블 정렬
    int temp {};
    
    for (int i = 0; i < answer.size(); ++i)
    {
        temp = 0;
        for (int j = 0; j < answer.size() - i - 1; ++j)
        {
            if (answer[j] > answer[j + 1])
            {
                temp = answer[j];
                answer[j] = answer[j + 1];
                answer[j + 1] = temp;
            }
        }
    }
    
    return answer;
}