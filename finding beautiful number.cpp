// 122333 이런 수 찾기
// 222는 안된다는 것 기억


#include <iostream>
#include <string>
using namespace std;

int n;

bool arum(const string& num) {
    if (num.empty()) return true;
    char now = num[0];
    int count = 0;
    for (int i = 0; i < num.size(); i++) {
        if (num[i] == now) count++;
        else break;
    }
    if (count % (now - '0') != 0) return false; // 나머지 말고 그냥 now-0 하면 2가 4번, 6번.. 3이 6번 9번.. 나오는 것 같은 경우가 miss
    return arum(num.substr(count));
}

int quantchk(int n, string str_now) {
    if (str_now.size() == n) return arum(str_now) ? 1 : 0;
    int count = 0;
    for (char digit = '1'; digit <= '4'; digit++) {
        count += quantchk(n, str_now + digit);
    }
    return count;
}

int main() {
    cin >> n;
    cout << quantchk(n, "") << endl;
    return 0;
}
