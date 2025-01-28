#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> one { 1, 2, 3, 4, 5 };
    vector<int> two { 2, 1, 2, 3, 2, 4, 2, 5 };
    vector<int> three { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    
    vector<int> Correct(3, 0);
    
    for (int i = 0; i < answers.size(); ++i)
    {
        if (answers[i] == one[i % one.size()]) ++Correct[0];
        
        if (answers[i] == two[i % two.size()]) ++Correct[1];
        
        if (answers[i] == three[i % three.size()]) ++Correct[2];
    }
    
    int highestCorrect = *(max_element(Correct.begin(), Correct.end()));
    
    for (int i = 0; i < Correct.size(); ++i)
    {
        if (highestCorrect == Correct[i])
        {
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}