class Solution {
public:
    int minimumDeletions(string s) {
        int a=0,b=0;
        for(auto it:s)
        {
            if(it=='a')
                a++;
            else
            b++;
        }
        int ca=0,cb=0, mini=s.size();
        for(int i=0;i<s.size();i++){
            //cur point efore this
            //on left of cut how many bs we have
            //from to end how mamny a we have
            if(cb+(a-ca)<mini)
            mini=cb+(a-ca);
            if(s[i]=='a')
                ca++;
            else
                cb++;
        }
        if(cb+(a-ca)<mini)
            mini=cb+(a-ca);
        return mini;
    }
};