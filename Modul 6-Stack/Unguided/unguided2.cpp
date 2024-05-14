#include <iostream>
#include <string>
#include <stack>

using namespace std;

void reverseSentence(string sentence) {
    stack<char> s;
    for (char c : sentence) {
        s.push(c);
    }
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
}

int main() {
    string sentence = "Today is Tuesday";
    cout << "Original sentence: " << sentence << endl;
    cout << "Reversed sentence: ";
    reverseSentence(sentence);
    cout << endl;
    return 0;
}