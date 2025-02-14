#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    unordered_map<string, set<string>> reportInfoList;
    
    for (int i = 0; i < report.size(); ++i)
    {
        istringstream iss(report[i]);
        
        std::string reportSender;
        std::string reportTarget;
        
        iss >> reportSender >> reportTarget;
        
        reportInfoList[reportTarget].insert(reportSender);
    }
    
    unordered_map<string, int> reportCounts;
    
    for (auto reportInfo : reportInfoList)
    {
        if (k <= reportInfo.second.size())
        {
            for (auto reportSender : reportInfo.second)
            {
                ++reportCounts[reportSender];
            }
        }
    }
    
    for (auto id : id_list)
    {
        answer.push_back(reportCounts[id]);
    }
    
    return answer;
}