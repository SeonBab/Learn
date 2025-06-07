#include <string>
#include <vector>

using namespace std;

pair<int, int> parent[51][51];
string table[51][51];

pair<int, int> find(int r, int c)
{
    if (parent[r][c] == make_pair(r, c))
    {
        return {r, c};
    }
    
    return parent[r][c] = find(parent[r][c].first, parent[r][c].second);
}

void init()
{
    for (int r = 1; r <= 50; ++r)
    {
        for (int c = 1; c <= 50; ++c)
        {
            parent[r][c] = {r, c};
            table[r][c] = "";
        }
    }
}

void merge(int r1, int c1, int r2, int c2)
{
    pair<int, int> p1 = find(r1, c1);
    pair<int, int> p2 = find(r2, c2);
    
    if (p1 == p2)
    {
        return;
    }
    
    string& v1 = table[p1.first][p1.second];
    string& v2 = table[p2.first][p2.second];
    
    parent[p2.first][p2.second] = p1;
    
    for (int r = 1; r <= 50; ++r)
    {
        for (int c = 1; c <= 50; ++c)
        {
            if (find(r, c) == p2)
            {
                parent[r][c] = p1;
            }
        }
    }
    
    if (v1.empty())
    {
        v1 = v2;
    }
}

void unmerge(int r, int c)
{
    pair<int, int> root = find(r, c);
    
    string cellValue = table[root.first][root.second];
    
    for (int i = 1; i <= 50; ++i)
    {
        for (int j = 1; j <= 50; ++j)
        {
            if (find(i, j) == root)
            {
                parent[i][j] = {i, j};
                table[i][j] = "";
            }
        }
    }
    
    table[r][c] = cellValue;
}

void updateCell(int r, int c, const string& value)
{
    auto p = find(r, c);
    table[p.first][p.second] = value;
}

void updateValue(const string& from, const string& to)
{
    for (int r = 1; r <= 50; ++r)
    {
        for (int c = 1; c <= 50; ++c)
        {
            pair<int, int> p = find(r, c);
            
            if (table[p.first][p.second] == from)
            {
                table[p.first][p.second] = to;
            }
        }
    }
}

string printCell(int r, int c)
{
    pair<int, int> p = find(r, c);
    
    string& value = table[p.first][p.second];
    
    return (value.empty()) ? "EMPTY" : value;
}

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    
    init();
    
    for (const string& command : commands)
    {
        vector<string> tokens;
        
        string token;
        
        for (char e : command)
        {
            if (e == ' ')
            {
                tokens.push_back(token);
                token.clear();
            }
            else
            {
                token += e;
            }
        }
        
        tokens.push_back(token);
        
        if (tokens[0] == "UPDATE")
        {
            if (tokens.size() == 4)
            {
                int r = stoi(tokens[1]);
                int c = stoi(tokens[2]);
                
                string value = tokens[3];
                
                updateCell(r, c, value);
            }
            else
            {
                updateValue(tokens[1], tokens[2]);
            }
        }
        else if (tokens[0] == "MERGE")
        {
            int r1 = stoi(tokens[1]);
            int c1 = stoi(tokens[2]);
            
            int r2 = stoi(tokens[3]);
            int c2 = stoi(tokens[4]);
            
            merge(r1, c1, r2, c2);
        }
        else if (tokens[0] == "UNMERGE")
        {
            int r = stoi(tokens[1]);
            int c = stoi(tokens[2]);
            
            unmerge(r, c);
        }
        else if (tokens[0] == "PRINT")
        {
            int r = stoi(tokens[1]);
            int c = stoi(tokens[2]);
            
            answer.push_back(printCell(r, c));
        }
    }
    
    return answer;
}