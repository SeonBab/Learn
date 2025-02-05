#include <string>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    char key = 0;
    int xCount = 0;
    int otherCount = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        if (key == 0)
        {
            key = s[i];
        }
        
        (key == s[i]) ? ++xCount : ++otherCount;
        
        if (xCount == otherCount)
        {
            ++answer;
            key = 0;
            xCount = 0;
            otherCount = 0;
        }
    }
    
    if (key != 0)
    {
        ++answer;
    }
    
    return answer;
}