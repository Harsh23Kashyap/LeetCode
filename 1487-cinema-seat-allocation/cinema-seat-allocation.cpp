class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int ans=0;
        unordered_map<int,unordered_set<int>> u;
        for(auto it:reservedSeats)
            u[it[0]].insert(it[1]);
        int c=0;
        for(auto it:u){
                int i=it.first;
                //three cases

                //if not in 2,3,4,5,6,7,8,9
                if(!(u[i].count(2) or u[i].count(3) or u[i].count(4) or u[i].count(5) or u[i].count(6) or u[i].count(7) or u[i].count(8) or u[i].count(9))){
                c+=2;
                }

                //notin 4,5,6,7
                else if(!( u[i].count(4) or u[i].count(5) or u[i].count(6) or u[i].count(7)))
                c++;
                 //notin 2,3,4,5
                else if(!( u[i].count(4) or u[i].count(5) or u[i].count(2) or u[i].count(3)))
                c++;
                else if(!( u[i].count(6) or u[i].count(7) or u[i].count(8) or u[i].count(9)))
                c++;




            // cout<<c<<endl;

                
            
        }

        return c+(n-u.size())*2;
    }
};