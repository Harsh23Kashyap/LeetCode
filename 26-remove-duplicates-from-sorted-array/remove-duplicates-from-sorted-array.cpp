class Solution {
public:
    int removeDuplicates(vector<int>& arr) { 
         int i=0,j=0;
        while( j+1<arr.size()){
            if(arr[j]==arr[j+1])
            {
                j++;
            }
            else{
                arr[i]=arr[j];
                i++;
                j++;  
                
            }
        }
        arr[i] = arr[j];
        i++;
        return i; 
    }
};