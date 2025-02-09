#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    
    int firstX = 50, firstY = 50;
    int lastX = 0, lastY = 0;
    
    for (int i = 0; i < wallpaper.size(); ++i)
    {
        for (int j = 0; j < wallpaper[i].length(); ++j)
        {
            if (wallpaper[i][j] == '#')
            {
                firstY = (firstY > i) ? i : firstY;
                firstX = (firstX > j) ? j : firstX;
                lastY = (lastY < i + 1) ? i + 1 : lastY;
                lastX = (lastX < j + 1) ? j + 1 : lastX;
            }
        }
    }
    
    answer.push_back(firstY);
    answer.push_back(firstX);
    answer.push_back(lastY);
    answer.push_back(lastX);
    
    return answer;
}