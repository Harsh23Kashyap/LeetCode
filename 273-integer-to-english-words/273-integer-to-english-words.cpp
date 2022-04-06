class Solution {
public:
    string less10(int no)
    {
        switch(no)
        {
            case 1: return "One";
            case 2: return "Two";
            case 3: return "Three";
            case 4: return "Four";
            case 5: return "Five";
            case 6: return "Six";
            case 7: return "Seven";
            case 8: return "Eight";
            case 9: return "Nine";
                
        }
        return "";
    }
    string less20(int no)
    {
        switch(no)
        {
            case 11: return "Eleven";
            case 12: return "Twelve";
            case 13: return "Thirteen";
            case 14: return "Fourteen";
            case 15: return "Fifteen";
            case 16: return "Sixteen";
            case 17: return "Seventeen";
            case 18: return "Eighteen";
            case 19: return "Nineteen";
                
        }
        return "";
    }
    string tensPlace(int no)
    {
        switch(no)
        {
            case 1: return "Ten";
            case 2: return "Twenty";
            case 3: return "Thirty";
            case 4: return "Forty";
            case 5: return "Fifty";
            case 6: return "Sixty";
            case 7: return "Seventy";
            case 8: return "Eighty";
            case 9: return "Ninety";
                
        }
        return "";
    }
    string numberToWords(int num) 
    {
        if(num==0)
            return "Zero";
        string ans="";
        if(num/1000000000!=0)
        {
            ans+=less10(num/1000000000)+ " Billion ";
        }
        num=num%1000000000;
        if(num/1000000!=0)
        {
            int million=num/1000000;
            int hundred=million/100;
            int tens=(million/10)%10;
            int digits=million%10;
            if(hundred!=0)
                ans+=less10(hundred)+ " Hundred ";
            if(million%100>10 and million%100<20)
            {
                cout<<tens<<endl;
                ans+=" "+less20(tens*10+digits);
            }
            else if(million%100<10 and million%100!=0)
            {
                //cout<<tens<<endl;
                ans+=" "+less10(digits)+" ";
            }
            else if(million%100!=0)
            {
                //cout<<tens<<endl;
                ans+=" "+tensPlace(tens)+" ";
                ans+=" "+less10(digits)+" ";
            }
            
            
            
            ans+=" Million ";
        }
        num=num%1000000;
        if(num/1000!=0)
        {
            
            int million=num/1000;
            int hundred=million/100;
            int tens=(million/10)%10;
            int digits=million%10;
            if(hundred!=0)
                ans+=less10(hundred)+ " Hundred ";
            
             if(million%100>10 and million%100<20)
            {
                cout<<tens<<endl;
                ans+=" "+less20(tens*10+digits);
            }
            else if(million%100<10 and million%100!=0)
            {
                //cout<<tens<<endl;
                ans+=" "+less10(digits);
            }
            else if(million%100!=0)
            {
                cout<<tens<<endl;
                ans+=" "+tensPlace(tens);
                ans+=" "+less10(digits);
            }
            
            
            ans+=" Thousand ";
        }
        num=num%1000;
        if(num!=0)
        {
            //cout<<"Runs"<<endl;
            int million=num;
            int hundred=million/100;
            int tens=(million/10)%10;
            int digits=million%10;
            if(hundred!=0)
                ans+=less10(hundred)+ " Hundred ";
           // cout<<million%100<<endl;
            if(million%100>10 and million%100<20)
            {
                cout<<tens<<endl;
                ans+=" "+less20(tens*10+digits);
            }
            else if(million%100<10 and million%100!=0)
            {
                //cout<<tens<<endl;
                ans+=" "+less10(digits);
            }
            else if(million%100!=0)
            {
                cout<<tens<<endl;
                ans+=" "+tensPlace(tens);
                ans+=" "+less10(digits);
            }
            
            
        }
        
        stringstream s(ans);
        string temp="";
        string res="";
        while(s>>temp)
        {
            res=res+temp+" ";
        }
        return res.substr(0,res.length()-1);
    }
    
};