class Solution {
public:
    bool possible(string answerKey, int k, int mid)
    {
        int true1=0,false1=0;
        for(int i=0;i<mid;i++)
        {
            if(answerKey[i]=='T')
                true1++;
            else
                false1++;
        }
        if(true1<=k or false1<=k)
        {
            //cout<<"True1"<<endl;
            return true;
        }
        
        for(int j=mid;j<answerKey.length();j++)
        {
            if(answerKey[j-mid]=='T')
                true1--;
            else
                false1--;
            
            if(answerKey[j]=='T')
                true1++;
            else
                false1++;
            
            if(true1<=k or false1<=k)
             {
                //cout<<"True2"<<endl;
                return true;
        }
        }
        return false;
    }
    int maxConsecutiveAnswers(string answerKey, int k) 
    {
        int low=1,high=answerKey.length();
        int best=1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            //cout<<mid<<endl;
            if(possible(answerKey,k,mid))
            {
                best=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
                
        }
        return best;
        
    }
};