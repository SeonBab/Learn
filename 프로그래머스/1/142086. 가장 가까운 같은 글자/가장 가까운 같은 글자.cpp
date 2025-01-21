#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(s.size(), -1);
    unordered_map<char, int> lastIndex;
    
    for (int i = 0; i < s.length(); ++i)
    {
        char curChar = s[i];
        
        if (lastIndex.find(curChar) != lastIndex.end())
        {
            answer[i] = i - lastIndex[curChar];
        }
        
        lastIndex[curChar] = i;
    }
    return answer;
}