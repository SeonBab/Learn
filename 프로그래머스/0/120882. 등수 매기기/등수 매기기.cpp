#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<vector<int>> score) {
    vector<int> answer;
    
    vector<float> averages;
    for (int i = 0; i < score.size(); ++i)
    {
        float average = (score[i][0] + score[i][1]) / 2.f;
        averages.push_back(average);
    }
    
    vector<float> sortAverages = averages;
    sort(sortAverages.begin(), sortAverages.end(), greater<float>());
    
    for (int i = 0; i < score.size(); ++i)
    {
        auto it = find(sortAverages.begin(), sortAverages.end(), averages[i]);
        answer.push_back(distance(sortAverages.begin(), it) + 1);
    }
    
    return answer;
}