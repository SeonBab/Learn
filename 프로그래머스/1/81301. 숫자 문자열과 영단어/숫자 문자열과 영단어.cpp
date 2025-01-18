#include <string>
#include <unordered_map>

int solution(std::string s) {
    int answer = 0;

    std::unordered_map<std::string, int> umap;

    umap.insert(std::make_pair("zero", 0));
    umap.insert(std::make_pair("one", 1));
    umap.insert(std::make_pair("two", 2));
    umap.insert(std::make_pair("three", 3));
    umap.insert(std::make_pair("four", 4));
    umap.insert(std::make_pair("five", 5));
    umap.insert(std::make_pair("six", 6));
    umap.insert(std::make_pair("seven", 7));
    umap.insert(std::make_pair("eight", 8));
    umap.insert(std::make_pair("nine", 9));

    std::string str;
    for (int i = 0; i < s.length(); ++i)
    {
        str.push_back(s[i]);

        if (std::isdigit(s[i]))
        {
            answer *= 10;
            answer += s[i] - '0';
            str = "";
            continue;
        }

        std::unordered_map<std::string, int>::iterator findIter = umap.find(str);
        if (findIter != umap.end())
        {
            answer *= 10;
            answer += findIter->second;
            str = "";
        }
    }

    return answer;
}