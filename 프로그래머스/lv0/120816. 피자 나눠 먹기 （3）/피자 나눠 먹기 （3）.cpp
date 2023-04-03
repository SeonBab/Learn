int solution(int slice, int n) {
    int answer{}, i{1};
    
    while(answer == 0)
    {
        ((slice * i) / n) ? answer = i : ++i;
    }
    
    return answer;
}