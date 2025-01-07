long long solution(int price, int money, int count)
{
    long long answer = -1;
    answer *= money;
    
    for (int i = 1; i <= count; ++i)
    {
        answer += i * price;
    }
    
    if (answer < 0)
    {
        answer = 0;
    }

    return answer;
}