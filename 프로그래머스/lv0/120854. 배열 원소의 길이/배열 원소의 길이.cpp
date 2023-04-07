#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> strlist) {
    vector<int> answer(strlist.size(), 0);

    for (int i = 0; i < strlist.size(); ++i)
    {
        for (int j = 0; j < strlist[i].size(); ++j)
        {
            ++answer[i];
        }
    }

    return answer;
}