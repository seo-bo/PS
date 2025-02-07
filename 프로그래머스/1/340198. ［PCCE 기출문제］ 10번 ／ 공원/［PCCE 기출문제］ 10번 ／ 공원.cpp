#include <string>
#include <vector>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1;
    int n = park.size(), m = park[0].size();
    auto sv = [&] (int x, int y,int z)
    {
        for(int i = x; i < x + z;++i)
        {
            for(int j = y; j < y + z;++j)
            {
                if(i >=0 && i < n && j >=0 && j < m && park[i][j] == "-1")
                {
                    continue;
                }
                return false;
            }
        }
        return true;
    };
    for(int i =0; i<n;++i)
    {
        for(int j =0; j <m; ++j)
        {
            if(park[i][j] != "-1")
            {
                continue;
            }
            for(auto & z : mats)
            {
                if(sv(i,j,z))
                {
                    answer = max(answer,z);
                }
            }
        }
    }
    return answer;
}