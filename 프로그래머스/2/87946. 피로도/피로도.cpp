#include <bits/stdc++.h>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0, n = dungeons.size();
    vector<int>per(n);
    iota(per.begin(),per.end(),0);
    do
    {
        int now = k, cnt = 0;
        for(int i =0; i< n;++i)
        {
            int idx = per[i];
            if(dungeons[idx][0] > now)
            {
                break;
            }
            now -= dungeons[idx][1];
            cnt++;
        }
        answer = max(answer,cnt);
    }while(next_permutation(per.begin(),per.end()));
    return answer;
}