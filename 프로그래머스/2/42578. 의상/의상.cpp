#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    
    unordered_map<string, int> clothesMap;
    
    for(int i = 0; i < clothes.size(); ++i)
    {
        ++clothesMap[clothes[i][1]];
    }
    
    answer = 1;
    for (const auto& pair : clothesMap)
    {
        answer *= (pair.second + 1);
    }
    answer -= 1;
    
    return answer;
}