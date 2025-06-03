#include <vector>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    int answer = 0;
    
    if (N == number)
    {
        return 1;
    }
    
    vector<unordered_set<int>> dp(9);
    
    for (int i = 1; i <= 8; ++i)
    {
        int num = 0;
        
        for (int j = 0; j < i; ++j)
        {
            num = num * 10 + N;
        }
        
        dp[i].insert(num);
        
        for (int j = 1; j < i; ++j)
        {
            for (int a : dp[j])
            {
                for (int b : dp[i - j])
                {
                    dp[i].insert(a + b);
                    dp[i].insert(a - b);
                    dp[i].insert(a * b);
                    
                    if (b != 0)
                    {
                        dp[i].insert(a / b);
                    }
                }
            }
        }
        
        if (dp[i].count(number))
        {
            return i;
        }
    }
    
    return -1;
}