class Solution {
public:
    string repeatLimitedString(string s, int rl) {
        unordered_map<char,int> u;
        for(auto it:s)
            u[it]++;
        
        priority_queue<char> pq;
        for(auto it:u)
            pq.push(it.first);
        string a="";
        
        while(!pq.empty())
        {
            
            auto it=pq.top();
            cout<<it<<endl;
            if(!a.empty() and a.back()==it){
                pq.pop();
                if(pq.empty() )
                    break;
                auto tt=pq.top();
                pq.pop();
                pq.push(it);
                if(u[tt]>0){
                     
                    a+=tt;
                    u[tt]--;
                    if(u[tt]>0)
                    pq.push(tt);
                
                }
            }
            else
            {
                pq.pop();
                if(u[it]<=rl){
                    string ns(u[it],it);
                     cout<<"secion 1 -1 "<<ns<<endl;
                    a+=ns;
                    u[it]=0;
                }
                else {
                    string ns(rl,it);
                     cout<<"secion 1 -2 "<<ns<<endl;
                    a+=ns;
                    u[it]-=rl;
                    pq.push(it);
                }
            }
        }
        
        return a;
    }
};