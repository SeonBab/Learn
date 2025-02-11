#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;

    unordered_map<char, int> termMap;

    for (string term : terms)
    {
        istringstream iss(term);

        char termChar = 0;
        int termMonth = 0;

        iss >> termChar >> termMonth;

        termMap[termChar] = termMonth * 28;
    }
    

    int todaytoInt = 0;
    todaytoInt += stoi(today.substr(0, 4)) * 12 * 28;
    todaytoInt += stoi(today.substr(5, 2)) * 28;
    todaytoInt += stoi(today.substr(8));
    
    
    for (int i = 0; i < privacies.size(); ++i)
    {
        int privacytoInt = 0;
        privacytoInt += stoi(privacies[i].substr(0, 4)) * 12 * 28;
        privacytoInt += stoi(privacies[i].substr(5, 2)) * 28;
        privacytoInt += stoi(privacies[i].substr(8));
        
        char privacyChar = privacies[i][11];
        
        if (todaytoInt >= privacytoInt + termMap[privacyChar])
        {
            answer.push_back(i + 1);
        }
    }

    return answer;
}