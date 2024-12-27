bool solution(int x) {
    bool answer = true;
    
    int num = x;
    int digitSum = 0;
    
    while (num)
    {
        digitSum += num % 10;
        num /= 10;
    }
    
    (x % digitSum == 0) ? answer = true : answer = false;
    
    return answer;
}