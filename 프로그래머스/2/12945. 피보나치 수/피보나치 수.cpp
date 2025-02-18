int solution(int n) {
    int sum = 0;
    int prev1 = 0;
    int prev2 = 1;
    
    for (int i = 2; i <= n; i++)
    {
        sum = (prev1 + prev2) % 1234567;
        prev1 = prev2;
        prev2 = sum;
    }
    
    return prev2;
}