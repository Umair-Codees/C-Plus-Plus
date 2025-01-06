#include <iostream>
#include <string>
using namespace std;

bool palindrom(string& str, int i) {
    if (i >= str.length() / 2) {
        return true;
    }
    if (str[i] == str[str.length() - 1 - i]) {
        return palindrom(str, ++i);
    }
    else {
        return false;
    }
}

int main() {
    string str;
    cout << "Enter string ..) ";
    cin >> str;

    if (palindrom(str, 0)) {
        cout << "\nString is Palindrom" << endl << endl;
    }
    else {
        cout << "\nString is Not Palindrom" << endl << endl;
    }
    return 0;
}