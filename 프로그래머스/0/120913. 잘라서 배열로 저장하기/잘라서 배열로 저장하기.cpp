#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_str, int n) {
    vector<string> answer;
    string str{};

    for (int i = 0; i < my_str.length(); ++i)
    {
        if (i != 0 && i % n == 0)
        {
            answer.push_back(str);
            str = "";
        }

        str += my_str[i];
    }
    
    answer.push_back(str);

    return answer;
}