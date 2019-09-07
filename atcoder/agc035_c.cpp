#include <iostream>
#include <cassert>
using namespace std;

const int maxn = 1e5+1;
int a[maxn];
void answer_for_4k_0() {
}

int main() {
  int N;
  cin>>N;
  for(int i = 1; i <= N; i++) a[i] = i;
  if(N % 4 == 3) {
    cout<<"Yes"<<endl;
    for(int i = 1; i < N; i++) {
      cout<<i<<" "<<i + 1<<endl;
      cout<<N + i<<" "<<N + i + 1<<endl;
    }
    cout<<N<<" "<<N+1<<endl;
  } else if(N % 4 == 0) {
    if(__builtin_popcount(N) == 1) {
      cout<<"No"<<endl; // no for such case
    } else {
      int target_value = N ^(N - 1); // this value always less
      swap(a[target_value], a[N - 2]); 
      cout<<"Yes"<<endl;
      for(int i = 1; i < N - 1; i++) {
        cout<<a[i]<<" "<<a[i + 1]<<endl;
        cout<<N + a[i]<<" "<<N + a[i + 1]<<endl;
      }
      cout<<a[N - 1]<<" "<<N + a[1]<<endl;
      cout<<N<<" "<<N - 1<<endl;
      cout<<N + N<<" "<<a[N-2]<<endl;
    }
  } else if(N % 4 == 1 && N > 1) {
    cout<<"Yes"<<endl;
    for(int i = 1; i < N - 2; i++) {
      cout<<i<<" "<<i + 1<<endl;
      cout<<N + i<<" "<<N + i + 1<<endl;
    }
    cout<<N - 2<<" "<<N + 1<<endl;
    cout<<N<<" "<<N - 1<<endl;
    cout<<N - 1<<" "<<1<<endl;
    cout<<1<<" "<<N + N<<endl;
    cout<<N + N<<" "<<N + N - 1<<endl;
  } else if(N % 4 == 2 && N > 2) {
    cout<<"Yes"<<endl;
    int n = N - 3;
    for(int i = 1; i < n; i++) {
      cout<<i<<" "<<i + 1<<endl;
      cout<<N + i<<" "<<N + i + 1<<endl;
    }
    cout<<n<<" "<<N + 1<<endl;
    cout<<(N - 2)<<" "<<(N - 1)<<endl;
    cout<<(N - 1)<<" "<<(1)<<endl;
    cout<<(2 * N - 2)<<" "<<(1)<<endl;
    cout<<(2 * N - 2)<<" "<<(2*N - 1)<<endl;
    cout<<N << " " << N - 1 <<endl;
    cout<<2 << " " << 2 * N <<endl;
  } else {
    cout<<"No"<<endl;
  }
  return 0;
}
