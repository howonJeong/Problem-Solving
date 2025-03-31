#include <iostream>
#include <vector>
#define MAX_N 8

using namespace std;

int n;
bool visited[MAX_N+1];
vector<int> picked;

void perm(int cnt){
    if(cnt==n){
        for(int i = 0 ; i < picked.size(); i++) cout << picked[i] << " ";
        cout << endl;
        return;
    }
    
    // backtracking part
    for(int i = n; i>0 ; i--){
        //종료조건
        if(visited[i])    continue;
        //
        visited[i] = true;
        picked.push_back(i);
        perm(cnt+1);
        picked.pop_back();
        visited[i] = false;
    }
}

int main(void){
    cin >> n;
    perm(0);
}