#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;


unordered_map<string, int> variables;
stack<unordered_map<string, int>> operationsHistory;


int getValue(const string &key) {
    if (variables.find(key) == variables.end()) variables[key] = 0;
    return variables[key];
}

bool isInt(const string &possibleInt) {
    try {
        stoi(possibleInt);
        return true;
    } catch (invalid_argument &e) {
        return false;
    }
}

bool isMapContainsKey(const unordered_map<string, int> &map, const string &key) {
    return (map.count(key) != 0);
}


int main() {
    string line, key, value;
    operationsHistory.emplace();

    while (getline(cin, line)) {

        if (line == "{") operationsHistory.emplace();
        else if (line == "}") {
            for (auto &[k, v]: operationsHistory.top()) {
                variables[k] += operationsHistory.top()[k];
            }
            operationsHistory.pop();
        } else {
            key = line.substr(0, line.find('='));
            value = line.substr(line.find('=') + 1);

            if (!isMapContainsKey(operationsHistory.top(), key)) {
                operationsHistory.top()[key] = variables[key];
            }

            if (isInt(value)) {
                variables[key] = stoi(value);
            } else {
                variables[key] = getValue(value);
                cout << variables[key] << endl;
            }

            operationsHistory.top()[key] -= variables[key];
        }
    }
    return 0;
}
