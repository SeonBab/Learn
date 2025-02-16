#include <string>

using namespace std;

string solution(string s) {
    string answer = "";
    
    bool isCapital = true;
    
    for (int i = 0; i < s.length(); ++i)
    {   
        if (s[i] == ' ')
        {
            isCapital = true;
        }
        else
        {
            if (isCapital == true)
            {
                if ('a' <= s[i] && s[i] <= 'z')
                {
                    s[i] -= 'a' - 'A';
                }
            }
            else
            {
                if ('A' <= s[i] && s[i] <= 'Z')
                {
                    s[i] += 'a' - 'A';
                }
            }
            
            isCapital = false;
        }
        
        answer += s[i];
    }
    
    return answer;
}