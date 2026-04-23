class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        vector<long long> ans;

        unordered_map<int, vector<int>> u;
        for(int i=0;i<nums.size();i++){
            u[nums[i]].push_back(i);
        } 

        unordered_map<int, vector<long long >> ps;
        for(auto it:u){
            if(it.second.size()==1)
                continue;
            else{
                vector<long long > temp;
                long long s=0;
                for(auto l:it.second){
                    s+=l;
                    temp.push_back(s);
                }
                ps[it.first]=temp;
            }
        }
 
        for(int i=0;i<nums.size();i++){
            long long cal=0;
 

            if(u[nums[i]].size()==1)
            { 
                ans.push_back(0);
                continue;
            }
            else{
                auto &v=u[nums[i]];
                auto &pss=ps[nums[i]];
 

                int ind=lower_bound(v.begin(),v.end(),i)-v.begin();
                int lind=ind-1,rind=ind+1;
 

                long long left=0,right=0;

                if(lind>=0){ 

                    left += (long long)(lind+1)*i - pss[lind];
                }

                if(rind < v.size()){ 

                    right += (long long)pss.back() - pss[ind] - (long long)(pss.size()-ind-1)*i;
                }

                cal = left + right;
 
                ans.push_back(cal);
            }
        }
        return ans;
    }
};