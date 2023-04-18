#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int chek {};

    for (char i = 'a'; i <= 'z'; ++i)
    {
        for (int j = 0; j < s.length(); ++j)
        {
            if (i == s[j])
            {
                ++chek;
            }
        }
        
        if (chek == 1)
        {
            answer.push_back(i);
        }
        
        chek = 0;
    }
    return answer;
}