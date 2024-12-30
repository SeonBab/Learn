int solution(int num) {
    int answer = -1;
    long long n = num;
    
    for (int i = 0; i < 500; ++i)
    {   
        if (1 == n)
        {
            answer = i;
            break;
        }

        n = (0 == n % 2) ? n / 2 : n * 3 + 1;
    }
    
    return answer;
}