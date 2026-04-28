class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> a;
        for(auto it:grid){
            for(auto j:it)
                a.push_back(j);
        }

        sort(a.begin(),a.end());

        int mid=a.size()/2;
        int ans=0;
        for(auto it:a){
            if(abs(it-a[mid])%x==0)
                ans+=abs(it-a[mid])/x;
            else
                return -1;
        }
        return ans;
    }
};