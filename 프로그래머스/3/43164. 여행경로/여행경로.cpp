#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> answer;

void dfs(const vector<vector<string>>& tickets, vector<bool>& visited, vector<string>& path, 
         int depth, string curTicket)
{
    path.push_back(curTicket);
    
    if (depth == tickets.size())
    {
        answer = path;
        return;
    }
    else if (!answer.empty())
    {
        return;
    }
    
    for (int i = 0; i < tickets.size(); ++i)
    {
        if (!visited[i] && tickets[i][0] == curTicket)
        {
            visited[i] = true;
            
            dfs(tickets, visited, path, depth + 1, tickets[i][1]);
            
            visited[i] = false;
        }
    }
    
    path.pop_back();
}

bool compare(const vector<string>& a, const vector<string>& b)
{
    if (a[0] == b[0])
    {
        return a[1] < b[1];
    }
    
    return a[0] < b[0];
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end(), compare);
    
    vector<bool> visited(tickets.size(), false);
    vector<string> path;
    
    dfs(tickets, visited, path, 0, "ICN");
    
    return answer;
}