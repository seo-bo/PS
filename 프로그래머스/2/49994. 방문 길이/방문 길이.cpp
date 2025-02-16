#include <string>
#include <vector>
#include <map>
#include <set>
#include <tuple>
using namespace std;
typedef tuple<int,int,int,int> tp;

int solution(string dirs) {
    int answer = 0;
    map<char,int>mm = {{'U',0},{'D',1},{'R',2},{'L',3}};
    set<tp>visited;
    vector<vector<int>>dir = {{-1,0},{1,0},{0,1},{0,-1}};
    int x = 0, y = 0;
    for(auto & i :dirs)
    {
        int d = mm[i];
        int nx = x + dir[d][0];
        int ny = y + dir[d][1];
        tp a = make_tuple(x,y,nx,ny);
        tp b = make_tuple(nx,ny,x,y);
        if(abs(nx) <= 5 && abs(ny) <= 5)
        {
            if(visited.find(a) == visited.end() && visited.find(b) == visited.end())
            {   answer++;
                visited.insert(a);
                visited.insert(b);
            }
            x = nx, y= ny;
        }
    }
    return answer;
}