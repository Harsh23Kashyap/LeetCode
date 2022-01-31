/******************************************************************************
Given a list of n String S0,S1,S2.... Sn-1. 
S0,S1,S2....Sn-1 
Each String has digits seperated by spaces
Ex. S0= "019 213 314"
There is a key specifying the element on whose basis sorting is to be done.
Ex: key =2 then S0 sorting element will be "213"

There is a reverse value which tells sorted in ascending or descending order.
There is a string which asks whether to sort lexicographically i.e 022<12
or numerically 12<022

Ex:
Input
3                   -n
92 022              -S0
82 012              -S1
77 013              -S3
2                   -key
false               -reverse
numeric             -lexicographic/numeric

Output
82 012
92 022
77 13

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool sortLexico(const pair<string,string> &a, const pair<string,string> &b)
{
    return a.first<=b.first;
}
bool sortNumeric(const pair<string,string> &a, const pair<string,string> &b)
{
    return stoi(a.first)<=stoi(b.first);
}
int main()
{
    int n;
    cin>>n;
    vector<string> v;
    string s;
    getline (cin, s);
    for(int i=0;i<n;i++)
    {
        getline (cin, s);
        v.push_back(s);
    }
    int key;
    bool rev;
    string numeric="lexicographic";
    cin>>key>>rev;
    getline(cin,numeric);
    vector<pair<string,string>> map;
    for(int i=0;i<n;i++)
    {
        int k=0;
        stringstream s(v[i]);
        string temp;
        while(s>>temp)
        {
            k++;
            if(k==key)
                break;
        }
        map.push_back(make_pair(temp,v[i]));
    }
    
    if(numeric=="numeric")
        sort(map.begin(),map.end(),sortNumeric);
    else 
        sort(map.begin(),map.end(),sortLexico);
        
    for(int i=0;i<n;i++)
    {
        v[i]=map[i].second;
    }
    if(rev)
        reverse(v.begin(),v.end());
        
    for(string s:v)
        cout<<s<<endl;
        
    return 0;
}
