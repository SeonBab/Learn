#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    multiset<int> ms;
    
    for(auto& oper : operations)
    {
        if (oper[0] == 'I')
        {
            int num = stoi(oper.substr(2));
            ms.insert(num);
        }
        else if (!ms.empty())
        {
            if (oper[2] == '1')
            {
                auto it = prev(ms.end());
                ms.erase(it);
            }
            else
            {
                ms.erase(ms.begin());
            }
        }
    }
    
    if (ms.empty())
    {
        return {0, 0};
    }
    
    answer.push_back(*prev(ms.end()));
    answer.push_back(*ms.begin());
    
    return answer;
}