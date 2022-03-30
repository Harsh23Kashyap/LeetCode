class Solution {
public:
    bool isLongPressedName(string name, string typed) 
    {
        int j=0;
        int i;
        for( i=0;i<typed.length();i++)
        {
            //cout<<typed[i]<<" "<<name[j]<<endl;
            if(j==name.length())
            {
                //cout<<"runs"<<endl;
                while(i<typed.length())
                {
                    if(typed[i]!=name[j-1])
                        return false;
                    i++;
                }
            }
            if(typed[i]==name[j])
            {
                j++;
            }
            else if(j>0 and typed[i]==name[j-1])
            {
                
            }
            else
                return false;
        }
        if(j<name.length() or i<typed.length())
            return false;
        return true;
        
    }
};