#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> dots) {
    int answer = 0, w = dots[0][0], l = dots[0][1];
    bool bw {true}, bl {true};
    
    for (int i = 0; i < dots.size(); ++i)
    {
        if (w != dots[i][0] && bw)
        {
            w = abs(w - dots[i][0]);
            bw = false;
        }
        
        if (l != dots[i][1] && bl)
        {
            l = abs(l - dots[i][1]);
            bl = false;
        }
    }
    answer = w * l;
    
    return answer;
}