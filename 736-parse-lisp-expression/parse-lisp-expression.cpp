class Solution {
public:
    int idx = 0;

    int evaluate(string expression) {
        idx = 0;
        unordered_map<string, int> scope;
        return eval(expression, scope);
    }

    int eval(string &s, unordered_map<string, int> scope) {
        // skip spaces
        while (s[idx] == ' ') idx++;

        // Expression
        if (s[idx] == '(') {
            idx++; // skip '('
            string op = parseToken(s);

            // (add e1 e2)
            if (op == "add") {
                int a = eval(s, scope);
                int b = eval(s, scope);
                idx++; // ')'
                return a + b;
            }

            // (mult e1 e2)
            if (op == "mult") {
                int a = eval(s, scope);
                int b = eval(s, scope);
                idx++; // ')'
                return a * b;
            }

            // (let v1 e1 v2 e2 ... expr)
            while (true) {
                while (s[idx] == ' ') idx++;

                // last expression
                if (s[idx] == '(' || s[idx] == '-' || isdigit(s[idx])) {
                    int val = eval(s, scope);
                    idx++; // ')'
                    return val;
                }

                string var = parseToken(s);

                // edge: "(let x 2 x)"
                if (s[idx] == ')') {
                    idx++;
                    return scope[var];
                }

                int val = eval(s, scope);
                scope[var] = val;
            }
        }

        // Variable
        if (isalpha(s[idx])) {
            string var = parseToken(s);
            return scope[var];
        }

        // Number
        return parseNumber(s);
    }

    string parseToken(string &s) {
        while (s[idx] == ' ') idx++;
        string t;
        while (idx < s.size() && s[idx] != ' ' && s[idx] != ')')
            t += s[idx++];
        while (s[idx] == ' ') idx++;
        return t;
    }

    int parseNumber(string &s) {
        int sign = 1;
        if (s[idx] == '-') sign = -1, idx++;

        int num = 0;
        while (isdigit(s[idx]))
            num = num * 10 + (s[idx++] - '0');

        return sign * num;
    }
};
