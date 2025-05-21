#include <string>
#include <algorithm>

using namespace std;

int solution(string s)
{
    int answer = 1;
    
    int n = s.size();
    
    for (int i = 0; i < n; ++i)
    {
        int left = i;
        int right = i;
        
        while(left >= 0 && right < n && s[left] == s[right])
        {
            answer = max(answer, right - left + 1);
            
            --left;
            ++right;
        }
        
        left = i;
        right = i + 1;
        
        while (left >= 0 && right < n && s[left] == s[right])
        {
            answer = max(answer, right - left + 1);
            --left;
            ++right;
        }
    }

    return answer;
}