#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 1;
    
    int rollerStart = section[0];
    
    for (int i = 1; i < section.size(); ++i)
    {   
        if (section[i] - rollerStart >= m)
        {
            rollerStart = section[i];
            ++answer;
        }
    }
    
    return answer;
}