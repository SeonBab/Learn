int GetOneCount(int targetNumber)
{
    int count = 0;
    
    while (targetNumber != 0)
    {
        if (targetNumber % 2 == 1)
        {
            ++count;
        }
        
        targetNumber /= 2;
    }
    
    return count;
}

int solution(int n) {
    int answer = n + 1;
    
    int oneCount = GetOneCount(n);
    
    while (true)
    {
        if (GetOneCount(answer) == oneCount)
        {
            break;
        }
        
        ++answer;
    }
    
    return answer;
}