#include <string>
#include <vector>
#include <map>
#include <functional>
using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    map<char,int>mm = {{10,'A'},{11,'B'},{12,'C'},{13,'D'},{14,'E'},{15,'F'}};
    p--;
    int base = 0, idx = 0;
    auto cal = [&]
    {
        vector<int>temp;
        
        int pivot = base;
        if(base == 0)
        {
            temp.push_back(0);
        }
        while(pivot)
        {
            temp.push_back(pivot % n);
            pivot /= n;
        }
        int len = temp.size()-1;
        for(int i = len; i>=0;--i)
        {
            if(idx == p)
            {
                if(temp[i] >= 10)
                {
                    answer += mm[temp[i]];
                }
                else
                {
                    answer += (temp[i] + '0');
                }
            }
            idx = (idx + 1) % m;
        }
    };
    while((int)answer.size() < t)
    {
        cal();
        base++;
    }
    while((int)answer.size() > t)
    {
        answer.pop_back();
    }
    return answer;
}