#define ll long long
class Solution {
public:
    bool check(ll n1, ll n2, string s, bool ans)
    {
        if(s.length()==0 and ans)
            return true;
        
        string n3=to_string(n1+n2);
        int idx=min(s.length(),n3.length());
        if(s.substr(0,idx)!=n3)
            return false;
        return check(n2,stol(n3), s.substr(idx),true);
    }
    bool isAdditiveNumber(string num) 
    {
        if(num.length()<3)
            return false;
        
        for(int i=1;i<num.length()-1;i++)
        {
            ll n1=stol(num.substr(0,i));
            if(to_string(n1)!=num.substr(0,i))
                break;
            for(int j=i+1;j<num.length();j++)
            {
                ll n2=stol(num.substr(i,j-i));
                if(to_string(n2)!=num.substr(i,j-i))
                    break;
                bool happens=check(n1,n2,num.substr(j),false);
                if(happens) return true;
            }
        }
        return false;
    }
};