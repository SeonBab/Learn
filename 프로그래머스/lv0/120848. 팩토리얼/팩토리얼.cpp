int solution(int n) {
    int answer = 1, i {};
    
    while (++i)
    {
        answer *= i;
        
        if (answer > n)
        {
            answer = i - 1;
            break;
        }
        else if (answer == n)
        {
            answer = i;
            break;
        }
    }
    return answer;
}