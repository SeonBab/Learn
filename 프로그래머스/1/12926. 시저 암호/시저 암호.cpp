#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for (int i = 0; i < s.length(); ++i)
    {
        if (' ' == s[i])
        {
            answer += ' ';
            continue;
        }
        
        char alphabet;
        
        alphabet = ('a' > s[i]) ? s[i] - 'A' : s[i] - 'a';

        
        alphabet += n;
        alphabet %= 26;
        
        answer += ('a' > s[i]) ? 'A' + alphabet : 'a' + alphabet;
    }
    
    
    return answer;
}