class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> u;
        for(char ch:s)
        u[ch]++;
        int vm=0,cm=0;
        for(auto it: u){
            if(it.first=='a' or it.first=='e' or it.first=='o' or it.first=='u' or it.first=='i'){
                vm=max(vm,it.second);
            }
            else
            {
                cm=max(cm,it.second);
            }
        }
        return vm+cm;
    }
};