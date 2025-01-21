#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    for (int i = 0; i < numbers.size() - 1; ++i)
    {
        for (int j = i + 1; j < numbers.size(); ++j)
        {
            int sumNumber = numbers[i] + numbers[j];
            bool bIsFind = false;
            
            for (int k = 0; k < answer.size(); ++k)
            {
                if (answer[k] == sumNumber)
                {
                    bIsFind = true;
                }
            }
            
            if (false == bIsFind)
            {
                answer.push_back(sumNumber);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}