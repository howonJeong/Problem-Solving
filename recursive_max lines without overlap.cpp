// 안겹치는 최대 선분 갯수
// 점 주면 안겹치는 선분 갯수 몇개인지 출력


#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;
pair<int, int> points[15];
vector<pair<int,int>> chk;

int n;
int ans;
//만난다가 아니고 '겹친다'.
//그래서 선분 위에 점이 있는지 확인해보면 된다.

bool doesinclude(pair<int, int> a, pair<int, int> b){
    int ax1, ax2, bx1, bx2;
    tie(ax1, ax2) = a;
    tie(bx1, bx2) = b;

   return   (ax1 <= bx1 && bx1 <= ax2) || (ax1 <= bx2 && bx2 <= ax2) || (bx1 <= ax1 && ax1 <= bx2) || (bx1 <= ax2 && ax2 <= bx2);
   // 왼쪽 일부 겹침, 전부 겹침, 전부 겹침, 오른쪽 일부 겹침 (x나 y 중 하나만 볼 시)
    // 제출하고 생각해보니 slope랑 점 하나 가지고 비교하면 더 간단할 것 같다.

}

bool ok(){
    for(int i = 0 ; i< (int)chk.size(); i++)
        for(int j = i+1; j < (int)chk.size(); j++)
            if(doesinclude(chk[i], chk[j])) return false;
    //chk i+1 부터는 y좌표 포함
    return true;
}


void findmax(int cnt){
    if(cnt==n){
        if(ok())    ans = max(ans, (int) chk.size());
        return;
    }

    chk.push_back(points[cnt]);
    findmax(cnt+1);
    chk.pop_back();

    findmax(cnt+1);
}
int main() {
    cin >> n;
    int x1,x2;
    for (int i = 0; i < n; i++) {
        cin >> x1 >> x2;
        points[i] = make_pair(x1, x2);
    }

	findmax(0);
    cout << ans;
    return 0;
}
