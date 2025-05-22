class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        
        int i=0,j=1;
        while(i<arr.size() and j<arr.size()){
            if(arr[i]==arr[j])
            {
                j++;
            }
            else{
                i++;
                arr[i]=arr[j];
            }
        }
        return i+1;
    }
};