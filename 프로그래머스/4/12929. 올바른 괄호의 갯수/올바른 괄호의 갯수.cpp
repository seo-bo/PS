#include<bits/stdc++.h>
using namespace std;

int solution(int n) 
{
    set<string>s;
    function<void(int,int,string)> dfs = [&] (int op, int cl, string str)
    {
        if(!op && !cl)
        {
            s.insert(str);
            return;
        }
        if(op > 0)
        {
            dfs(op-1, cl, str + "(");
        }
        if(cl > op)
        {
            dfs(op,cl-1,str +")");
        }
    };
    dfs(n,n,"");
    return s.size();
}