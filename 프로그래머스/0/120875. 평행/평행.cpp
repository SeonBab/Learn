#include <vector>
#include <cmath>

using namespace std;

bool isparallel(vector<int> p1, vector<int>p2, vector<int>p3, vector<int>p4)
{    
    return (double)(p2[1] - p1[1]) / (p2[0] - p1[0]) == 
        (double)(p4[1] - p3[1]) / (p4[0] - p3[0]);
}

int solution(vector<vector<int>> dots) {
    int answer = 0;
    
    if (isparallel(dots[0], dots[1], dots[2], dots[3]) ||
       isparallel(dots[0], dots[2], dots[3], dots[1]) ||
       isparallel(dots[0], dots[3], dots[1], dots[2]))
    {
        answer = 1;
    }
    
    return answer;
}