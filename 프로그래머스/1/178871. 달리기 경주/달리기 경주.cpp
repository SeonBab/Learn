#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer(players);
    
    unordered_map<string, int> rankMap;
    
    for (int i = 0; i < players.size(); ++i)
    {
        rankMap.insert({players[i], i});
    }
    
    for (int i = 0; i < callings.size(); ++i)
    {
        string calling = callings[i];
        int rank = rankMap[calling];
        
        string temp = answer[rank];
        answer[rank] = answer[rank - 1];
        answer[rank - 1] = temp;
        
        --rankMap[calling];
        ++rankMap[answer[rank]];
    }
    
    return answer;
}