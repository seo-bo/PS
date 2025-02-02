#include <string>
#include <vector>
using namespace std;
typedef long long ll;
int solution(int n) 
{
    int answer = 0;
    vector<bool>prime(n+1,true);
    prime[0] = prime[1] = false;
    for(ll i =2; i * i<= n;++i)
    {
        if(prime[i])
        {
            for(ll j = i*i; j<=n; j += i)
            {
                prime[j] = false;
            }
        }
    }
    for (int i =2; i<=n;++i)
    {
        if(prime[i])
        {
          answer++;
        }
    }
    return answer;
}