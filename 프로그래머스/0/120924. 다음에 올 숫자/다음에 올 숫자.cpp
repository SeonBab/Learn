#include <vector>

using namespace std;

int solution(vector<int> common) {
    int answer = 0;
    
    int n = common.size();
    
    int a = common[0];
    int b = common[1];
    int c = common[2];
    
    int different = b - a;
    
    if (c - b == different)
    {
        answer = common[n - 1] + different;
    }
    else
    {
        answer = common[n - 1] * b / a;
    }
    
    return answer;
}