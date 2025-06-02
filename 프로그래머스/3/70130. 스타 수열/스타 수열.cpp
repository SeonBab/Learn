#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(std::vector<int> a) {
    int answer = 0;
    
    unordered_map<int, int> countMap;
    
    for (int number : a)
    {
        ++countMap[number];
    }
    
    for (auto [x, count] : countMap)
    {
        if (count * 2 <= answer)
        {
            continue;
        }
        
        int pairCount = 0;
        
        for (int i = 0; i < a.size() -1; ++i)
        {
            if (a[i] != x && a[i + 1] != x)
            {
                continue;
            }
            if (a[i] == a[i + 1])
            {
                continue;
            }
            
            ++pairCount;
            ++i;
        }
        
        answer = max(answer, pairCount * 2);
    }
    
    return answer;
}