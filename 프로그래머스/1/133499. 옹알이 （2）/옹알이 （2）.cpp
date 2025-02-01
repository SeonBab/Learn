#include <string>
#include <vector>

using namespace std;

vector<string> babyWords { "aya", "ye", "woo", "ma" };

bool canPronounce(string& babbling)
{
    bool found = true;
    string prev;
    int j = 0;
        
    while (j < babbling.length())
    {
        for (int k = 0; k < babyWords.size(); ++k)
        {
            string substr = babbling.substr(j, babyWords[k].length());
                
            if (substr == prev)
            {
                return false;
            }
                
            if (substr == babyWords[k])
            {
                found = true;
                prev = substr;
                j += babyWords[k].length();
                break;
            }
            else
            {
                found = false;
            }
        }
            
        if (!found)
        {
           return false;
        }
    }
    
    return found;
}

int solution(vector<string> babbling) {
    int answer = 0;
    
    for (int i = 0; i < babbling.size(); ++i)
    {
        if (canPronounce(babbling[i]))
        {
            ++answer;
        }
    }
    
    return answer;
}