#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    multiset<int>s(wallet.begin(),wallet.end());
    multiset<int>m(bill.begin(),bill.end());
    while(*m.begin() > *s.begin() || *prev(m.end()) > *prev(s.end()))
    {
        int jt = *prev(m.end());
        m.erase(jt);
        m.insert(jt /2);
        answer++;
    }
    return answer;
}