#include <bits/stdc++.h>

using namespace std;
const int MAXN = 100100;
#define int long long

int k, b, n, ans;
int v[MAXN];
unordered_map<int, int> dp;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(0);

    cin >> k >> b >> n;
    for(int i = 1;i <= n;i++)
        cin >> v[i];

    int sum = 0, z = 0;
    dp[0]++;
    for(int i = 1, cnt = 0;i <= n;i++){
        sum = (sum + v[i]) % (k - 1);
        ans += dp[(sum - b + k - 1) % (k - 1)];
        dp[sum]++;
        if(v[i] == 0)
            z += ++cnt;
        else
            cnt = 0;
    }
    if(b == 0)
        ans = z;
    if(b == k - 1)
        ans -= z;

    cout << ans << "\n";
}