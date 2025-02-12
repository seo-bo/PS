#include <iostream>
#include <queue>
#include <map>
using namespace std;

int solution(int n)
{
    int ans = 0;
    while(n)
    {
        if(n & 1)
        {
            ans++;
        }
        n >>= 1;
    }
    return ans;
}