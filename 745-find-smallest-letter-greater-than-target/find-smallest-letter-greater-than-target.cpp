class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // char ch=letters[0];
        // for(auto it:letters){
        //     if(it>target){
        //         return it;
        //     }
        // }
        // return ch;
        target++;
        cout<<target<<endl;
        int it=lower_bound(letters.begin(),letters.end(),target)-letters.begin();
        if(it==letters.size())
            return letters[0];

        return letters[it];
    }
};