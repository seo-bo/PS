#include <string>
#include <vector>
#include <set>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    multiset<string>s(participant.begin(),participant.end());
    for(auto & i : completion)
    {
        s.erase(s.find(i));
    }
    return *s.begin();
}