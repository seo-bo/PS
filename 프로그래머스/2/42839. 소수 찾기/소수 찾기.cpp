#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;
int solution(string numbers) {
    int answer = 0;
    vector<bool>prime(10000005,true);
    prime[0] = prime[1] = false;
    for (ll i =2; i*i<=10000005;++i)
    {
        if(prime[i])
        {
            for(ll j = i*i;j<=10000005; j +=i)
            {
                prime[j] = false;
            }
        }
    }
    int len = numbers.size();
    sort(numbers.begin(),numbers.end());
    set<int>s;
    do
    {
        for(int i =0; i<(1<<len);++i)
        {
            string temp = "";
            for(int j =0; j<len;++j)
            {
                if(i & (1<<j))
                {
                    temp += numbers[j];
                }
            }
            if(!temp.empty() && prime[stoi(temp)])
            {
                s.insert(stoi(temp));
            }
        }
    }while(next_permutation(numbers.begin(),numbers.end()));
    return (int)s.size();
}