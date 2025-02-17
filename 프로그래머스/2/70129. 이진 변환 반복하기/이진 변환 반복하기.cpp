#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2);
    
    while (1 < s.length())
    {
        int zeroCount = 0;
        string substr;
        
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '1')
            {
                substr += s[i];
            }
            else
            {
                ++zeroCount;
            }
        }
        
        int strSize = substr.length();
        s = "";
        
        while (strSize != 0)
        {
            s += (strSize % 2 == 1) ? '1' : '0';
            
            strSize /= 2;
        }
        
        ++answer[0];
        answer[1] += zeroCount;
    }
    
    return answer;
}