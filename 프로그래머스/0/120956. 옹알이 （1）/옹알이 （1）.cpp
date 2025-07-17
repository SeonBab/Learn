#include <string>
#include <vector>

using namespace std;

vector<string> str = { "aya", "ye", "woo", "ma" };

bool isValidWord(string babble)
{
    string lastword;
    
    for (int i = 0; i < babble.size(); ++i)
    {
        bool isMatch = false;
        
        for (int j = 0; j < str.size(); ++j)
        {
            string word = str[j];
            if (babble.substr(i, word.size()) == str[j] && lastword != word)
            {
                i += word.size() - 1;
                lastword = word;
                isMatch = true;
                break;
            }
        }
        
        if (!isMatch)
        {
            return false;
        }
    }
    
    return true;
}

int solution(vector<string> babbling) {
    int answer = 0;
    
    for (int i = 0; i < babbling.size(); ++i)
    {
        if (isValidWord(babbling[i]))
        {
            ++answer;
        }
    }

    return answer;
}