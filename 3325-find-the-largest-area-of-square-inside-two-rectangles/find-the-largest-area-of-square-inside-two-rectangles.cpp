class Solution {
public:

    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long maxi=0;
        int n=bottomLeft.size();
        for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++){
                long long left   = max(bottomLeft[i][0], bottomLeft[j][0]);
                long long right  = min(topRight[i][0], topRight[j][0]);
                long long bottom = max(bottomLeft[i][1], bottomLeft[j][1]);
                long long top    = min(topRight[i][1], topRight[j][1]);
                if(left>right or top<bottom)
                continue;
                long long sz=min(right-left,top-bottom);
            maxi=max(maxi,sz*sz);
        }
        return maxi;
    }
};