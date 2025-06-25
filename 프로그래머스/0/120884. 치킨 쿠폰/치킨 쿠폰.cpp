int solution(int chicken) {
    int answer = 0;
    
    while (chicken / 10)
    {
        answer += chicken / 10;
        
        int temp = chicken % 10;
        chicken /= 10;
        chicken += temp;
    }
    
    return answer;
}