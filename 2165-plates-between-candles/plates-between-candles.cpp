class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
         int n = s.size();
        
        vector<int> prefix(n,0);
        vector<int> leftCandle(n,-1);
        vector<int> rightCandle(n,-1);
        
        // prefix sum of plates
        prefix[0] = (s[0] == '*');
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1] + (s[i] == '*');
        }
        
        // nearest candle on left
        int last = -1;
        for(int i=0;i<n;i++){
            if(s[i] == '|') last = i;
            leftCandle[i] = last;
        }
        
        // nearest candle on right
        last = -1;
        for(int i=n-1;i>=0;i--){
            if(s[i] == '|') last = i;
            rightCandle[i] = last;
        }
        
        vector<int> ans;
        
        for(auto &q : queries){
            
            int L = q[0];
            int R = q[1];
            
            int leftBoundary = rightCandle[L];
            int rightBoundary = leftCandle[R];
            
            if(leftBoundary == -1 || rightBoundary == -1 || leftBoundary >= rightBoundary){
                ans.push_back(0);
            }
            else{
                int plates = prefix[rightBoundary] - prefix[leftBoundary];
                ans.push_back(plates);
            }
        }
        
        return ans;
    }
};