class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.size()-1, j=b.size()-1;
        string ans = "";
        int carry = 0;
        while(i>=0 && j>=0){
            int sum = 0;

            sum+= a[i]-'0';
            sum+= b[j]-'0';
            sum+=carry;

            ans+= ((sum % 2) + '0') ;
            
            if(sum >= 2) carry = 1;
            else carry = 0;

            i--; j--;
        }

        while(i>=0){
            int sum = 0;

            sum+= a[i]-'0';
            sum+=carry;

            ans+= ((sum % 2) + '0') ;
            
            if(sum >= 2) carry = 1;
            else carry = 0;

            i--;
        }

        while(j>=0){
            int sum = 0;

            sum+= b[j]-'0';
            sum+=carry;

            ans+= ((sum % 2) + '0') ;
            
            if(sum >= 2) carry = 1;
            else carry = 0;

            j--;
        }
        // vvi step
        cout<<"carry="<<carry<<endl;
        if(carry == 1){
            ans+="1";
        }

        reverse(ans.begin(), ans.end());
        cout<<"ans ="<<ans<<endl;

        return ans;
    }
};
