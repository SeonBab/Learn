#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    vector<string> babyWords { "aya", "ye", "woo", "ma" };
    
    for (int i = 0; i < babbling.size(); ++i)
    {
        string substr;
        string found;
        
        for (int j = 0; j < babbling[i].size(); ++j)
        {
            substr += babbling[i][j];
            
            for (int k = 0; k < babyWords.size(); ++k)
            {
                
                if (substr == babyWords[k] && substr != found)
                {
                    found = substr;
                    substr = "";
                }
            }
        }
        
        if (substr == "")
        {
            ++answer;
        }
    }
    
    return answer;
}