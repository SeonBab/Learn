#include <vector>
#include <algorithm>

using namespace std;

vector<int> answer = {0, 0};
vector<int> discountRates = {10, 20, 30, 40};

void dfs(const vector<vector<int>>& users, const vector<int>emoticons, int index, vector<int>& discounts)
{
    int n = emoticons.size();
    
    if (index == n)
    {
        int subscriber = 0;
        int totalSale = 0;
        
        for (auto & user : users)
        {
            int minDiscount = user[0];
            int plusLimit = user[1];
            
            int purchaseAmount = 0;
            
            for(int i = 0; i < n; ++i)
            {
                if (discounts[i] >= minDiscount)
                {
                    int price = emoticons[i] * (100 - discounts[i]) / 100;
                    purchaseAmount += price;
                }
            }
            
            if (purchaseAmount >= plusLimit)
            {
                ++subscriber;
            }
            else
            {
                totalSale += purchaseAmount;
            }
        }
        
        if (subscriber > answer[0] || (subscriber == answer[0] && totalSale > answer[1]))
        {
            answer[0] = subscriber;
            answer[1] = totalSale;
        }
        
        return;
    }
    
    
    for (int rate : discountRates)
    {
        discounts[index] = rate;
        dfs(users, emoticons, index + 1, discounts);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    
    vector<int> discounts(emoticons.size(), 0);
    
    dfs(users, emoticons, 0, discounts);
    
    return answer;
}