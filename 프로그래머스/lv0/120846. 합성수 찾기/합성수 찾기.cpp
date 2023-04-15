int solution(int n) {
    int answer = 0;
    
    for (int i = 4; i <= n; ++i)
    {
        for (int j = 2; j < i; ++j)
        {
            if (!(i % j))
            {
                answer++;
                break;
            }
        }
    }
    return answer;
}