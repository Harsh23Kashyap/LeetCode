class Solution {
public:
int m=1e9+7;
long long fact(int a){
    if(a<=1)
        return 1;
    return (a*fact(a-1)%m)%m;
}
    int countPermutations(vector<int>& c) {
        int mini=*min_element(c.begin()+1,c.end());
        if(mini<=c[0])
            return 0;
        return fact(c.size()-1)%m;

    }
};

/*
1 2 3 5 6 2

6

*/