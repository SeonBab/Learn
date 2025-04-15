#include <vector>
#include <unordered_map>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    
    unordered_map<int, int> weightCount;
    
    for (int weight : weights)
    {
        ++weightCount[weight];
    }
    
    for (const auto& [w, count] : weightCount)
    {
        if (count > 1)
        {
            answer += (static_cast<long long>(count) * static_cast<long long>(count - 1)) / 2;
        }
    }
    
    for (const auto& [w, count] : weightCount)
    {
        vector<pair<int, int>> ratios = {{2, 3}, {3, 4}, {1, 2}};
        
        for (const auto& ratio : ratios)
        {
            long long num = static_cast<long long>(w) * static_cast<long long>(ratio.first);
            if (num % ratio.second == 0)
            {
                int target = num / ratio.second;
                if (weightCount.find(target) != weightCount.end())
                {
                    answer += weightCount[target] * count;
                }
            }
        }
    }
    
    return answer;
}