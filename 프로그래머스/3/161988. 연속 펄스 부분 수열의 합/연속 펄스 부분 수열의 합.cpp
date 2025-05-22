#include <vector>
#include <algorithm>

using namespace std;

long long maxSubsequenceSum(const vector<long long>& pulse)
{
    long long maxSum = pulse[0];
    long long currentSum = pulse[0];
    
    for (int i = 1; i < pulse.size(); ++i)
    {
        currentSum = max(pulse[i], currentSum + pulse[i]);
        maxSum = max(maxSum, currentSum);
    }
    
    return maxSum;
}

long long solution(vector<int> sequence) {
    long long answer = 0;
    
    vector<long long> pulse1(sequence.size());
    vector<long long> pulse2(sequence.size());
    
    for (int i = 0; i < sequence.size(); ++i)
    {
        pulse1[i] = sequence[i] * ((i % 2 == 0) ? 1 : -1);
        pulse2[i] = sequence[i] * ((i % 2 == 0) ? -1 : 1);
    }
    
    long long maxSum1 = maxSubsequenceSum(pulse1);
    long long maxSum2 = maxSubsequenceSum(pulse2);
    
    answer = max(maxSum1, maxSum2);
    
    return answer;
}