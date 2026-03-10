class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> s;
        vector<int> ans;
        for(int i=heights.size()-1;i>=0;i--){
            int c=0;
            while(!s.empty() and heights[s.top()]<heights[i]){
                c++;
                // cout<<"At index "<<i<<" popping "<<heights[s.top()]<<" "<<s.size()-1<<endl;
                s.pop();
            }

            ans.push_back(c+(s.empty()?0:1));
            s.push(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};