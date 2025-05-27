class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
       vector<int> ans(t.size(),0);
        stack<int> s;
        s.push(0);
        for(int i=1;i<t.size();i++){
            while(!s.empty() and t[s.top()]<t[i]){
                ans[s.top()]=i-s.top();
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};