#include <string>
#include <vector>
using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0, ed = 0;
    vector<int>ok(1001,-1);
    for(auto & i : attacks)
    {
        ok[i[0]] = i[1];
        ed = max(ed,i[0]);
    }
    int cnt = 0, base = health;
    for(int i =1; i<=ed;++i)
    {
        if(ok[i] == -1)
        {
            health = min(base, health + bandage[1]);
            if(++cnt == bandage[0])
            {
                health = min(base, health + bandage[2]);
                cnt = 0;
            }
        }
        else
        {
            cnt = 0;
            health -= ok[i];
            if(health <=0)
            {
                return -1;
            }
        }
    }
    return health;
}