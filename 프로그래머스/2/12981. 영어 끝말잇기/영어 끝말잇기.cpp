#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    set<string>s;
    vector<int>sw = {0,0};
    int cnt = 1, idx = 0, m = 0,len = words.size();
    while(m < len)
    {
        if(s.find(words[m]) != s.end() || (m > 0 && words[m-1].back() != words[m].front()))
        {
            sw[0] = idx + 1;
            sw[1] = cnt;
            return sw;
        }
        s.insert(words[m]);
        idx = (idx + 1) % n;
        if(!idx)
        {
            cnt++;
        }
        m++;
    }
    return sw;
}