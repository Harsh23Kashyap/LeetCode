class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set<int> u(arr.begin(),arr.end());
        int maxi=0;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                int x=arr[i],y=arr[j];
                int c=2;
                while(u.find(x+y)!=u.end()){
                    cout<<x+y<<endl;
                    c++;
                    int t=x+y;
                    x=y;
                    y=t;
                }
                maxi=max(maxi,c);
            }
        }
        return maxi>=3?maxi:0;
    }
};