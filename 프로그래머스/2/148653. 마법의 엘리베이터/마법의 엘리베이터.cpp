int solution(int storey) {
    int answer = 0;
    
    while(storey != 0)
    {
        int digitNum = storey % 10;
        
        if (digitNum > 5)
        {
            answer += 10 - digitNum;
            storey += 10;
        }
        else if (digitNum < 5)
        {
            answer += digitNum;
        }
        else
        {
            answer += 5;
            
            int nextNum = (storey / 10) % 10;
            if (nextNum >= 5)
            {
                storey += 10;
            }
        }
        
        storey /= 10;
    }
    
    return answer;
}