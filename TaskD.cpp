//
// Created by Oleg Pashchenko on 11.03.2023.
//
#include <iostream>
using namespace std;

int main() {
    int storage, from_container, to_use, to_container, k, prev_storage;
    prev_storage = 0;
    cin >> storage >> from_container >> to_use >> to_container >> k;

    for (int i = 0; i < k; i++) {
        storage *= from_container;  // Step 1

        if (storage > to_use) {  // Step 2
            storage = storage - to_use;
        } else {
            storage = 0;
        }

        if (storage > to_container) {  // Step 3
            storage = to_container;
        }

        if (k == i + 1 || storage == prev_storage) {
            cout << storage << endl;
            break;
        }
        prev_storage = storage;
    }
    return 0;
}