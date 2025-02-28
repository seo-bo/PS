#include <bits/stdc++.h>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    vector<vector<int>>v(w);
    int base = 1, pivot = -1,d = 1, idx = 0;
    while (base <= n)
    {
        v[idx].push_back(base);
        if (base == num)
        {
            pivot = idx;
        }
        base++;
        idx += d;
        if(idx == w)
        {
            d = -1;
            idx = w-1;
        }
        else if(idx == -1)
        {
            d = 1;
            idx = 0;
        }
    }
    answer = v[pivot].size();
    int pp = lower_bound(v[pivot].begin(),v[pivot].end(),num) - v[pivot].begin();
    answer -= pp;
    return answer;
}