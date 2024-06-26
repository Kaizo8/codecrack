//AUTHOR : ANKUR
#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<long long> L(n + 1, 0);
  for (int i = 0; i < n; i++){
    L[i + 1] = __gcd(L[i], a[i]);
  }
  vector<long long> R(n + 1, 0);
  for (int i = n - 1; i >= 0; i--){
    R[i] = __gcd(R[i + 1], a[i]);
  }
  vector<long long> B(n);
  for (int i = 0; i < n; i++){
    B[i] = __gcd(L[i], R[i + 1]);
  }
  long long ans = B[0];
  for (int i = 1; i < n; i++){
    ans = (ans*B[i]) / __gcd(ans,B[i]);
  }
  cout << ans << endl;
}