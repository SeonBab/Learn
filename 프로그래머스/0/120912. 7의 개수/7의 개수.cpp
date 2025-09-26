#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    
    for (int e : array)
    {
        while (e > 0)
        {
            int curNumber = e % 10;
            if (curNumber == 7)
            {
                ++answer;
            }
            
            e /= 10;
        }
    }
    
    return answer;
}