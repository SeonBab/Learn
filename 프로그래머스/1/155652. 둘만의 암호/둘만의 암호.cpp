#include <string>
#include <algorithm>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
        
    for (int i = 0; i < s.length(); ++i)
    {
        char CurWord = s[i];
        
        for (int j = 0; j < index; ++j)
        {
            ++CurWord;
            
            CurWord = (CurWord > 'z') ? 'a' : CurWord;
            
            for (int k = 0; k < skip.length(); ++k)
            {
                if (CurWord == skip[k])
                {
                    ++CurWord;
                    k = -1;
                    
                    CurWord = (CurWord > 'z') ? 'a' : CurWord;
                }
            }
        }
        
        answer += CurWord;
    }
    
    return answer;
}