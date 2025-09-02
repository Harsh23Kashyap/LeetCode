class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
            int c=0;
        sort(points.begin(),points.end());

        for(int i=0;i<points.size();i++){
            for(int j=0;j<points.size();j++){
                if(i==j)
                    continue;
                // cout<<points[i][0]<<","<<points[i][1]<<" -> "<<points[j][0]<<","<<points[j][1]<<endl;
                if((points[i][0]<points[j][0] and points[i][1]>=points[j][1]) or (points[i][0]<=points[j][0] and points[i][1]>points[j][1])){
                    // cout<<"here"<<endl;
                    bool cond=true;
                    for(int k=0;k<points.size();k++){
                        if(k==i or k==j)
                            continue;
                        if((points[i][0]<=points[k][0] and points[k][0]<=points[j][0]) and (points[j][1]<=points[k][1] and points[k][1]<=points[i][1])){
                            cond=false;
                            break;
                        }
                    }
                    if(cond)
                        c++;
                }

            }
           
        }
         return c;
    }
};