#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_map<string, int> completionMap;
    
    for (const auto& e : participant)
    {
        completionMap[e] += 1;
    }
    
    for (const auto& e : completion)
    {
        if (completionMap.find(e) != completionMap.end())
        {
            completionMap[e] -= 1;
        }
    }
    
    for (const auto& e : completionMap)
    {
        if (e.second == 1)
        {
            answer = e.first;
        }
    }
    
    return answer;
}