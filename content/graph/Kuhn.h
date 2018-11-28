/**
 * Author: Fedor Alekseev
 * Date: 2018-11-29
 */
#pragma once

vector<int> vis, match;

int qq = 0;
bool try_kuhn(int v) {
  if (vis[v] == qq)
    return false;
  vis[v] = qq;
  for (auto u : e[v]) {
      if (match[u] == -1) {
          match[u] = v;
          return true;
      }
  }
  for (auto u : e[v]) {
      if (dfs(match[u])) {
          match[u] = v;
          return true;
      }
  }
  return false;
}

void kuhn() {
  fill(WHOLE(vis), -1);
  for (int qq = 0; qq < n; ++qq) {
    try_kuhn(qq);
  }
}
