#include <vector>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    
    vector<int> collatzSequence;
    
    collatzSequence.push_back(k);
    
    while(k != 1)
    {
        if (k % 2 == 0)
        {
            k /= 2;
        }
        else
        {
            k = k * 3 + 1;
        }
        
        collatzSequence.push_back(k);
    }
    
    int n = collatzSequence.size();
    
    vector<double> areas(n - 1);
    
    for (int i = 0; i < n - 1; ++i)
    {
        areas[i] = (collatzSequence[i] + collatzSequence[i + 1]) / 2.0;
    }
    
    for (const auto& range : ranges)
    {
        int start = range[0];
        int end = (n - 1) + range[1];
        
        if (start > end)
        {
            answer.push_back(-1.0);
        }
        else
        {
            double area = 0;
            for (int i = start; i < end; ++i)
            {
                area += areas[i];
            }
            
            answer.push_back(area);
        }
    }
    
    return answer;
}