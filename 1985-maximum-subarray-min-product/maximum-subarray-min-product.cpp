class Solution {
public:
int m=1e9+7;
    int maxSumMinProduct(vector<int>& nums) {
        int n=nums.size();
        vector<long long> ps;
        long long cs=0;
        vector<long long> pse(n,0);
        vector<long long> nse(n,0);


        for(auto it:nums){
            cs+=it;
            ps.push_back(cs);
        }
        //looking for previous smaller
        stack<int> st;

        for(int i=0;i<n;i++){

            while(!st.empty() and nums[st.top()]>=nums[i]){
                st.pop();
            }

            int li=st.empty()?-1:st.top();

            pse[i]=li;

            st.push(i);

        }

        while(!st.empty()){
            st.pop();
        }

        for(int i=n-1;i>=0;i--){

            while(!st.empty() and nums[st.top()]>=nums[i]){
                st.pop();
            }

            int li=st.empty()?nums.size():st.top();

            nse[i]=li;

            st.push(i);

        }

        while(!st.empty()){
            st.pop();
        }


        long long ans=0;

        for(int i=0;i<n;i++){


            int l = pse[i];
            int r = nse[i]; 
            int L = l + 1;
            int R = r - 1;

            long long sum = ps[R] - (L > 0 ? ps[L-1] : 0);

            long long finalval = sum * nums[i];
            ans = max(ans, finalval);
            
        }

        return ans%m;





    }
};