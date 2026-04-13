class Solution {
public:
int best=1;
unordered_map<int,char> m;
unordered_map<int, vector<int>> u;
    int longest(int node){
         int first=0,second=0;
         int c=0;
        for(auto it:u[node]){
            int res=longest(it);
            if(m[it]==m[node])
                continue;
            else{
                c++;
                if(res>=first)
                {
                    second=first;
                    first=res;
                }
                else if(res<first and res>=second)
                    second=res;
            } 
        }
        int maxi=1;
        if(c==0)
            maxi= 1;
        else if(c==1){
            maxi= 1+first;
            best=max(best,maxi);
        }
        else{
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