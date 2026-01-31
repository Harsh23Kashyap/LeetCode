class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ch=letters[0];
        for(auto it:letters){
            if(it>target){
                return it;
            }
        }
        return ch;
    }
};