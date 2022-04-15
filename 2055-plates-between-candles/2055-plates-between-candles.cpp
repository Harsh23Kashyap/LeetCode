class Solution {
    static vector<int> search(int start,int end, string a)
    {
        vector<int> res(2,-2);
        for(int i=start;i<=end;i++)
        {
            if(a[i]=='|')
            {
                res[0]=i;
                break;
            }
        }
        for(int i=end;i>=start;i--)
        {
            if(a[i]=='|')
            {
                res[1]=i;
                break;
            }
        }
        return res;
    }
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) 
    {
        vector<int> candleCount(s.length(),0);
        vector<int> leftClosest(s.length(),-1);
         vector<int> rightClosest(s.length(),1e5 +1);
        
        vector<int> res;
        
        
        if(s[0]=='*')
            candleCount[0]=1;
        else
            leftClosest[0]=0;
        for(int i=1;i<s.length();i++)
        {
            if(s[i]=='*')
            {
                candleCount[i]=candleCount[i-1]+1;
            }
            else
            {
                candleCount[i]=candleCount[i-1];
            }
            
            if(s[i]=='|')
                leftClosest[i]=i;
            else
                leftClosest[i]=leftClosest[i-1];
        }
        
        if(s[s.length()-1]=='|')
            rightClosest[s.length()-1]=s.length()-1;
        
        for(int i=s.length()-2;i>=0;i--)
        {
            if(s[i]=='|')
                rightClosest[i]=i;
            else
                rightClosest[i]=rightClosest[i+1];
        }
       
        
      for(vector<int> q:queries )
      {
          int lowerIndex=rightClosest[q[0]];
          int upperIndex=leftClosest[q[1]];
          // cout<<"Lower-> "<<lowerIndex<<endl;
          // cout<<"Upper-> "<<upperIndex;
          if(lowerIndex>=upperIndex)
              res.push_back(0);
          else
              res.push_back(candleCount[upperIndex]-candleCount[lowerIndex]);
      }
        
        return res;
        
    }
};