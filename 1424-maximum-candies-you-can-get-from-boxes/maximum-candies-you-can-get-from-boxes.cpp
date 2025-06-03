class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& ib) {
        unordered_set<int> kf;
        unordered_set<int> taken;
        unordered_set<int> lefttoPlay;
        queue<int> q;
        for(int i=0;i<ib.size();i++){
            
            if(status[ib[i]]==1){
                kf.insert(ib[i]);
                q.push(ib[i]);
            }
            else{
                lefttoPlay.insert(ib[i]);
            }
        }
        int c=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto it=q.front();
                // cout<<"Working on box "<<it<<endl;
                q.pop();
                // if(kf.find(it)==kf.end() and status[it]==0){
                //     q.push(it);
                // }

                if(taken.find(it)!=taken.end())
                    continue;
                taken.insert(it);
                c+=candies[it];
                // cout<<c<<endl;
                for(auto tck:keys[it]){
                    kf.insert(tck);
                    status[tck] = 1; 
                    if(lefttoPlay.find(tck) != lefttoPlay.end() && taken.find(tck) == taken.end()){
                        q.push(tck); 
                    }
                }

                
                for(auto tb:containedBoxes[it]){
                    if(taken.find(tb)==taken.end() ){
                        if(status[tb]==1)
                        q.push(tb);
                        else
                        lefttoPlay.insert(tb);

                    }
                }

            }
                    
        for (auto it: lefttoPlay) {
            if (status[it] == 1 && taken.find(it) == taken.end()) {
                q.push(it); 
            } 
        }

        }
        return c;

    }
};