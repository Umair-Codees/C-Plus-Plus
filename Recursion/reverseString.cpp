#include <iostream>
#include <string>
using namespace std;

string reverse(string& str, int i) {
    if (i >= str.length() / 2) {
        return str;
    }
    swap(str[i], str[str.length() - 1 - i]);
    return reverse(str, ++i);
}

int main() {
    string str;
    cout << "Enter string ..) ";
    cin >> str;

    cout << "\nOrignal String is ... " << str << endl << endl;
    cout << "After Reverse String becomes ... " << reverse(str, 0) << endl;
    return 0;
}
