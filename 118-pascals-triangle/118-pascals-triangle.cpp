class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ps= { { 1 },{ 1, 1 }};
        if(numRows==1)
            return vector<vector<int>> {{1}};
        else if (numRows==2)
            return ps;
        else
        {
            for (int i=2;i<numRows;i++)
            {
                vector <int> v {1};
                for(int j=1;j<ps[i-1].size();j++)
                    v.push_back(ps[i-1][j-1]+ps[i-1][j]);
                v.push_back(1);
                ps.push_back(v);
            }
             
        }
        return ps;
    }
};