long long solution(int price, int money, int count)
{
    long long answer = -1;
    
    long long totalCost = static_cast<long long>(price) * count * (count + 1) / 2;
    
    answer = totalCost - money;
    
    if (answer < 0)
    {
        answer = 0;
    }

    return answer;
}