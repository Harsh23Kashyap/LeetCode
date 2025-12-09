class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int m=1e9+7; 
       unordered_map<int,int> tp;
 
       unordered_map<int,int> nx;
        for(auto it:nums)
            nx[it]++;
        int ans=0; 

        for(int i=0;i<nums.size();i++){

            int val=nums[i];
            nx[nums[i]]--;
            int need=val*2;

           if (tp.find(need) != tp.end() && nx.find(need) != nx.end()) {
                long long prevfreq = tp[need];
                long long nextfreq = nx[need];
                ans = (ans + prevfreq * nextfreq % m) % m;
            }

            tp[nums[i]]++;
        }
        return ans;
    }
};