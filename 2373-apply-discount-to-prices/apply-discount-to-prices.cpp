class Solution {
public:
bool price(string word){
    if(word.size()==1)
    return false;
    if(word[0]!='$')
    return false;

    for(int i=1;i<word.size();i++){
        if(!isdigit(word[i]))
            return false;
    }
    return true;
}
    string discountPrices(string sentence, int discount) {
        stringstream ss(sentence);
        // double discoooo= floor(discount * 100 + 0.5) / 100; 
        string word;
        string ans="";
        while(ss>>word){
            if (price(word)){
                // cout<<word<<endl;
                long long cost=stol(word.substr(1));
                double discounted = cost * (100.0 - discount) / 100.0;

                stringstream formatted;
                formatted << fixed << setprecision(2) << discounted;
                ans += " $" + formatted.str();
            }
            else{
                ans+=" "+word;
            }
        }
        return ans.substr(1);
    }
};