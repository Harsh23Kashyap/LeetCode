class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) 
    {
        for(int i=0;i<matrix.size();i++)
        {
            set<int> s;
            for(int j=0;j<matrix[i].size();j++)
                s.insert(matrix[i][j]);
            if(s.size()!=matrix.size()) 
                return false;
        }
        for(int i=0;i<matrix.size();i++)
        {
            set<int> s;
            for(int j=0;j<matrix[i].size();j++)
                s.insert(matrix[j][i]);
            if(s.size()!=matrix.size()) 
                return false;
        }
        return true;
    }
};