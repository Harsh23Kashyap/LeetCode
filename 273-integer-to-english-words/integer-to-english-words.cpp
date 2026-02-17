class Solution {
public:
    
    vector<string> below20 = {
        "", "One", "Two", "Three", "Four", "Five", "Six", "Seven",
        "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen",
        "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
    };
    
    vector<string> tens = {
        "", "", "Twenty", "Thirty", "Forty",
        "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
    };
    
    vector<string> thousands = {"", "Thousand", "Million", "Billion"};
    
    
    string helper(int num) {
        string res = "";
        
        int hundred = num / 100;
        int rest = num % 100;
        
        if (hundred != 0) {
            res += below20[hundred] + " Hundred";
        }
        
        if (rest != 0) {
            if (!res.empty()) res += " ";
            
            if (rest < 20) {
                res += below20[rest];
            } else {
                int ten = rest / 10;
                int one = rest % 10;
                
                res += tens[ten];
                
                if (one != 0)
                    res += " " + below20[one];
            }
        }
        
        return res;
    }
    
    
    string numberToWords(int num) {
        
        if (num == 0)
            return "Zero";
        
        string result = "";
        int index = 0;
        
        while (num > 0) {
            
            int chunk = num % 1000;
            
            if (chunk != 0) {
                string part = helper(chunk);
                
                if (!thousands[index].empty())
                    part += " " + thousands[index];
                
                if (!result.empty())
                    result = part + " " + result;
                else
                    result = part;
            }
            
            num /= 1000;
            index++;
        }
        
        return result;
    }
};
