class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {

        int n = words.size();
        vector<int> pref(n+1,0);

        for(int i=0;i<n;i++)
            pref[i+1] = pref[i] + words[i].size();

        vector<string> ans;

        int i = 0;

        while(i < n){

            int j = i;
 
            while(j < n){
                int len = pref[j+1] - pref[i];
                int gaps = j - i;
                if(len + gaps <= maxWidth) j++;
                else break;
            }

            j--;

            int wordsLen = pref[j+1] - pref[i];
            int gaps = j - i;
            int spaces = maxWidth - wordsLen;

            string line = "";
 
            if(j == n-1 || gaps == 0){

                for(int k=i;k<=j;k++){
                    line += words[k];
                    if(k != j) line += " ";
                }

                line += string(maxWidth - line.size(),' ');
            }
            else{

                int each = spaces / gaps;
                int extra = spaces % gaps;

                for(int k=i;k<=j;k++){

                    line += words[k];

                    if(k < j){
                        line += string(each,' ');
                        if(extra > 0){
                            line += " ";
                            extra--;
                        }
                    }
                }
            }

            ans.push_back(line);
            i = j + 1;
        }

        return ans;
    }
};