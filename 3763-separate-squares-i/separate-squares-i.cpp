class Solution {
public:
double possible(vector<vector<int>>& a, double x){
    double rs=0;

    for(int i=0;i<a.size();i++){
        if(a[i][1]>=x)
        break;
        double upper=a[i][1]+a[i][2];

        if(upper<=x){
            rs += (double)a[i][2] * a[i][2];
        }
        else{
            double height=x-a[i][1];
            rs+=height*a[i][2];
        }

    }

    return rs;
}
    double separateSquares(vector<vector<int>>& squares) {
        sort(squares.begin(),squares.end(),[](auto &a, auto &b){
            return a[1]<b[1];
        });
        double ts=0;
        double l=squares[0][1],h=squares.back()[1];

        for(auto it:squares){
        ts += 1.0 * it[2] * it[2];
            if(it[1]+it[2]>h)
                h=it[1]+it[2];
        } 
        while(h-l>=1e-6){
            double m=l+(h-l)/2;
            
             auto it=possible(squares,m);
            // cout<<m<<" "<<it<<endl;
             if(it>=ts/2){
                h=m;
            }
            else{
                l=m;
            }
        }
        return l;
    }
};