#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

bool isNearWord(const string& curWord, const string& targetWord)
{
    int diffCount = 0;
    
    for (int i = 0; i < curWord.size(); ++i)
    {
        if (curWord[i] != targetWord[i])
        {
            ++diffCount;
            
            if (diffCount > 1)
            {
                return false;
            }
        }
    }
    
    return diffCount == 1;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    unordered_map<string, bool> visited;
    
    queue<pair<string, int>> q;
    q.push({begin, 0});
    
    visited[begin] = true;
    
    while (!q.empty())
    {
        auto [current, count] = q.front();
        q.pop();
        
        if (current == target)
        {
            return count;
        }
        
        for (const auto& word : words)
        {
            if (!visited[word] && isNearWord(current, word))
            {
                visited[word] = true;
                q.push({word, count + 1});
            }
        }
    }
    
    return 0;
}