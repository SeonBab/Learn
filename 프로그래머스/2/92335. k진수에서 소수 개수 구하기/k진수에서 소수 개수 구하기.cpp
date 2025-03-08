#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrimeNumber(long long num)
{
    if (num < 2)
    {
        return false;
    }
    
    for (long long i = 2; i * i <= num; ++i)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    
    string convertNum = "";
    while (n > 0)
    {
        convertNum += to_string(n % k);
        n /= k;
    }
    reverse(convertNum.begin(), convertNum.end());
    
    string temp = "";
    for (char c : convertNum)
    {
        if (c == '0')
        {
            if (!temp.empty() && isPrimeNumber(stoll(temp)))
            {
                ++answer;
            }
            
            temp = "";
        }
        else
        {
            temp += c;
        }
    }
    
    if (!temp.empty() && isPrimeNumber(stoll(temp)))
    {
        ++answer;
    }
    
    return answer;
}