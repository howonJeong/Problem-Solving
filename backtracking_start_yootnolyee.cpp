#include <iostream>
using namespace std;

int n,m,k;
int ans;
int players[4]={1,1,1,1}, distances[12];

int calc(){
    int score = 0; 
    for(int i = 0 ; i<k; i++)   score+=(players[i]>=m);
    return score;
}

void find_max(int cnt){
    ans = max(ans, calc());
    if(cnt == n)    return; 
    for(int i = 0; i<k; i++){
        if(players[i]>=m)   continue; //break 아님!
        players[i] += distances[cnt];
        find_max(cnt+1);
        players[i] -= distances[cnt];
    }
}

int main(){
    cin >> n >> m >> k;
    for(int i = 0; i<n; i++)    cin >> distances[i];
    find_max(0);
    cout << ans;
    return 0; 
}
