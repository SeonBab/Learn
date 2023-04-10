#include <string>
#include <vector>

using namespace std;

int solution(vector<int> sides) {
    int answer = 0, largest {}, index;
    
    for (int i = 0; i < sides.size(); ++i)
    {
        answer += sides[i];
        
        if (largest < sides[i])
        {
            largest = sides[i];
        }
    }
    
    answer -= largest;
    
    if (answer > largest)
    {
        answer = 1;
    }
    else
    {
        answer = 2;
    }
    
    return answer;
}