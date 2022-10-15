#include<iostream>
using namespace std;
#include<bits/stdc++.h>
string s1,s2;
int f(int i,int j)
{
    if(i==-1 || j==-1)
    {
        return 0;
    }
    else if(s1[i]==s2[j])
    {
        return f(i-1,j-1)+1;
    }
    else
    {
        return max(f(i-1,j),f(i,j-1));
    }
}
void dp()
{
       int n=s1.length()+1;
       int m=s2.length()+1;
       vector<vector<int>> v( n , vector<int> (m, 0)); //*****
       for(int i=0;i<=s1.length();i++)
       {
           for(int j=0;j<=s2.length();j++)
           {
               if(i==0||j==0)
               {
                   v[i][j]=0;
               }
               else if(s1[i-1]==s2[j-1])
               {
                   v[i][j]=v[i-1][j-1]+1;
               }
               else
               {
                   v[i][j]=max(v[i-1][j],v[i][j-1]);
               }
           }
       }
       cout<<endl<<v[n-1][m-1];
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while (t--)
    {
       cin>>s1>>s2;
       cout<<f(s1.length()-1,s2.length()-1);  
       dp();  
    }  
    return 0;
}