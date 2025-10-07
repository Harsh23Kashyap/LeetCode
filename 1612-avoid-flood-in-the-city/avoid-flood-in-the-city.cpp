class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> ans(rains.size(),1);
        set<int> st;
        unordered_map<int,int> u;

        for(int i=0;i<rains.size();i++){
            if(rains[i]==0){
                st.insert(i);
            }
            else{
                ans[i]=-1;
                if(u.find(rains[i])!=u.end()){
                    int lastrain=u[rains[i]];
                    auto fi=st.lower_bound(lastrain);
                    if(fi==st.end()){
                        return {};
                    }
                    ans[*fi]=rains[i];
                    st.erase(fi);
                }
                u[rains[i]]=i;
            }
        }
        return ans;
    }
};