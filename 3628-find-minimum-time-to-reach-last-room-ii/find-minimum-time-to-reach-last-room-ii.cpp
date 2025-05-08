class Solution {
public:
typedef vector<int> v;
vector<int> dx={1,0,-1,0,1};
    int mini(vector<vector<int>> mt){

        priority_queue<v,vector<v>,greater<v>> pq;

        unordered_set<int> u;
        int r=mt.size(),c=mt[0].size();

        pq.push({0,0,0,0});
        u.insert(0);
        while(!pq.empty()){
            auto j=pq.top();
            int x=j[1],y=j[2],s=j[3],t=j[0];
            // cout<<x<<" "<<y<<" "<<t<<endl;
            pq.pop();
            if(x==r-1 and y==c-1)
                return t;
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dx[i+1];
                if(nx<0 or ny<0 or nx>=r or ny>=c or u.find(nx*c+ny)!=u.end())
                    continue;
                int ns=1;
                if(s!=0)
                    ns=(s==1)?2:1;
                u.insert(nx*c+ny);
                pq.push({max(ns+t,ns+mt[nx][ny]),nx,ny,ns});
            }

        }
        return -1;

    }
    int minTimeToReach(vector<vector<int>>& moveTime) {
        return mini(moveTime);
    }
};