#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void generateSubarray(string s , int n)
{
    int indexFetch=0;
    while(n>0)
    {
        int lastBit= n&1;
        if(lastBit==1)
            cout<<s[indexFetch];
        indexFetch++;
        n=n>>1;
    }
    cout<<endl;
}
int main() 
{
    string s= "ABCD";
    int len=s.length();
    int n= 1<<len;
    cout<<"Possible combinations : "<<n<<endl;
    cout<<"\nGenerating Subarrays"<<endl;
    for(int i=0;i<n;i++)
    {
        generateSubarray(s,i);
    }
}