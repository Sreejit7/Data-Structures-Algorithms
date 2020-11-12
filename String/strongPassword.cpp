/**
Louise joined a social networking site to stay in touch with her friends. 
The signup page required her to input a name and a password. However, the password must be strong. 
The website considers a password to be strong if it satisfies the following criteria:

    Its length is at least .
    It contains at least one digit.
    It contains at least one lowercase English character.
    It contains at least one uppercase English character.
    It contains at least one special character. The special characters are: !@#$%^&*()-+

She typed a random string of length  in the password field but wasn't sure if it was strong. 
Given the string she typed, can you find the minimum number of characters she must add to make her password strong?
**/

//Approach: O(n) time & space
#include <bits/stdc++.h>
using namespace std;
int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong
    vector <bool> strong(5,false);
    if(n >= 6){
        strong[0] = true;
    }
    for(int i = 0; i < n; i++){
        if(password[i] >= 48 && password[i] <= 57)
            strong[1] = true;
        else if(password[i] >= 97 && password[i] <= 122)
            strong[2] = true;
        else if(password[i] >= 65 && password[i] <= 90)
            strong[3] = true;
        else if(password[i] >= 33 && password[i] <= 45)
            strong[4] = true;
    }
    int count = 0;
    for(int i = 0; i <5; i++){
        if(!strong[i])
            count++;
    }
    if(!strong[0] && n + count > 6)
        return count - 1;
    if(n + count < 6)
        return  count + (6 - n - count);
    return count;
}
int main(){
    string password;
    cin>>password;
    int n = password.length();
    cout<<minimumNumber(n,password)<<endl;
}