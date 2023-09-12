
#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
//#include<conio.h>
class Solution {
public:
    bool isPalindrome(string s) {
        // only storing alphanumeric characters in temp string;
        string temp  = "";
        for(int i=0; i<s.length(); i++){
            if( isalpha(s[i])  || isdigit(s[i])){
               //temp.append(s[i]);
                temp+= s[i];
            }
        }
        //transform(temp.begin(), temp.end(), tolower);  // i dont know how to use this transform ()
        
        // convrting to lower case
        for(int i=0; i<temp.length(); i++){
            temp[i] = tolower(temp[i]);
        }
        
        cout<<temp<<endl;
        for(int i=0; i<temp.length()/2 ; i++){
             if(temp[i] != temp[temp.length()-1-i]){
                 return false;
             }
        }
        return true;
    }
};
