class Solution {
public:
    int sum(int n)
    {
        int add=0;
        while(n>0)
        {
            int dig=n%10;
            add+=dig*dig;
            n/=10;
        }
        return add;
    }
    bool isHappy(int n) 
    {
        set<int> s;
        while(true)
        {
            int add=sum(n);
            cout<<add<<endl;
            if(add==1) return true;
            if(s.find(add)!=s.end())
                return false;
            else    s.insert(add);
            n=add;
        }
        return n==1;
    }
};