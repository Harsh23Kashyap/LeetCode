class Solution {
public:
    string addBinary(string a, string b) 
    {
        int carry=0;
        string temp="";
        for(int i=a.length()-1,j=b.length()-1;i>=0 || j>=0; i--,j--)
        {
            int num=0;
            if(i>=0 && j>=0)
            {
                num=(a[i]-'0')+(b[j]-'0')+carry;
            }
            else if(i>=0)
            {
                num=(a[i]-'0')+carry;
            }
            else if(j>=0)
            {
                num=(b[j]-'0')+carry;
            }
            if(num==0)
            {
                carry=0;
                temp="0"+temp;
            }
            if(num==1)
            {
                carry=0;
                temp="1"+temp;
            }
            else if(num==2)
            {
                carry=1;
                temp="0"+temp; 
            }
            else if(num==3)
            {
                carry=1;
                temp="1"+temp; 
            }
        }
        if(carry>0)
            temp=to_string(carry)+temp;
        return temp;
        
    }
};