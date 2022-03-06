class Solution {
    int evaluate(vector<int>& mapping, int number)
    {
        int newNum=0;
        int p=1;
        if(number==0)
            return mapping[number];
        while(number>0)
        {
            int dig=number%10;
            newNum=mapping[dig]*p+newNum;
            p*=10;
            number/=10;
        }
        return newNum;
        
    }
    static bool cmp(const pair<int,int> &a, const pair<int,int> &b)
    {
        if(a.first<b.first)
            return true;
        else if(a.first==b.first)
        {
            if(a.second<b.second)
                return true;
        }
        return false;
        
    }
public:
    
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) 
    {
        
        vector<int> ans;
        vector<pair<int,int>> eval;
        for(int i=0;i<nums.size();i++)
        {
            int newval=evaluate(mapping,nums[i]);
            //cout<<newval<<endl;
            eval.push_back(make_pair(newval,i));
        }
        
        sort(eval.begin(),eval.end(),cmp);
        for(int i=0;i<eval.size();i++)
        {
           ans.push_back(nums[eval[i].second]);
        }
        return ans;
    }
};