#include <string>
#include <vector>
#include <sstream>

using namespace std;

#include <string>
#include <vector>

using namespace std;

string solution(string polynomial) {
    int first_term{}, constant_term{}, num{};
    string answer = "", str{};
    stringstream stream(polynomial);

    while (stream >> str)
    {
        if (str[0] == 'x')
        {
            ++first_term;
        }
        else if (str[str.length() - 1] == 'x')
        {
            for (int i = 0; i < str.length() - 1; ++i)
            {
                num = num * 10 + (str[i] - '0');
            }

            first_term += num;
        }
        else if (str[0] != '+')
        {
            for (int i = 0; i < str.length(); ++i)
            {
                num = num * 10 + (str[i] - '0');
            }

            constant_term += num;
        }
        num = 0;
    }

    if (first_term)
    {
        if (first_term == 1)
        {
            answer = "x";
        }
        else
        {
            answer = to_string(first_term) + "x";
        }
    }

    if (constant_term)
    {
        if (first_term)
        {
            answer += " + " + to_string(constant_term);
        }
        else
        {
            answer = to_string(constant_term);
        }
    }

    return answer;
}