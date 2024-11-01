#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int checkPasswordStrength(const string& password) {
    int score = 0;


    if (password.length() >= 8) score += 1;
    if (password.length() >= 12) score += 1;


    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;

    for (char ch : password) {
        if (isupper(ch)) hasUpper = true;
        else if (islower(ch)) hasLower = true;
        else if (isdigit(ch)) hasDigit = true;
        else hasSpecial = true;
    }


    if (hasUpper) score += 1;
    if (hasLower) score += 1;
    if (hasDigit) score += 1;
    if (hasSpecial) score += 1;

    return score;
}

void printStrengthMessage(int score) {
    if (score <= 2) {
        cout << "Password is weak. You should use a mix of letters, digits, and special characters." << endl;
    } else if (score <= 4) {
        cout << "Password is moderate. Add more characters for a stronger one." << endl;
    } else {
        cout << "Password is really strong, congratulations!" << endl;
    }
}

int main() {
    string password;
    cout << "Enter password to check the strength of it: ";
    cin >> password;

    int score = checkPasswordStrength(password);
    printStrengthMessage(score);

    return 0;
}
