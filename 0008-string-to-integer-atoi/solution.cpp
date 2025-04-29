class Solution {
public:
    int myAtoi(string s) {
        // remove the starting space
        int index = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == ' '){
                index++;
                continue;
            }else break;
        }
        cout<<"starting index = "<<index<<endl;

        int ans = 0;
        bool negativeOrNot = false;
        bool foundDigitAlready = false;
        bool minusOrPlusFoundAlready = false;
        for(int i=index; i<s.length(); i++){
            if(s[i] == ' ' )return negativeOrNot ? -ans: ans;  // we have found space after char

            if(s[i] == '-' || s[i] == '+'){
                if(minusOrPlusFoundAlready) return negativeOrNot ? -ans: ans;

                minusOrPlusFoundAlready = true;
                if(foundDigitAlready){
                    cout<<s[i]<<" found and foundDigitAlready is also true so returned";
                    return negativeOrNot ? -ans: ans;

                }
                if(s[i] == '-')
                  negativeOrNot = true;
            } 
            else if(s[i] > 58 || s[i] < 48){
                cout<<"non-negative ingerger found "<<s[i];
                return  negativeOrNot ? -ans: ans;
 
            } 
            else{
                foundDigitAlready = true;
                if(ans > INT_MAX/10) return negativeOrNot ? INT_MIN : INT_MAX;

                ans*=10;
                if((INT_MAX - ans) < (s[i]-48))  return negativeOrNot ? INT_MIN : INT_MAX;
                ans += (s[i] - 48);
                cout<<s[i]<<"  "<<ans<<endl;
            }
        }
        cout<<"return at the end";
        return  negativeOrNot ? -ans: ans;
        
    }
};
