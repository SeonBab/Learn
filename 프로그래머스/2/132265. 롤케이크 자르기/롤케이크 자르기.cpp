#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    unordered_map<int, int> rollCake;
    unordered_map<int, int> cheolSoo;
    
    for (int e : topping)
    {
        ++rollCake[e];
    }
    
    for (int i = 0; i < topping.size(); ++i)
    {
        --rollCake[topping[i]];
        ++cheolSoo[topping[i]];
        
        if (rollCake[topping[i]] <= 0)
        {
            rollCake.erase(topping[i]);
        }
        
        if (rollCake.size() == cheolSoo.size())
        {
            ++answer;
        }
    }
    
    return answer;
}