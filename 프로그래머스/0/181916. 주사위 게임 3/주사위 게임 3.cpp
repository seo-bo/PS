#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(int a, int b, int c, int d) {
    int answer = 0;
    map<int,int>mm;
    mm[a]++,mm[b]++,mm[c]++,mm[d]++;
    if(mm.size() == 4)
    {
        return mm.begin()->first;
    }
    else if(mm.size() == 3)
    {
        int p = 1;
        for(auto & [i,j] : mm)
        {
            if(j == 2)
            {
                continue;
            }
            p *= i; 
        }
        return p;
    }
    else if(mm.size() == 2)
    {
        int p = mm.begin()->second;
        if(p == 2)
        {
            int aa = mm.begin()->first;
            int bb = next(mm.begin())->first;
            return (aa + bb) * abs(aa - bb);
        }
        else
        {
            if(p == 1)
            {
                int pp = (10 * next(mm.begin())->first + mm.begin()->first);
                return pp * pp;
            }
            else
            {
                int pp = (10 * mm.begin()->first + next(mm.begin())->first);
                return pp * pp;
            }
        }
    }
    else
    {
        return 1111 * mm.begin()->first;
    }
    return answer;
}