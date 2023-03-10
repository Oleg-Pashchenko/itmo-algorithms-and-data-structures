#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

unordered_map <string, int> variables;
stack <unordered_map<string, int>> order;


int getValue(const string& key) {
    if (variables.find(key) == variables.end()) variables[key] = 0;
    return variables[key];
}


bool isInt(const string& possibleInt) {
    bool result;
    try {
        stoi(possibleInt);
        result = true;
    } catch (invalid_argument& e) {
        result = false;
    }
    return result;
}


int main() {
    string line, key, value;
    while (getline(cin, line)) {
        if (line == "{") {
            order.push(variables);
        }
        else if (line == "}") {
            variables = order.top();
            order.pop();
        }
        else {
            key = line.substr(0, line.find('='));
            value = line.substr(line.find('=') + 1);
            if (isInt(value)) {
                variables[key] = stoi(value);
            } else {
                variables[key] = getValue(value);
                cout << variables[key] << endl;
            }
        }
    }
    return 0;
}
