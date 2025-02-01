#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    vector<string> babyWords { "aya", "ye", "woo", "ma" };
    
    for (int i = 0; i < babbling.size(); ++i)
    {
        string substr;
        string prev;
        int j = 0;
        
        while (j < babbling[i].size())
        {
            bool found = false;
            for (int k = 0; k < babyWords.size(); ++k)
            {
                substr = babbling[i].substr(j, babyWords[k].length());
                
                if (substr == babyWords[k] && prev != substr)
                {
                    prev = substr;
                    substr = "";
                    j += babyWords[k].length();
                    found = true;
                }
            }
            
            if (!found)
            {
                break;
            }
        }
        
        if (substr == "")
        {
            ++answer;
        }
    }
    
    return answer;
}