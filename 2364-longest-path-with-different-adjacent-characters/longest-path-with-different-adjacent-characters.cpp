class Solution {
public:
int best=1;
unordered_map<int,char> m;
unordered_map<int, vector<int>> u;
    int longest(int node){
        priority_queue<int> pq;
        for(auto it:u[node]){
            int res=longest(it);
            if(m[it]==m[node])
                continue;
            else
                pq.push(res);
        }
        int maxi=1;
        if(pq.empty())
            maxi= 1;
        else if(pq.size()==1){
            maxi= 1+pq.top();
            best=max(best,maxi);
        }
        else{
             int first=pq.top();
            pq.pop();
            int second=pq.top();
            pq.pop();
             best=max(best, 1+first+second);
            maxi= 1+max(first,second);
        }
       

       
        return maxi;
    }
    int longestPath(vector<int>& parent, string s) {
//         You always have two options:
// 1. For this note, we get what the best answer is, and we can either extend it or loop it.
       

        for(int i=0;i<parent.size();i++){
            int curr=parent[i];
            u[curr].push_back(i);
            m[i]=s[i];
        }


        longest(0);

        return best;
    }
};