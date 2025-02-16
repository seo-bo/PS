#include <string>
#include <vector>
#include <deque>
#include <map>
#include <iostream>
using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    map<string,int>v1, v2;
    int alen = str1.size(), blen = str2.size();
    for(int i = 0; i< alen-1;++i)
    {
        if(isalpha(str1[i]) && isalpha(str1[i+1]))
        {
            string temp = "";
            temp += tolower(str1[i]);
            temp += tolower(str1[i+1]);
            v1[temp]++;
        }
    }
    for(int i = 0; i< blen-1;++i)
    {
        if(isalpha(str2[i]) && isalpha(str2[i+1]))
        {
            string temp = "";
            temp += tolower(str2[i]);
            temp += tolower(str2[i+1]);
            v2[temp]++;
        }
    }
    int a1 = 0, a2 = 0;
    for(auto & [a,b] : v1)
    {
        if(v2.find(a) != v2.end())
        {
            a1 += min(b,v2[a]);
        }
        a2 += max(b,v2[a]);
    }
     for(auto & [a,b] : v2)
    {
        if(v1.find(a) == v1.end())
        {
            a2 += b;
        }
    }
    if(a2 == 0)
    {
        return 65536;
    }
    return int((double)a1 / a2 * 65536);
}