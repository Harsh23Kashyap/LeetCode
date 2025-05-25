class Solution {
public:
struct pair_hash {
    size_t operator()(const std::pair<int, int>& p) const {
        return ((size_t)p.first << 16) ^ (size_t)p.second;
    }
};

    int racecar(int target) {
        if(target==0)
            return 0;
        queue<pair<long long,long long>> q;
       set<pair<int, int>> u;
        q.push({0,1});
        u.insert({0,1});
        int c=0;
        while(!q.empty()){
            int sz=q.size();

            while(sz--){
                auto it=q.front();
                // cout<<it.first<<" "<<it.second<<endl;
                q.pop();
                //lets accelerate
                long long nx=it.first+it.second;
                long long ns=it.second*2;
                if(nx==target)
                    return c+1;
                
                // s=to_string(nx)+" . "+to_string(ns);
                if(u.find({nx,ns})==u.end() and nx<=2*target){
                    q.push({nx,ns});
                    u.insert({nx,ns});
                }

                //revrse
                if(it.second>0)
                    ns=-1;
                else
                    ns=1;
                // s=to_string(it.first)+" . "+to_string(ns);
                if(u.find({it.first,ns})==u.end() and it.first<=2*target ){
                    q.push({it.first,ns});
                    u.insert({it.first,ns});
                }

            }
            c++;
            // cout<<endl;
        }
        return -1;

    }
};


/*
A
1.   2
A
3.   4
R
3.   -1


*/