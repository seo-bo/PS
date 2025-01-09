#include <bits/stdc++.h>
#define MOD 1000
using namespace std;
typedef long long ll;
typedef long double lb;

ll N = 0, B = 0;

struct mat
{
    ll m[5][5] = { 0, };
};

mat base;

mat mul(const mat& a, const mat& b)
{
    mat result;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            result.m[i][j] = 0;
            for (int k = 0; k < N; ++k)
            {
                result.m[i][j] = (result.m[i][j] + a.m[i][k] * b.m[k][j]) % MOD;
                if (result.m[i][j] < 0)
                {
                    result.m[i][j] += MOD;
                }
            }
        }
    }
    return result;
}

mat add(const mat& a, const mat& b)
{
    mat result;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            result.m[i][j] = (a.m[i][j] + b.m[i][j]) % MOD;
            if (result.m[i][j] < 0)
            {
                result.m[i][j] += MOD;
            }
        }
    }
    return result;
}

mat pw(mat a, ll E)
{
    mat result;
    for (int i = 0; i < N; ++i)
    {
        result.m[i][i] = 1;
    }
    while (E)
    {
        if (E % 2)
        {
            result = mul(result, a);
        }
        a = mul(a, a);
        E /= 2;
    }
    return result;
}

mat sum(mat a, ll E) 
{
    if (E == 1) 
    {
        return a;
    }
    mat hs = sum(a, E / 2);
    mat hp = pw(a, E / 2);
    mat hsum = mul(hs, hp);
    mat result = add(hs, hsum);
    if (E % 2) 
    {
        result = add(result, pw(a, E));
    }
    return result;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> B;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> base.m[i][j];
        }
    }
    mat result = sum(base, B);
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cout << result.m[i][j] % MOD << " ";
        }
        cout << "\n";
    }
    return 0;
}