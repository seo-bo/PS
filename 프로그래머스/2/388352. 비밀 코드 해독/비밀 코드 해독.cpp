#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;
    int len = ans.size();
    for(int i =0; i<(1<<n);++i)
    {
        if(__builtin_popcount(i) != 5)
        {
            continue;
        }
        auto cal = [&] (int mask)
        {
            int temp = 0;
            for(int j =0; j<len;++j)
            {
                int temp = 0;
                for(auto & k : q[j])
                {
                    if(mask & (1<<(k-1)))
                    {
                        temp++;
                    }       
                }
                if(temp != ans[j])
                {
                    return false;
                }
            }
            return true;
        };
        answer += cal(i);
    }
    return answer;
}