#include <string>
#include <vector>

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {

    if (array.size() == 1)
    {
        return array[0];
    }

    int answer{}, mode{}, index{};
    int ary[1001]{};

    for (int i = 0; i < array.size(); ++i)
    {
        ary[array[i]]++;
    }

    for (int i = 0; i < 1001; ++i)
    {
        if (mode < ary[i])
        {
            mode = ary[i];
            index = i;
        }
    }

    for (int i = 0; i < 1001; ++i)
    {
        if (index != i && ary[i] == mode)
        {
            return -1;
        }
    }

        return answer = index;
}