#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

void distributeProfit(int sellerIndex, int profit, const vector<int>& referral, vector<int>& answer)
{
    if (profit < 1 || sellerIndex == -1)
    {
        return;
    }
    
    int commission = profit / 10;
    answer[sellerIndex] += profit - commission;
    distributeProfit(referral[sellerIndex], commission, referral, answer);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    
    unordered_map<string, int> nameToIndex;
    
    int n = enroll.size();
    
    for (int i = 0; i < n; ++i)
    {
        nameToIndex[enroll[i]] = i;
    }
    
    vector<int> referralIndex(n);
    for (int i = 0; i < n; ++i)
    {
        referralIndex[i] = (referral[i] == "-") ? -1 : nameToIndex[referral[i]];
    }
    
    answer.resize(n, 0);
    for (int i = 0; i < seller.size(); ++i)
    {
        int sellerIndex = nameToIndex[seller[i]];
        int profit = amount[i] * 100;
        distributeProfit(sellerIndex, profit, referralIndex, answer);
    }
    
    return answer;
}