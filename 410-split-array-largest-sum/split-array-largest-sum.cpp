class Solution {
public:
int total=0;
    bool possible(vector<int> nums, int m, int k){

        int sum=0;
        int csum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>m)
            return false;
            if(csum+nums[i]>m){
                k--;
                if(k<=0)
                    return false;
                csum=nums[i];
            }
            else
                csum+=nums[i];
            cout<<csum<<endl;
            
        }
        return k>0;

    }
    int splitArray(vector<int>& nums, int k) {
        total=accumulate(nums.begin(),nums.end(),0);
        if(nums.size()==k){
            return *max_element(nums.begin(),nums.end());
        }
        if(nums.size()==1)
            return total;

        
        vector<int> ps;
        ps.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
            ps.push_back(nums[i]+ps.back());


        int l=*min_element(nums.begin(),nums.end());
        int h=total;
        int ans=h;
        while(l<=h){
            int m=l+(h-l)/2;
            cout<<"Mid "<<m<<endl;
            if(possible(nums,m,k))
            {
                cout<<"Runs"<<endl;
                ans=m;
                h=m-1;
            }
            else
            l=m+1;
        }
        return ans;

        
    }
};