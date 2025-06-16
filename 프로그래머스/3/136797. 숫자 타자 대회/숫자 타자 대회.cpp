#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

pair<int, int> getPos(int num)
{
    if (num == 0)
    {
        return {3, 1};
    }
    
    return {(num - 1) / 3, (num - 1) % 3};
}

int getCost(int from, int to)
{
    if (from == to)
    {
        return 1;
    }
    
    auto [r1, c1] = getPos(from);
    auto [r2, c2] = getPos(to);
    
    int rowDiff = abs(r1 - r2);
    int colDiff = abs(c1 - c2);
    int diagonalMoves = min(rowDiff, colDiff);
    int straightMoves = max(rowDiff, colDiff) - diagonalMoves;
    
    return 3 * diagonalMoves + 2 * straightMoves;
}

int dfs(const string& numbers, int index, int left, int right, vector<vector<vector<int>>>& dp)
{
    if (index == numbers.size())
    {
        return 0;
    }
    
    int& cachedDPValue = dp[index][left][right];
    
    if (cachedDPValue != INT_MAX)
    {
        return cachedDPValue;
    }
    
    int num = numbers[index] - '0';
    
    if (num != right)
    {
        int leftCost = getCost(left, num);
        int resLeft = dfs(numbers, index + 1, num, right, dp);
        if (resLeft != INT_MAX)
        {
            cachedDPValue = min(cachedDPValue, leftCost + resLeft);
        }
    }
    
    if (num != left)
    {
        int rightCost = getCost(right, num);
        int resRight = dfs(numbers, index + 1, left, num, dp);
        if (resRight != INT_MAX)
        {
            cachedDPValue = min(cachedDPValue, rightCost + resRight);
        }
    }
    
    return cachedDPValue;
}

int solution(string numbers) {
    vector<vector<vector<int>>> dp(numbers.size() + 1, vector<vector<int>>(11, vector<int>(11, INT_MAX)));
    
    return dfs(numbers, 0, 4, 6, dp);
}