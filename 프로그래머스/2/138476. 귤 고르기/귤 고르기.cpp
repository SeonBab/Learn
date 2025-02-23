#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    unordered_map<int, int> countMap;    
    
    for (int e : tangerine)
    {
        ++countMap[e];
    }
    
    vector<int> countVec;
    for (auto e : countMap)
    {
        countVec.push_back(e.second);
    }
    sort(countVec.rbegin(), countVec.rend());
    
    int boxCount = 0;
    for (int i = 0; i < countVec.size(); ++i)
    {
        ++answer;
        boxCount += countVec[i];
        
        if (boxCount >= k)
        {
            break;
        }
    }
    
    return answer;
}