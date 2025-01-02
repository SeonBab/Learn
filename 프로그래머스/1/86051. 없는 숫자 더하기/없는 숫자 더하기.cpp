#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    
    vector<bool> numList (10);
    
    for (int i = 0; i < numbers.size(); ++i)
    {
        numList[numbers[i]] = true;
    }
    
    for (int i = 0; i < numList.size(); ++i)
    {
        if (numList[i] == false)
        {
            answer += i;
        }
    }
    
    return answer;
}