#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_str, int n) {
    vector<string> answer;
    string subString;
    
    for (int i = 0; i < my_str.size(); ++i)
    {
        if (i != 0 && i % n == 0)
        {
            answer.push_back(subString);
            subString.clear();
        }
        
        subString.push_back(my_str[i]);
    }
    
    answer.push_back(subString);
    
    return answer;
}