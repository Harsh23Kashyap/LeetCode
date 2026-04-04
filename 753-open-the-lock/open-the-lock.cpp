class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<string> q;
        unordered_set<string> u(deadends.begin(), deadends.end());
        if(u.find("0000")!=u.end())
        return -1;
        q.push("0000");
        unordered_set<string> vis;
        vis.insert("0000");
        int c=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto it=q.front();
                q.pop();
                if(it==target)
                return c;
               
                for(int i=0;i<4;i++){
                    string temp=it;
                    char ch=temp[i];
                    char nx=ch,prev=ch;
                    nx++,prev--;
                    if(ch=='9')
                    nx='0';
                    if(ch=='0')
                    prev='9';

                    temp[i]=nx;
                    if(u.find(temp)==u.end() and vis.find(temp)==vis.end()){
                        q.push(temp);
                        vis.insert(temp);
                    }
                    temp[i]=prev;
                    if(u.find(temp)==u.end() and vis.find(temp)==vis.end()){
                        q.push(temp);
                        vis.insert(temp);
                    }
                }
            }
            c++;
        }
        return -1;
    }
};