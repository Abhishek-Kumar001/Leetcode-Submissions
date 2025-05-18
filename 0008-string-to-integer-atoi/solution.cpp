class Solution {
public:
    int myAtoi(string s) {

        // finding the 1st ans-space index i.e igansring the white space
        int index = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i] != ' '){
                index = i;
                break;
            }
        }
        cout<<index;

        // checking after removind the white-spaces is the 1st letter is ('-' or '+') or anst
        bool isNegative = false;
        if(s[index] == '-'){
            isNegative = true;
            cout<<"negative found"<<endl;
            index++;  // vvvvvi
        } 
        else if(s[index] == '+') index++;  // vvvvvvi



        // now from here if found number then add it otherwise break and return ans;
        int ans = 0;
        cout<<"index = "<<index<<endl;
        for(int i=index; i<s.length(); i++){
            int currans = s[i]-48;
           
            cout<<"index= "<<i<<"  ans="<<ans;
            if(currans  >= 0  && currans <=9){
                // if(ans <= INT_MAX/10)
                //    if(ans == INT_MAX/10){
                //         if( currans <= 7) ans = (ans*10) + (currans);
                //         else{
                //             if(isNegative) return INT_MIN;
                //             else return INT_MAX;
                //         }
                //    }else{
                //         ans = (ans*10) + (currans);
                //    }
                  
                // else {
                //     // i thing this else code will never execute b/c if ans exceed int range we 
                //     // return from above if block
                //
                //     if(isNegative) return INT_MIN;
                //     else return INT_MAX;
                // }


                
                // THIS METHOD IS BETTER THAN ABOVE ONE
                if(ans > INT_MAX/10) return isNegative ? INT_MIN : INT_MAX;

                ans*=10;
                if((INT_MAX - ans) < (s[i]-48))  return isNegative ? INT_MIN : INT_MAX;
                ans += (s[i] - 48);
                cout<<s[i]<<"  "<<ans<<endl;
            }
            else break;

            cout<<"index= "<<i<<"  ans="<<ans;
        }
        return isNegative? -ans: ans;

    }
};
