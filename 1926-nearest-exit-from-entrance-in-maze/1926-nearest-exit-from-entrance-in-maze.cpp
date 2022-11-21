class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) 
    {
        set<pair<int,int>> s;
        s.insert({entrance[0],entrance[1]});
        
        queue<pair<int,int>> q;
        
        vector<pair<int,int>> dir;
        dir.push_back({1,0});
        dir.push_back({0,1});
        dir.push_back({-1,0});
        dir.push_back({0,-1});
        
        q.push({entrance[0],entrance[1]});
        int steps=1;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                int x=q.front().first,y=q.front().second;
                q.pop();
                //cout<<x<<" , "<<y<<endl;
                for(int i=0;i<dir.size();i++)
                {
                    int nx=x+dir[i].first,ny=y+dir[i].second;
                    if(nx<0 or nx>=maze.size() or ny<0 or ny>=maze[0].size() or maze[nx][ny]=='+')
                        continue;
                    if(s.find({nx,ny})==s.end())
                    {
                        if(nx==0 or ny==0 or nx==maze.size()-1 or ny==maze[0].size()-1)
                        {
                            //cout<<nx<<" - "<<ny<<endl;
                            return steps;
                        }
                        s.insert({nx,ny});
                        q.push({nx,ny});
                    }

                }
            }
            steps++;
            
        }
        return -1;
        
        
    }
};