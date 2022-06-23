class Solution {
public:
    string largestOddNumber(string num) 
    {
        int i;
        for(i=num.size()-1;i>=0;i--)
        {
            char ch=num[i];
            if(ch=='1' or ch=='3' or ch=='5' or ch=='7' or ch=='9')
                break;
            
        }
        return num.substr(0,i+1);
            
        
    }
};