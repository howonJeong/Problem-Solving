#include <iostream>
#include <vector>

#define MAX_N 8

using namespace std;

int n;
bool visited[MAX_N+1];
vector<int> picked;

void per(int cnt){
    if(cnt==n){
        for(int i = 0 ; i< (int) picked.size(); i++)    cout << picked[i] << " ";
        cout << endl;
        return;
    }

    for(int i = n; i >= 1; i--) {
        if(visited[i]) continue;
        visited[i] = true;
        picked.push_back(i);

        per(cnt + 1);

        visited[i] = false;
        picked.pop_back();
    }
}

int main() {
    cin >> n;

    per(0);
    return 0;
}