#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int n) {
    int answer = 0, num = 101;
    
    for (int i = 0; i < array.size(); ++i)
    {
        if (num > abs(array[i] - n))
        {
            num = abs(array[i] - n);
            answer = array[i];
        }
        else if (num == abs(array[i] - n) && answer > array[i])
        {
            answer = array[i];
        }
        
    }
    
    return answer;
}