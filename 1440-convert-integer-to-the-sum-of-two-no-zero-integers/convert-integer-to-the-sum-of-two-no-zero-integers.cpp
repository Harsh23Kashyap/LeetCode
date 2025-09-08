class Solution {
public:
    bool contains(int n){
        string k=to_string(n);
       if(k.find('0')==string::npos)
       return true;
       return false;
    }
    vector<int> getNoZeroIntegers(int n) {
       
       for(int i=1;i<n;i++){
        if(contains(i) and contains(n-i)){
            return {i,n-i};
        }
       }
       return {-1,-1};
    }
};