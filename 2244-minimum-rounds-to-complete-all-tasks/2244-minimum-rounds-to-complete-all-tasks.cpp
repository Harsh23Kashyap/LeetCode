class Solution {
public:
    int minimumRounds(vector<int>& tasks) 
    {
       map<int,int> m;
        for(int i:tasks)
            m[i]++;
        
        int count=0;
        for(auto i:m)
        {
            if(i.second<2)
                return -1;
            else
            {
                int a=i.second/3;
                if(i.second%3==0)
                    count+=a;
                else
                    count+=a+1;
                
            }
        }
        return count;
        
        
    }
};