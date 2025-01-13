class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int> u;
        for(auto it:s)
            u[it]++;

        int c=0;
        for(auto it:u)
        {
            while(it.second>2)
            {
                it.second-=2;
            }
            c+=it.second;
        }
        return c;
    }
};

/*
1- 1
2-2
3- 1
4-2
5-1
6-2
7-
*/