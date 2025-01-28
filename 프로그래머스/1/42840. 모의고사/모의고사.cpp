#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> one { 1, 2, 3, 4, 5 };
    vector<int> two { 2, 1, 2, 3, 2, 4, 2, 5 };
    vector<int> three { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    
    int isOneCorrect = 0;
    int isTwoCorrect = 0;
    int isThreeCorrect = 0;
    
    for (int i = 0; i < answers.size(); ++i)
    {
        isOneCorrect += (answers[i] == one[i % one.size()]) ? 1 : 0;
        
        isTwoCorrect += (answers[i] == two[i % two.size()]) ? 1 : 0;
        
        isThreeCorrect += (answers[i] == three[i % three.size()]) ? 1 : 0;
    }
    
    int highestCorrect = (isOneCorrect > isTwoCorrect) ? isOneCorrect : isTwoCorrect;
    highestCorrect = (highestCorrect > isThreeCorrect) ? highestCorrect : isThreeCorrect;
        
    if (highestCorrect == isOneCorrect)
    {
        answer.push_back(1);
    }
    if (highestCorrect == isTwoCorrect)
    {
        answer.push_back(2);
    }
    if (highestCorrect == isThreeCorrect)
    {
        answer.push_back(3);
    }
    
    return answer;
}