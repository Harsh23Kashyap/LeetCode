class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) 
    {
        vector<double> med;
        priority_queue<int>  maxh;
        priority_queue<int,vector<int>,greater<int>> minh;
        unordered_map<int,int> u;
        for(int i=0;i<k;i++)
            maxh.push(nums[i]);
        
        for(int i=0;i<(k/2);i++)
        {
            minh.push(maxh.top());
            maxh.pop();
        }
        
        for(int i=k;i<nums.size();i++)
        {
            //cout<<i<<endl;
            if(k%2==0)
            {
                med.push_back(((minh.top()*1.0)+(1.0*maxh.top()))/2.0);
            }
            else
            {
                med.push_back(maxh.top());
            }
            //cout<<med.back()<<endl;
            int del=nums[i-k],add=nums[i];
            
            int left=0;
            
            if(del<=maxh.top())
            {
                left--;
                u[del]++;
            }
            else
            {
                left++;
                u[del]++;
            }
            
            if(!maxh.empty() and add<=maxh.top())
            {
                left++;
                maxh.push(add);
            }
            else
            {
                left--;
                minh.push(add);
            }
            
            if(left<0)
            {
                maxh.push(minh.top());
                minh.pop();
            }
            else if(left>0)
            {
                minh.push(maxh.top());
                maxh.pop();
            }
            
            
            while(!maxh.empty() and u[maxh.top()]>0)
            {
                u[maxh.top()]--;
                maxh.pop();
                
            }
            while(!minh.empty() and u[minh.top()]>0)
            {
                u[minh.top()]--;
                minh.pop();
                
            }
        }
        if(k%2==0)
        {
            med.push_back(((minh.top()*1.0)+(1.0*maxh.top()))/2.0);
        }
        else
        {
            med.push_back(maxh.top());
        }
        
        return med;
    }
};