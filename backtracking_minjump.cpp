#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 10
using namespace std;

int n;
int grid[MAX_N][MAX_N];
bool visited[MAX_N];
vector<int> picked;

int ans;

void findmax(int row){
    if(row==n){
        int sum = 0;
        for(int i = 0; i < (int)picked.size(); i++)   sum += grid[i][picked[i]];

        ans = max(ans, sum);
        return;
    }

    for(int i = 0; i < n; i++) {
        if(visited[i]) continue;
        visited[i] = true;
        picked.push_back(i);

        findmax(row + 1);

        visited[i] = false;
        picked.pop_back();
    }
}

int main() {
    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];

    findmax(0);

    cout << ans;
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minJumps(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) return 0;
    if (nums[0] == 0) return -1;

    int maxReach = nums[0];
    int step = nums[0];
    int jumps = 1;

    for (int i = 1; i < n; ++i) {
        if (i == n - 1) return jumps;

        maxReach = max(maxReach, i + nums[i]);
        step--;

        if (step == 0) {
            jumps++;
            if (i >= maxReach) return -1;
            step = maxReach - i;
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << minJumps(nums);
    

    return 0;
}
