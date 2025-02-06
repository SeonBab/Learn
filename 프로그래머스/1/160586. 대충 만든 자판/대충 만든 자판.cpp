#include <string>
#include <vector>

#include <iostream>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer(targets.size());
    
    for(int i = 0; i < targets.size(); ++i)
    {
        for (int j = 0; j < targets[i].size(); ++j)
        {
            int keyIndex = 101;
            for (auto key : keymap)
            {
                int CurkeyIndex = key.find(targets[i][j]);
                
                if (CurkeyIndex != string::npos)
                {
                    keyIndex = (CurkeyIndex < keyIndex) ? CurkeyIndex : keyIndex;
                }
            }
            
            if (keyIndex != 101)
            {
                answer[i] += keyIndex + 1;
            }
            else
            {
                answer[i] = -1;
                break;
            }
        }
    }
    
    return answer;
}