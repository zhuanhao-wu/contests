#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int N; vector<int> a;
  cin>>N;
  int x;
  bool all_zero = true;
  for(int i = 0; i < N; i++) { cin>>x; a.push_back(x); all_zero = all_zero && (x == 0); }

  if(N % 3 != 0) {
    if(all_zero) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  } else {
    sort(a.begin(), a.end());
    bool all_same = true;
    for(int i = 1; i < N / 3; i++) { all_same = all_same && (a[i] == a[0]); }
    for(int i = N / 3 + 1; i < 2 * (N / 3); i++) { all_same = all_same && (a[i] == a[N / 3]); }
    for(int i = 2 * (N / 3) + 1; i < N; i++) { all_same = all_same && (a[i] == a[2 * (N / 3)]); }
    bool target = a[0] ^ a[N / 2] ^ a[N - 1];
    if(target == 0 && all_same) {
      cout<<"Yes"<<endl;
    } else {
      cout<<"No"<<endl;
    }
  }
  return 0;
}
