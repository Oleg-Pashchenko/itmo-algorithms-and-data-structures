//
// Created by Oleg Pashchenko on 11.03.2023.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> flowers(n);
    for (int i = 0; i < n; i++) {
        cin >> flowers[i];
    }
    if (n == 1) {
        cout << "1 1" << endl;
    } else {
        int max_left_index = 0, max_right_index = 0, current_left_index = 0;
        for (int i = 1; i < n; i++) {
            int flower = flowers[i];
            if (i == n - 1) {
                if (i - current_left_index > max_right_index - max_left_index) {
                    max_left_index = current_left_index;
                    max_right_index = i;
                }
                break;
            }
            int next_flower = flowers[i + 1];
            int previous_flower = flowers[i - 1];
            if (previous_flower == flower && flower == next_flower) {
                if (i - current_left_index > max_right_index - max_left_index) {
                    max_left_index = current_left_index;
                    max_right_index = i;
                }
                current_left_index = i;
            }
        }
        cout << max_left_index + 1 << " " << max_right_index + 1 << endl;
    }
    return 0;
}
