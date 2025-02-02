#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int idx = 0, i = 0, j = 0;
    while(idx < goal.size() && i < cards1.size() && j < cards2.size())
    {
        string pivot = goal[idx++];
        if(pivot == cards1[i])
        {
            i++;
        }
        else if(pivot == cards2[j])
        {
            j++;
        }
        else
        {
            return "No";
        }
    }
    while(idx < goal.size() && i < cards1.size())
    {
        string pivot = goal[idx++];
        if(pivot == cards1[i])
        {
            i++;
        }
        else
        {
            return "No";
        }
    }
    while(idx < goal.size() && j < cards2.size())
    {
        string pivot = goal[idx++];
        if(pivot == cards2[j])
        {
            j++;
        }
        else
        {
            return "No";
        }
    }
    return "Yes";
}