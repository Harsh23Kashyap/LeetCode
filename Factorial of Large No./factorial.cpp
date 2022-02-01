#include <bits/stdc++.h>

using namespace std;

void calculatefactorial(int n, vector<int>& ans)
{
    int dig=0,carr=0;
    for(int i=0;i<ans.size();i++)
    {
        dig=ans[i]*n+carr;
        ans[i]=dig%10;
        carr=dig/10;
    }
    while(carr>0)
    {
        ans.push_back(carr%10);
        carr/=10;
    }
    // cout<<"For - "<<n<<" - ";
    // for(int i=ans.size()-1;i>=0;i--)
    //     cout<<ans[i];
    // cout<<endl;
}
void extraLongFactorials(int n) {
    vector<int> ans{1};
    for(int i=2;i<=n;i++)
    {
        calculatefactorial(i,ans);
    }
    cout<<"Factorial of "<<n<<endl;
    for(int i=ans.size()-1;i>=0;i--)
        cout<<ans[i];
}

int main()
{
    int n;
    cin>>n;

    extraLongFactorials(n);

    return 0;
}