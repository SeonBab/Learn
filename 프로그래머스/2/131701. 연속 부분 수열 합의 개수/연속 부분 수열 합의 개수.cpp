#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    unordered_set<int> sumSet;
    
    for (int i = 1; i <= elements.size(); ++i)
    {
        for (int j = 0; j < elements.size(); ++j)
        {
            int sum = 0;
            
            for (int k = 0; k < i; ++k)
            {
                sum += elements[(j + k) % elements.size()];
            }
            
            sumSet.insert(sum);
        }
    }
    
    return answer = sumSet.size();
}