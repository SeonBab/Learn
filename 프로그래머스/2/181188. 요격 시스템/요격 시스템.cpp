#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    sort(targets.begin(), targets.end(), [](const vector<int>& a, const vector<int>& b)
         {
            return a[1] < b[1];
         });
    
    int lastXCorrdinate = 0;
    
    for (const auto & target : targets)
    {
        int start = target[0];
        int end = target[1];
        
        if (lastXCorrdinate <= start)
        {
            ++answer;
            
            lastXCorrdinate = end;
        }
    }
    
    return answer;
}