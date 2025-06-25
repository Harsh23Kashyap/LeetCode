class Solution {
public:
bool possible(vector<int> &tasks, vector<int> &workers,int p, int s,int mid){
    
    multiset<int> m(workers.begin(),workers.end());
     int limit = max(0, (int)tasks.size() - mid);
    for(int i=mid-1;i>=0;i--)
    {
        int currtask=tasks[i];
        auto it=m.lower_bound(currtask);
        // cout<<"task "<<currtask<<endl;
        if(it==m.end()){

            if(p>0){
                // cout<<"take pills"<<endl;
                auto it=m.lower_bound(currtask-s);
                if(it==m.end())
                return false;
                else{
                    // cout<<"Removed "<<(*it)<<endl;
                    m.erase(it);
                }
                p--;

            }
            else{
                return false;
            }
        }
        else{
            // cout<<"Safe"<<endl;
            m.erase(it);
        }

    }
    return true;
}
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(),tasks.end());
        // sort(workers.begin(),workers.end());
        int low=0,high=tasks.size();
        int ans=low;
        while(low<=high){
            int mid=low+(high-low)/2;
            // cout<<mid<<endl;
            if(possible(tasks,workers,pills,strength,mid)){
                // cout<<"Runs for "<<mid<<endl;
                low=mid+1;
                ans=mid;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};