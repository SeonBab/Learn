#include <string>
#include <vector>
#include <climits>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    
    int leftPointer = 0;
    int rightPointer = 0;
    int minLength = INT_MAX;
    
    int sum = sequence[0];
    
    while(rightPointer < sequence.size())
    {
        if (sum < k)
        {
            ++rightPointer;
            sum += sequence[rightPointer];
        }
        else if (sum > k)
        {
            sum -= sequence[leftPointer];
            ++leftPointer;
        }
        else
        {
            int length = rightPointer - leftPointer;
            
            if(minLength > length)
            {
                minLength = length;
                answer = {leftPointer, rightPointer};
            }
            
            sum -= sequence[leftPointer];
            ++leftPointer;
        }
    }
    
    return answer;
}