/**
 * Author: Fedor Alekseev
 * Date: 2018-03-25
 */
#pragma once

struct TwoSAT {
  int n;
  vector<vector<int>> g;
  vector<vector<int>> gr;

  explicit TwoSAT(int n = 0): n(n), g(n * 2), gr(n * 2) {}

  void addImplication(int a, int b) {
    debug("%d -> %d", a, b);
    g[a].push_back(b);
    gr[b].push_back(a);

    debug("\t%d -> %d\n", b ^ 1, a ^ 1);
    g[b ^ 1].push_back(a ^ 1);
    gr[a ^ 1].push_back(b ^ 1);
  }

  void addOr(int a, int b) {
    debug("%d v %d\t", a, b);
    addImplication(a ^ 1, b);
  }

  vector<bool> used;
  vector<int> topOrder;
  void topTraverse(int v) {
    used[v] = true;
    for (int u : g[v])
      if (!used[u])
        topTraverse(u);
    topOrder.push_back(v);
  }

  int comps;
  vector<int> comp;
  void colorize(int v, int color) {
    comp[v] = color;
    for (int u : gr[v])
      if (comp[u] == -1)
        colorize(u, color);
  }

  vector<bool> solution;
  bool run() {
    used.assign(n * 2, false);
    for (int i = 0; i < 2 * n; ++i) {
      if (!used[i])
        topTraverse(i);
    reverse(WHOLE(topOrder));

    comps = 0;
    comp.assign(2 * n, -1);
    for (auto v : topOrder)
      if (comp[v] == -1)
        colorize(v, comps++);

    solution.resize(n * 2);
    for (int v = 0; v < n * 2; v += 2) {
      if (comp[v] == comp[v + 1]) {
        debug("No solution, as %d <-> %d\n", v, v + 1);
        return false;
      }
      solution[v] = comp[v] > comp[v + 1];
      solution[v + 1] = !solution[v];
    }
    return true;
  }
};
