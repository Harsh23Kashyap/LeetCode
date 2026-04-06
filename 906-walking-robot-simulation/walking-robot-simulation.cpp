class Solution {
public:
    void change(int i, char &d){
        if(i==-2){
            if(d=='N') 
                d='W';
            else if(d=='W') 
                d='S';
            else if(d=='S') 
                d='E';
            else 
                d='N';
        }
        else{
            if(d=='N') 
                d='E';
            else if(d=='E') 
                d='S';
            else if(d=='S') 
                d='W';
            else 
                d='N';
        }
    }

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<int, set<int>> vx;
        unordered_map<int, set<int>> vy;

        for(auto &it:obstacles){
            vx[it[0]].insert(it[1]);
            vy[it[1]].insert(it[0]);
        } 

        int cx=0, cy=0;
        char d='N';
        int ans = 0;

        for(int i=0; i<commands.size(); i++){
            if(commands[i] < 0){
                change(commands[i], d);
                continue;
            }

            int nx = cx, ny = cy;

            if(d=='N'){
                ny = cy + commands[i];
                if(vx.count(cx)){
                    auto it = vx[cx].upper_bound(cy);
                    if(it != vx[cx].end() && *it <= ny){
                        ny = *it - 1;
                    }
                }
            }
            else if(d=='S'){
                ny = cy - commands[i];
                if(vx.count(cx)){
                    auto it = vx[cx].lower_bound(cy);
                    if(it != vx[cx].begin()){
                        --it;
                        if(*it >= ny){
                            ny = *it + 1;
                        }
                    }
                }
            }
            else if(d=='E'){
                nx = cx + commands[i];
                if(vy.count(cy)){
                    auto it = vy[cy].upper_bound(cx);
                    if(it != vy[cy].end() && *it <= nx){
                        nx = *it - 1;
                    }
                }
            }
            else{ // W
                nx = cx - commands[i];
                if(vy.count(cy)){
                    auto it = vy[cy].lower_bound(cx);
                    if(it != vy[cy].begin()){
                        --it;
                        if(*it >= nx){
                            nx = *it + 1;
                        }
                    }
                }
            }

            cx = nx;
            cy = ny;

            ans = max(ans, cx*cx + cy*cy);
        }

        return ans;
    }
};