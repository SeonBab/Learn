long long solution(int n) {
    long long answer = 0;

    if (n == 1) return 1;
    if (n == 2) return 2;
    
    int prev1 = 2;
    int prev2 = 1;
    for (int i = 3; i <= n; ++i)
    {
        answer = (prev1 + prev2) % 1234567;
        prev2 = prev1;
        prev1 = answer;
    }
    
    return answer;
}