#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0);
    
    unordered_set<string> usedWords;
    char prev_char = words[0][0];
    
    for (int i = 0; i < words.size(); ++i)
    {
        if (usedWords.find(words[i]) != usedWords.end() ||
           prev_char != words[i][0])
        {
            answer[0] = i % n + 1;
            answer[1] = i / n + 1;
            break;
        }
        
        prev_char = words[i].back();
        usedWords.insert(words[i]);
    }

    return answer;
}