class Solution {
public:
int time(int a ,int b, int x, int y){
    int t=0;
    int modmov1=abs(x-a),modmov2=abs(y-b);
    int wewillmove=min(modmov1,modmov2);
    // cout<<wewillmove<<endl;
    int verticalmove=max(modmov1,modmov2);
    
    return wewillmove+(verticalmove-wewillmove);
    
}
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        
        int t=0;

        for(int i=0;i<points.size()-1;i++){
            t+=time(points[i][0],points[i][1],points[i+1][0],points[i+1][1]);
        }
        return t;
    }
};