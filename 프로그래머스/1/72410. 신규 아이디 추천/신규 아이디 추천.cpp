#include <bits/stdc++.h>

using namespace std;

string solution(string new_id) {
    string answer = "";
    transform(new_id.begin(),new_id.end(), new_id.begin(), ::tolower);
    string temp = "";
    for(auto & i : new_id)
    {
        if('a' <= i && i <='z' || '0' <= i && i <= '9' || i == '-' || i == '_' || i == '.')
        {
            temp += i;
        }
    }
    bool flag = false;
    new_id = temp;
    temp = "";
    for(int i =0; i<(int)new_id.size();++i)
    {
        if(new_id[i] == '.')
        {
            flag = true;
        }
        else
        {
            if(flag)
            {
                temp += '.';
                flag = false;
            }
            temp += new_id[i];
        }
    }
    new_id = temp;
    temp = "";
    if(!new_id.empty() && new_id.back() == '.')
    {
        new_id.pop_back();
    }
    if(!new_id.empty() && new_id[0] == '.')
    {
        new_id.erase(new_id.begin());
    }
    if(new_id.empty())
    {
        new_id = 'a';
    }
    while(!new_id.empty() && new_id.size() > 15)
    {
        new_id.pop_back();
    }
    if(new_id.back() == '.')
    {
        new_id.pop_back();
    }
    char pivot = new_id.back();
    while(new_id.size() < 3)
    {
        new_id += pivot;
    }
    return new_id;
}