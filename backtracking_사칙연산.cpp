#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

string str;
int ans = INT_MIN;

void solve(int local, int charToInt[]) {
    if (local == static_cast<int>('f') + 1) {
        int num = charToInt[str[0]];

        for (size_t i = 2; i < str.length(); i += 2) {
            char temp = str[i - 1];
            if (temp == '-') {
                num -= charToInt[str[i]];
            } else if (temp == '+') {
                num += charToInt[str[i]];
            } else {
                num *= charToInt[str[i]];
            }
        }

        ans = max(ans, num);
        return;
    }

    for (int i = 1; i <= 4; i++) {
        charToInt[local] = i;
        solve(local + 1, charToInt);
        charToInt[local] = 1;
    }
}

int main() {
    cin >> str;
    int charToInt[128] = {0};

    solve(static_cast<int>('a'), charToInt);
    cout << ans << endl;

    return 0;
}
