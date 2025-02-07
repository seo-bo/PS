#include <bits/stdc++.h>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    int n = friends.size();
    map<string,int>mm;
    for(int i =0; i<n;++i)
    {
        mm[friends[i]] =i;
    }
    vector<int>cost(n, 0);
    vector<vector<int>>v(n,vector<int>(n,0));
    for(auto & i : gifts)
    {
        stringstream ss(i);
        string str;
        vector<string>ok;
        while(ss >> str)
        {
            ok.push_back(str);
        }
        int a = mm[ok[0]];
        int b = mm[ok[1]];
        v[a][b]++;
        v[b][a]--;
        cost[a]++;
        cost[b]--;
    }
    for(int i =0; i<n;++i)
    {
        int temp = 0;
        for(int j =0; j<n;++j)
        {
            if(i == j)
            {
                continue;
            }
            if(v[i][j] == 0)
            {
                if (cost[i] > cost[j])
                {
                    temp++;
                }
            }
            else if(v[i][j] > 0)
            {
                temp++;
            }
        }
        answer = max(answer,temp);
    }
    return answer;
}