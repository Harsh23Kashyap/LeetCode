class Solution {
public:
    int maxrectange(vector<int> rect){
        stack<int> st;
        rect.push_back(0);
        int maxre=0;
        for(int i=0;i<rect.size();i++){
            while(!st.empty() and rect[st.top()]>=rect[i]){
                int ind=st.top();
                st.pop();
                int len=st.empty()?i:i-st.top()-1;
                int cr=len*rect[ind];
                maxre=max(maxre,cr);
            }
            st.push(i);
        }
        return maxre;

    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int ans=0;
        vector<int> ts(matrix[0].size(),0);
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]=='1'){
                    ts[j]+=1;
                }
                else{
                    ts[j]=0;
                }
            }
            ans=max(ans,maxrectange(ts));

        }
        return ans;
    }
};