class Solution {
public:
    bool validPalindrome(string s) 
    {
        int i=0;
        int j=s.length()-1;
        int c1=0;
        while(i<=j)
        {
            if(s[i]!=s[j])
            {
                i++;
                c1++;
            }
            else
            {
                i++;
                j--;
            }
        }
        cout<<c1<<endl;
        int c2=0;
        i=0;
        j=s.length()-1;
        while(i<=j)
        {
            if(s[i]!=s[j])
            {
                j--;
                c2++;
            }
            else
            {
                i++;
                j--;
            }
        }
        cout<<c2<<endl;
        if(min(c1,c2)>1) return false;
        return true;
        
    }
};