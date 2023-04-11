#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

map<string, char> mp;
string arr[26] = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };


string solution(string letter) {
    string answer = "", str = "";
    stringstream ss(letter);

    for (int i = 0; i < sizeof(arr)/sizeof(*arr); ++i)
    {
        mp[arr[i]] = 'a' + i;
    }

    while (ss >> str)
    {
        answer += mp[str];
    }

    return answer;
}