class Solution {
public:
    bool rotateString(string s, string goal) 
    {
        for(int i=0;i<s.length();i++)
        {
            string curr= s.substr(i)+s.substr(0,i);
            //cout<<curr<<endl;
            if(curr==goal)
                return true;
        }
        return false;
        
    }
};