#include <vector>

int solution(std::vector<std::vector<int>> sizes) {
    int answer = 0;
    int x = 0;
    int y = 0;
    
    for (int i = 0; i < sizes.size(); ++i)
    {
        int w = (sizes[i][0] > sizes[i][1]) ? sizes[i][0] : sizes[i][1];
        int h = (sizes[i][0] > sizes[i][1]) ? sizes[i][1] : sizes[i][0];
        
        x = (x > w) ? x : w;
        y = (y > h) ? y : h;
    }
    
    answer = x * y;
    
    return answer;
}