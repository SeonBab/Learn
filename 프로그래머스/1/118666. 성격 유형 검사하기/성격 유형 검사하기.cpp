#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    int score[7] {3, 2, 1, 0, 1, 2, 3};
    unordered_map<char, int> totalScores;
    
    for (int i = 0; i < survey.size(); ++i)
    {
        int choice = choices[i] - 1;
        int choiceScore = score[choice];
        
        if (choice < 3)
        {
            char typeA = survey[i][0];
            totalScores[typeA] += choiceScore;
        }
        else if (choice > 3)
        {
            char typeB = survey[i][1];
            totalScores[typeB] += choiceScore;
        }
        
    }
    
    answer += (totalScores['R'] >= totalScores['T']) ? 'R' : 'T';
    answer += (totalScores['C'] >= totalScores['F']) ? 'C' : 'F';
    answer += (totalScores['J'] >= totalScores['M']) ? 'J' : 'M';
    answer += (totalScores['A'] >= totalScores['N']) ? 'A' : 'N';
    
    return answer;
}