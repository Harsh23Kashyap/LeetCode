class Solution {
public:
    int numberOfArrays(vector<int>& diff, int lower, int upper) {
        // int n=diff.size();
        // vector<int> ps(n,0);
        // int sum=0;
        // for(int i=0;i<diff.size();i++){
        //     sum+=diff[i];
        //     ps.push_back(sum);
        // }
        // int maxi=*max_element(ps.begin(),ps.end());
        // int mini=*min_element(ps.begin(),ps.end());
        long long c=lower;
        long long maxi=lower,mini=lower;
        for(int i=0;i<diff.size();i++){
            c+=diff[i];
            maxi=max(maxi,c);
            mini=min(mini,c);
        }
        int rs=maxi-mini;
        int ans=upper-lower+1-rs;
        return ans<0?0:ans;
    }
};