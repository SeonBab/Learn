#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0, max = numbers[0] * numbers[1];
    
    for (int i = 0; i < numbers.size(); ++i)
    {
        for (int j = 0; j < numbers.size(); ++j)
        {
            if (max < numbers[i] * numbers[j] && i != j)
            {
                max = numbers[i] * numbers[j];
            }
        }
    }
        
    answer = max;
    
    return answer;
}