#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer;
    answer = my_string[0];
    bool check = true;
    
    for (int i = 0; i < my_string.size(); ++i)
    {
        check = true;
        
        for (int j = 0; j < answer.size(); ++j)
        {
            if (my_string[i] == answer[j])
            {
                check = false;
            }
        }
        
        if (check)
        {
            answer += my_string[i];
        }
    }
    
    return answer;
}