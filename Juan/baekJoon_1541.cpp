#include <iostream>
#include <string>
using namespace std;
 
int main() {
    string equation = "";
    cin  >> equation;
 
    int result = 0;
    string num;
    bool isMinus = false;
 
    for (int i = 0; i <= equation.size(); i++) {
        
        if (equation[i] == '-' || equation[i] == '+' || i==equation.size()) {
            if (isMinus) {
                result -= stoi(num);
                num = "";
            }
            else {
                result += stoi(num);
                num = "";
            }
        }
        else {
            num += equation[i];
        }
 
        if (equation[i] == '-') {
            isMinus = true;
        }    
    }
    
    cout << result;
}