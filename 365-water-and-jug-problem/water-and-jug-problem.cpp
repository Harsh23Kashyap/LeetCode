class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        
        queue<pair<int,int>> q;

        q.push({0,0});

        set<pair<int,int>> s;
        s.insert({0,0});    

        //options we  list down
        //empty x keep y
        //empty y keep x;
        //fill x completely keep y
        //fill y completely keep x
        //transfer contents of x to y;
        //transfer contents of y to x


        while(!q.empty()){
            auto [cx,cy]=q.front();
            q.pop();
            if(cx==target or cy==target or cx+cy==target)
                return true;

            if(!s.count({0,cy})){
                s.insert({0,cy});
                q.push({0,cy});
            }
            if(!s.count({cx,0})){
                s.insert({cx,0});
                q.push({cx,0});
            }
            if(!s.count({x,cy})){
                s.insert({x,cy});
                q.push({x,cy});
            }
            if(!s.count({cx,y})){
                s.insert({cx,y});
                q.push({cx,y});
            }
            //trying to fill x using y completely
            // pour x -> y
            int transfer = min(cx, y - cy);
            int nx = cx - transfer;
            int ny = cy + transfer;

            if(!s.count({nx, ny})){
                s.insert({nx, ny});
                q.push({nx, ny});
            }

            // pour y -> x
            transfer = min(cy, x - cx);
            nx = cx + transfer;
            ny = cy - transfer;

            if(!s.count({nx, ny})){
                s.insert({nx, ny});
                q.push({nx, ny});
            }
           

        }
        return false;
    }
};