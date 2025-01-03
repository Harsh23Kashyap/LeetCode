class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long > prefix;
        long long sum=0;
        for(auto it:nums){
                sum+=it;
                prefix.push_back(sum);
        }
    int c=0;
        for(int i=0;i<nums.size()-1;i++){
            long long  ls=prefix[i];
            long long  rs=sum-ls;
            if(ls>=rs)
            c++;
        }
        return c;
    }
};