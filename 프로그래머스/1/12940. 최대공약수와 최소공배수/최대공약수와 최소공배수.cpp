#include <vector>

std::vector<int> solution(int n, int m) {
    std::vector<int> answer;
    
    int a = (n > m) ? n : m;
    int b = (n > m) ? m : n;
    
    while(b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    
    int gcd = a;
    
    answer.push_back(gcd);
    answer.push_back((n / gcd) * m);
    
    return answer;
}