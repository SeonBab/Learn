#include <string>
#include <vector>

using namespace std;

bool dfs(const string& tree)
{
    int length = tree.length();
    
    if (length == 1)
    {
        return true;
    }
    
    int mid = length / 2;
    char root = tree[mid];
    
    string left = tree.substr(0, mid);
    string right = tree.substr(mid + 1);
    
    bool leftValid = dfs(left);
    bool rightValid = dfs(right);
    
    if (!leftValid || !rightValid)
    {
        return false;
    }
    
    if (root == '0')
    {
        if (left.find('1') != string::npos || right.find('1') != string::npos)
        {
            return false;
        }
    }
    
    return true;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for (long long number : numbers)
    {
        string binary = "";
        while (number > 0)
        {
            binary = to_string(number % 2) + binary;
            number /= 2;
        }
        
        int h = 0;
        while ((1 << h) - 1 < binary.length())
        {
            ++h;
        }
        
        int length = (1 << h) - 1;
        binary = string(length - binary.length(), '0') + binary;
        
        bool result = dfs(binary);
        answer.push_back((result) ? 1 : 0);
    }
    
    return answer;
}