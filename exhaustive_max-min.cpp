#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> lst(n);
    for (int i = 0; i < n; i++)
        cin >> lst[i];

    sort(lst.begin(), lst.end());
    int min_val = lst[0];
    int max_val = lst[n - 1];

    int res = INT_MAX;

    for (int i = min_val; i <= max_val; i++) {
        int tmp = 0;
        for (int j = 0; j < n; j++) {
            if (lst[j] >= i && lst[j] <= i + k)
                continue;
            tmp += min(abs(lst[j] - i), abs(lst[j] - (i + k)));
        }
        res = min(res, tmp);
    }

    cout << res << endl;
    return 0;
}
