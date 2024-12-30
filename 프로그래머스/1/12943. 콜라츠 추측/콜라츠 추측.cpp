int solution(int num) {
    int answer = 0;
    
    for (int i = 0; i <= 500; ++i)
    {   
        if (1 == num)
        {
            answer = i;
            break;
        }
        else if (500 == i)
        {
            answer = -1;
        }
        
        if (0 == num % 2)
        {
            num /= 2;
        }
        else if (1 == num % 2)
        {
            num = num * 3 + 1;
        }
    }
    
    return answer;
}