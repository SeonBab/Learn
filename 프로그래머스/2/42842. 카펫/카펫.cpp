#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int total = brown + yellow;
    
    for (int height = 3; height * height <= total; ++height)
    {
        if (total % height == 0)
        {
            int width = total / height;
            
            if ((2 * width) + (2 * height) - 4 == brown)
            {
                answer.push_back(width);
                answer.push_back(height);
                break;
            }
        }
    }
    
    return answer;
}