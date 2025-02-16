#include <bits/stdc++.h>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0, n = cities.size();
    map<string,int>used;
    map<int,string>ok;
    for(int i =0; i<n;++i)
    {
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
        string str = cities[i];
        if(used.find(str) == used.end())
        {
            answer += 5;
            if(used.size() == cacheSize && cacheSize)
            {
                string temp = ok.begin()->second;
                int t = used[temp];
                used.erase(temp);
                ok.erase(t);
            }
            if(used.size() < cacheSize)
            {
                used[str] = i +1;
                ok[i+1] = str;
            }
        }
        else
        {
            answer++;
            int temp = used[str];
            ok.erase(temp);
            ok[i+1] = str;
            used[str] = i +1;
        }
    }
    return answer;
}