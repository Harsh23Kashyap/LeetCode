class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {

stringstream ss(sentence);
string a;
int c=1;
while(ss>>a)
{
        size_t position = a.find(searchWord);
        if (position != std::string::npos) {
            if(position==0)
            return c;
        }
            c++;
}
       
        return -1;
    }
};