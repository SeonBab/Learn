int solution(int hp) {
    int answer = 0, remainder{hp};
        
    for (int i = 5; i > 0; i -=2)
    {
        answer += remainder / i;
        
        remainder %= i;
    }
    
    return answer;
}