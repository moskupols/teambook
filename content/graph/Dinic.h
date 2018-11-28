/**
 * Author: apparently zemen, as this is based on Jinotega's teambook.
 * License: MIT
 */
#pragma once

namespace Dinic {
const int maxn = 100100;
struct Edge {
  int to;
  i64 cap;
  i64 flow = 0;
};

vector<Edge> es;
vector<int> g[maxn];
int layer[maxn], pos[maxn];
int S, T;

void addEdge(int v, int u, ll c) {
  g[v].push_back(sz(es));
  es.push_back({u, c});
  g[u].push_back(sz(es));
  es.push_back({v, 0});
}

i64 dfs(int v, i64 curf) {
  if (v == T)
    return curf;
  i64 ret = 0;
  for (auto& i = pos[v]; curf && i < sz(g[v]); ++i) {
    auto& e = es[g[v][i]];
    if (layer[e.to] != layer[v])
      continue;
    if (i64 delta = dfs(e.to, min(curf, e.cap - e.flow))) {
      curf -= delta;
      ret += delta;
      e.flow += delta;
      es[g[v][i] ^ 1].flow -= delta;
    }
  }
  return ret;
}

bool bfs() {
  memset(layer, -1, sizeof layer);
  layer[S] = 0, q[0] = S;
  static queue<int> q;
  for (q.push(S); !q.empty(); q.pop) {
    int v = q.front();
    for (int id: g[v]) {
      const auto& e = es[id];
      if (e.cap > e.flow && layer[e.to] == -1) {
        layer[e.to] = layer[v] + 1;
        q.push(e.to);
      }
    }
  }
  return layer[T] != -1;
}

i64 dinic(int s, int t) {
  S = s; T = t;
  i64 res = 0;
  while (bfs()) {
    memset(pos, 0, sizeof pos);
    while (i64 cur = dfs(S, 1LL << 60))
      res += cur;
  }
  return res;
}
} // namespace Dinic

void test() {
    Dinic::addEdge(0, 1, 1);
    Dinic::addEdge(0, 2, 2);
    Dinic::addEdge(2, 1, 1);
    Dinic::addEdge(1, 3, 2);
    Dinic::addEdge(2, 3, 1);
    cout << Dinic::dinic(0, 3) << endl; // 3
}
