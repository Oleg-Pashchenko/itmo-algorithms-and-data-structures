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

void blockStart() {
    operationsHistory.emplace();
}

void blockEnd() {
    for (auto &[k, v]: operationsHistory.top()) {
        variables[k] += v;
    }
    operationsHistory.pop();
}

void assignVariable(const string &key, const string &value) {
    if (!isMapContainsKey(operationsHistory.top(), key)) {
        operationsHistory.top()[key] = getValue(key);
    }
    if (isInt(value)) {
        variables[key] = stoi(value);
    } else {
        variables[key] = getValue(value);
        cout << variables[key] << endl;
    }
    operationsHistory.top()[key] -= getValue(key);
}


int main() {
    string line, key, value;

    blockStart();
    while (getline(cin, line)) {
        if (line == "{") {
            blockStart();
        } else if (line == "}") {
            blockEnd();
        } else {
            key = line.substr(0, line.find('='));
            value = line.substr(line.find('=') + 1);
            assignVariable(key, value);
        }
    }

    return 0;
}
