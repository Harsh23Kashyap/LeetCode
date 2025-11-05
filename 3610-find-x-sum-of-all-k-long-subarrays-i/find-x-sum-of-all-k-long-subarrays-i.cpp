class Solution {
public:
unordered_map<int, int> ul;
multiset<pair<long long,int>> m;
long long printxsum( int x){
    long long ans=0;
    for(auto it:m){
        if(x==0)
            break;
        long long freq=it.first*-1;
        long long number=it.second*-1;
        ans+=freq*number;
        x--;
    }
    return ans;
       
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
         vector<int> ans;
       
        int l=nums.size()<k?nums.size():k;
       for(int i=0;i<l;i++)
            ul[nums[i]]++;
        
        for(auto it:ul)
            m.insert({-1*it.second,-1*it.first});

        ans.push_back(printxsum(x));
        int i=k;
        while(i<nums.size()){
            int numdel=nums[i-k];
            int freq=ul[nums[i-k]];
            if(m.find({-1*freq,numdel*-1})!=m.end())
                m.erase({-1*freq,numdel*-1});
            ul[nums[i-k]]--;
            int newfreq=ul[nums[i-k]];
            m.insert({-1*newfreq,numdel*-1});
            numdel=nums[i];
            freq=ul[nums[i]];
            if(m.find({-1*freq,numdel*-1})!=m.end())
                m.erase({-1*freq,numdel*-1});
            ul[nums[i]]++;
             newfreq=ul[nums[i]];
            m.insert({-1*newfreq,numdel*-1});
            
            ans.push_back(printxsum(x));
            i++;
        }
        return ans;
    }
};