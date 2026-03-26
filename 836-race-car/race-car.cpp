class Solution {
public:
long long hash(int pos, int speed){
    return ((long long)pos << 32) ^ (long long)speed;
}
    int racecar(int target) {
        
        int speed=1;
        queue<vector<long long>> q;
        int pos=0;
        q.push({1,0,0});
        unordered_set<long long> vis;
        vis.insert(hash(0,1));
        while(!q.empty()){
            
            int sz=q.size();
            while(sz--){
                auto it=q.front();
                q.pop();
                long long s=it[0],p=it[1],x=it[2];
                // cout<<s<<" "<<p<<endl;
                if(p==target)
                    return x;

                //A
                int np=p+s;
                int ns=s*2; 
                if(abs(np)<2*target){
                    auto lll=hash(np,ns);
                    if(vis.find(lll)==vis.end())
                    {
                        q.push({ns,np,x+1});
                        vis.insert(lll);
                    }
                }
                
                //R
                np=p;
                if(s>0)
                    ns=-1;
                else
                    ns=1;
                if(abs(np)<2*target){
                    auto lll=hash(np,ns);
                    if(vis.find(lll)==vis.end())
                    {
                        q.push({ns,np,x+1});
                        vis.insert(lll);
                    }
                }
                    

            }
           
        }
        return -1;
    }
};