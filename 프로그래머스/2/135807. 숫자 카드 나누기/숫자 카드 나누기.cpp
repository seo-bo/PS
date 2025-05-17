#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    vector<int>div = {A[0],B[0]};
    for(ll i =2; i<=(ll)sqrt(A[0]) + 2;++i)
    {
        if(A[0] % i == 0)
        {
            div.push_back(i);
            if(A[0] / i != i)
            {
                div.push_back(A[0] / i);
            }
        }
    }
    for(ll i =2; i<=(ll)sqrt(B[0]) + 2;++i)
    {
        if(B[0] % i == 0)
        {
            div.push_back(i);
            if(B[0] / i != i)
            {
                div.push_back(B[0] / i);
            }
        }
    }
    sort(div.rbegin(),div.rend());
    for(auto & i : div)
    {
        bool f1 = true, f2 = true;
        for(auto & j : A)
        {
            if(j % i)
            {
                f1 = false;
                break;
            }
        }
        for(auto & j : B)
        {
            if(j % i == 0)
            {
                f1 = false;
                break;
            }
        }
        for(auto & j : B)
        {
            if(j % i)
            {
                f2 = false;
                break;
            }
        }
        for(auto & j : A)
        {
            if(j % i == 0)
            {
                f2 = false;
                break;
            }
        }
        if(f1 | f2)
        {
            return i;
        }
    }
    return 0;
}