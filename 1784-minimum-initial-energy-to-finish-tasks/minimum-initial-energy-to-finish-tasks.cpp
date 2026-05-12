class Solution {
public:
static bool cmp(vector<int>& a, vector<int>& b){
    return (a[1]-a[0])>(b[1]-b[0]);
}
 bool possible(vector<vector<int>> &tasks, int m){
    for(auto it:tasks){
        // cout<<it[0]<<" "<<it[1]<<" "<<m<<endl;;
        if(it[1]>m)
        return false;
        m-=it[0];
    }
    return true;
}
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),cmp);

        int l=tasks[0][1], h=1e9;
        int ans=1e9;
        while(l<=h){
            int m=l+(h-l)/2;
            cout<<m<<endl;
            if(possible(tasks,m)){
                // cout<<"works"<<endl;
                ans=m;
                h=m-1;
            }
            else
            l=m+1;
        }
        return ans;
    }
};