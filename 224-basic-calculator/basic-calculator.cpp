class Solution {
public:
int solve(const string &expr) {
    int result = 0;
    int number = 0;
    int sign = 1;

    for (int i = 0; i < (int)expr.size(); ++i) {
        char c = expr[i];
        if (c>='0' and c<='9') {
            number = number * 10 + (c - '0');
        } else if (c == '+') {
            if(i+1<expr.size()){
                result += sign * number;
            number = 0;
            sign = -1;
                if(expr[i+1]=='+'){
                    sign=1;
                    i++;
                    continue;
                }
                if(expr[i+1]=='-'){
                    result += sign * number;
            number = 0;
            sign = -1;
                    sign = -1;
                     i++;
                    continue;
                }
            }
            result += sign * number;
            number = 0;
            sign = 1;
        } else if (c == '-') {
            if(expr[i+1]=='+'){
                result += sign * number;
            number = 0;
            sign = -1;
                    sign=-1;
                    i++;
                    continue;
                }
                if(expr[i+1]=='-'){
                    result += sign * number;
            number = 0;
            sign = -1;
                    sign = 1;
                     i++;
                    continue;
                }
            result += sign * number;
            number = 0;
            sign = -1;
        }
       
    }
    result += sign * number;
    cout<<result<<endl;
    return result;
}

// Calculate function: handles parentheses and calls solve for substrings
int calculate(string s) {
    stack<string> st;  
    string curr = "";

    for (char c : s) {
        if (c == '(') {
            st.push(curr);
            curr = "";
        } else if (c == ')') {
            int val = solve(curr);
            curr = st.top(); 
            st.pop();
            curr += to_string(val);
        } else {
            if (c != ' ') 
                curr += c;
        }
    }

    // Solve whatever is left in curr after processing all parentheses
    return solve(curr);
}
   
};