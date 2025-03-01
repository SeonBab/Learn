#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    unordered_map<string, int> wantMap;
    unordered_map<string, int> discountMap;
    
    for (int i = 0; i < want.size(); ++i)
    {
        wantMap[want[i]] = number[i];
    }
    
    for (int i = 0; i < 10 && i < discount.size(); ++i)
    {
        ++discountMap[discount[i]];
    }
    
    if (discountMap == wantMap)
    {
        ++answer;
    }
    
    for (int i = 10; i < discount.size(); ++i)
    {        
        --discountMap[discount[i - 10]];
        
        if (discountMap[discount[i - 10]] == 0)
        {
            discountMap.erase(discount[i - 10]);
        }
        
        ++discountMap[discount[i]];
        
        if(discountMap == wantMap)
        {
            ++answer;
        }
    }
    
    return answer;
}