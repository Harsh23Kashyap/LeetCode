class Solution {
public:
    int halveArray(vector<int>& nums) 
    {
        priority_queue<double> pq;
        double currsum=0;
        //cout<<"runs"<<endl;
        for(int i=0;i<nums.size();i++)
        {
            currsum+=nums[i];
            pq.push(nums[i]);
        }
        int count=0;
        double sum=currsum;
        //cout<<currsum<<endl;
        while(sum>currsum/2)
        {
            //cout<<pq.top();
            count++;
            double peak=pq.top()/2.0;
            pq.pop();
            pq.push(peak);
            sum=sum-peak;
           // cout<<" sum -"<<sum<<endl;
        }
        return count;
    }
};