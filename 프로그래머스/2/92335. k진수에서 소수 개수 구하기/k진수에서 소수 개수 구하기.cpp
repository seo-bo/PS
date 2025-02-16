#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool check(ll n)
{
    if(n < 2)
    {
        return false;
    }
    if(n == 2 || n == 3)
    {
        return true;
    }
    if(n % 2 == 0)
    {
        return false;
    }
    for (ll i = 3; i<= sqrt(n); i += 2)
    {
        if(n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string str;
    while(n)
    {
        int ok = n % k;
        str += (ok + '0');
        n /= k;
    }
    reverse(str.begin(),str.end());
    string temp;
    for(auto & i : str)
    {
        if(i == '0')
        {
            if(!temp.empty())
            {
                if(check(stoll(temp)))
                {
                    answer++;
                }
            }
            temp = "";
        }
        else
        {
            temp += i;
        }
    }
    if(!temp.empty())
    {
        if(check(stoll(temp)))
        {
            answer++;
        }
    }
    return answer;
}