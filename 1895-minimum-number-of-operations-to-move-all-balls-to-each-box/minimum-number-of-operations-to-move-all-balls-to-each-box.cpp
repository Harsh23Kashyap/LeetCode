class Solution {
public:
    vector<int> minOperations(string boxes) {
       vector<int> ans;

       for(int i=0;i<boxes.size();i++){
        int j=0;
        for(int k=0;k<boxes.size();k++)
        {
            if(boxes[k]=='1')
            j+=abs(k-i);
        }
        ans.push_back(j);
       } 
       return ans;
    }
};