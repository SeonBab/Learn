#include <vector>
#include <limits>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int min = std::numeric_limits<int>::max();
    int minIndex = 0;
    
    for (int i = 0; i < arr.size(); ++i)
    {
        if (min > arr[i])
        {
            min = arr[i];
            minIndex = i;
        }
    }
    
    for (int i = 0; i < arr.size(); ++i)
    {
        if (i != minIndex)
        {
            answer.push_back(arr[i]);
        }
    }
    
    if (0 == answer.size())
    {
        answer.push_back(-1);
    }
    
    return answer;
}