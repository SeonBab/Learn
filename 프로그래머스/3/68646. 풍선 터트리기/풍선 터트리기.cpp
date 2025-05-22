#include <string>
#include <algorithm>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    
    int n = a.size();
    
    vector<int> leftMin(n);
    vector<int> rightMin(n);
    
    leftMin[0] = a[0];
    for (int i = 1; i < n; ++i)
    {
        leftMin[i] = min(leftMin[i - 1], a[i]);
    }
    
    rightMin[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; --i)
    {
        rightMin[i] = min(rightMin[i + 1], a[i]);
    }
    
    for (int i = 0; i < n; ++i)
    {
        if (a[i] <= leftMin[i] || a[i] <= rightMin[i])
        {
            ++answer;
        }
    }
    
    return answer;
}