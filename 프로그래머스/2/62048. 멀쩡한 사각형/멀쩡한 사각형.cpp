int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    
    return gcd(b, a % b);
}

long long solution(int w,int h) {
    long long answer = 1;
    
    answer = static_cast<long long>(w) * static_cast<long long>(h) - (w + h - gcd(w, h));
    
    return answer;
}