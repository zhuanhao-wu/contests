#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <cstdlib>
using namespace std;

const int maxn = 1e5+1;
vector<int> e[maxn];
set<pair<int, int> > visE;
set<int> vis;

void dfs(int u, int fa = -1) {
  vis.insert(u);
  int degu = 0;
  for(auto v : e[u]) {
    if(fa == v) continue;
    if(vis.find(v) == vis.end()) {
      dfs(v, u);
    }
    auto ituv = visE.find(make_pair(u, v));
    auto itvu = visE.find(make_pair(v, u));
    if(ituv != visE.end()) {
      degu++;
    }
    if(ituv == visE.end() && itvu == visE.end()) {
      visE.insert(make_pair(v, u));
    }
  }
  if(fa != -1) {
    if(degu % 2 == 0) {
      visE.insert(make_pair(fa, u));
    }
    else {
      visE.insert(make_pair(u, fa));
    }
  }
}

int main() {
  int N, M, x, y;
  cin>>N>>M;
  for(int i = 0; i < M; i++) {
    cin>>x>>y;
    e[x].push_back(y);
    e[y].push_back(x);
  }
  dfs(1);
  if(M % 2 == 1) {
    cout<<"-1"<<endl;
  } else {
    for(auto pr: visE) {
      cout<<pr.first<<" "<<pr.second<<endl;
    }
  }
  return 0;
}
