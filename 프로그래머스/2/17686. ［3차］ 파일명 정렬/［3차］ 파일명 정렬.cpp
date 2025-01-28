#include<bits/stdc++.h>
using namespace std;

vector<string> solution(vector<string> b) {
    vector<string> answer;
    vector<pair<string,int>>v;
    int n = b.size();
    for(int i = 0; i<n;++i)
    {
        v.push_back(make_pair(b[i],i));
    }
    sort(v.begin(),v.end(), [&] (const pair<string,int> A, const pair<string,int> B)
         {
             auto [a,c] = A;
             auto [b,d] = B;
             transform(a.begin(),a.end(), a.begin(), ::tolower);
             transform(b.begin(),b.end(), b.begin(), ::tolower);
             string ah,bh,at,bt, temp;
             int anum =0, bnum = 0;
             int i = 0;
             while(i < n && !isdigit(a[i]))
             {
                 ah += a[i++];
             }
             while(i < n && isdigit(a[i]))
             {
                 temp += a[i++];
             }
             if(!temp.empty())
             {
                 anum = stoi(temp);
             }
             at = a.substr(i);
             i = 0;
             temp = "";
              while(i < n && !isdigit(b[i]))
             {
                 bh += b[i++];
             }
             while(i < n && isdigit(b[i]))
             {
                 temp += b[i++];
             }
             if(!temp.empty())
             {
                 bnum = stoi(temp);
             }
             bt = b.substr(i);
             
             if(ah == bh)
             {
                 if(anum == bnum)
                 {
                    return c < d;
                 }
                 return anum < bnum;
             }
             return ah < bh;
         });
    for(auto & [i,j] : v)
    {
        answer.push_back(i);
    }
    return answer;
    
}