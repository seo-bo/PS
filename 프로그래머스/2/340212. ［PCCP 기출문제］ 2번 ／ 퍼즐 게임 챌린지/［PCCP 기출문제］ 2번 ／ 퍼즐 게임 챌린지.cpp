#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0, n = times.size();
    ll left = 1, right = LLONG_MAX / 4;
    while(left <=right)
    {
        ll mid = (left + right) / 2;
        ll pivot = 0;
        for(int i =0; i<n;++i)
        {
            if(diffs[i] > mid)
            {
                ll a = diffs[i] - mid;
                pivot += (times[i] + ((i-1 <0) ? 0 : times[i-1])) * a + times[i];
            }
            else
            {
                pivot += times[i];
            }
        }
        if (pivot <= limit)
        {
            right = mid - 1;
            answer = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return answer;
}