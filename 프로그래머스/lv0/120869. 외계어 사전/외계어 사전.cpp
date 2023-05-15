#include <string>
#include <vector>

using namespace std;

int solution(vector<string> spell, vector<string> dic) {
    int answer = 2, count{};
    vector<string> str;

    for (int i = 0; i < dic.size(); ++i)
    {
        str = spell;
        count = 0;

        for (int j = 0; j < dic[i].length(); ++j)
        {
            for (int k = 0; k < spell.size(); ++k)
            {
                if (str[k][0] == dic[i][j])
                {
                    str[k] = ' ';
                    ++count;
                }

            }
        }

        if (count == dic[i].length() && spell.size() == dic[i].length())
        {
            answer = 1;
        }
    }
    return answer;
}