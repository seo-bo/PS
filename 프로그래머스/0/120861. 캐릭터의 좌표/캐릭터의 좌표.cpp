#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer;
    map<string,pii>mm = {{"left", {-1,0}}, {"right", {1,0}}, {"up", {0,1}}, {"down", {0,-1}}};
    int x = 0, y = 0;
    for(auto & i : keyinput)
    {
         auto it = mm.find(i);
         auto [a,b] = it->second;
         if(x + a >= -board[0] /2  && x + a <= board[0] / 2)
         {
             x += a;
         }
         if(y + b >= -board[1] /2  && y + b <= board[1] / 2)
         {
             y += b;
         }
    }
    answer = {x,y};
    return answer;
}