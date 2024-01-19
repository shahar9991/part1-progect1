#include <iostream>
#include <sstream>
#include <vector>
#include <cctype>
using  namespace std;

bool isNumeric(const string& str) {
    for (char ch : str) {
        if(!isdigit(ch) && ch!=' ') {
            return false;
        }
    }
    return true;
}
int edit_string(string str){
    int i=0;

    bool only_digit = isNumeric(str);
    if(only_digit) {
        istringstream iss(str);
        string token;
        vector<string> tokens;

        while (getline(iss, token, ' ')) {
            tokens.push_back(token);
        }

        // Displaying the tokens
        for (const auto &t: tokens) {
            i=i+1;

//            cout << t << endl;
//          int intValue = stoi(t);
//            if(i>0 && intValue>2){
//                return false;
//            }
//
        }

        return i;
    }
    else{

        return 0;
    }
}
int main(){
    string inputString = "1 2 3";
    int x=edit_string(inputString);
    cout<<"x"<<x;
    return 0;
}