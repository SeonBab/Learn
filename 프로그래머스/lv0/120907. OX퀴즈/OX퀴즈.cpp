#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> quiz) {
    vector<string> answer;

    int left, right, quizResult;
    char op, eq;
    stringstream ss;

    for (int i = 0; i < quiz.size(); ++i)
    {
        int left, right, quizResult;
        char op, eq;
        
        ss.str(quiz[i]);

        ss >> left >> op >> right >> eq >> quizResult;

        if (op == '+')
        {
            if (left + right == quizResult)
            {
                answer.push_back("O");
            }
            else
            {
                answer.push_back("X");
            }
        }
        else
        {
            if (left - right == quizResult)
            {
                answer.push_back("O");
            }
            else
            {
                answer.push_back("X");
            }
        }
        
        ss.clear();
    }
    return answer;
}