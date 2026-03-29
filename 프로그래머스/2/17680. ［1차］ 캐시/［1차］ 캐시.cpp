#include <string>
#include <vector>
#include <list>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    if (cacheSize == 0)
    {
        return cities.size() * 5;
    }
    
    int answer = 0;
    
    list<string> cacheList;

    unordered_map<string, list<string>::iterator> cacheMap;
    
    for (auto city : cities)
    {
        transform(city.begin(), city.end(), city.begin(), 
                  [](unsigned char c) { return tolower(c); });
        
        if (cacheMap.find(city) != cacheMap.end())
        {
            answer += 1;

            cacheList.erase(cacheMap[city]);
        }
        else
        {
            answer += 5;
            
            if (cacheList.size() >= cacheSize)
            {
                string oldCache = cacheList.front();
                cacheList.pop_front();

                cacheMap.erase(oldCache);
            }
        }
        
        cacheList.push_back(city);
        
        cacheMap[city] = prev(cacheList.end());
    }
    
    return answer;
}