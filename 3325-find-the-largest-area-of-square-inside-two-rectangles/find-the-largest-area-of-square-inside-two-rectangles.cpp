class Solution {
public:
long long largest(
    vector<int>& al, vector<int>& au,
    vector<int>& bl, vector<int>& bu
) {
    long long left   = max(al[0], bl[0]);
    long long right  = min(au[0], bu[0]);
    long long bottom = max(al[1], bl[1]);
    long long top    = min(au[1], bu[1]);

    if (left >= right || bottom >= top)
        return 0;

    long long side = min(right - left, top - bottom);
    return side * side;
}

    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long maxi=0;
        int n=bottomLeft.size();
        for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++){

            long long c1=largest(bottomLeft[i],topRight[i],bottomLeft[j],topRight[j]);
            // cout<<c1<<endl;
            maxi=max(maxi,c1);
        }
        return maxi;
    }
};