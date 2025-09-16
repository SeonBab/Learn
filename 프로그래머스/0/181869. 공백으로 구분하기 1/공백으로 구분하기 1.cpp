#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    string str;
    
    for (char e : my_string)
    {
        if (e == ' ')
        {
            answer.push_back(str);
            str.clear();
            continue;
        }
        
        str.push_back(e);
    }
    
    answer.push_back(str);
    
    return answer;
}