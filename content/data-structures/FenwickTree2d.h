/**
 * Author: Simon Lindholm, with some adaptation by Fedor Alekseev
 * Date: 2017-05-11
 * License: CC0
 * Source: folklore
 * Description: Computes sums a[i,j] for all i<I, j<J.
 *  Requires that the elements to be updated are known in advance.
 */
#pragma once

#include "FenwickTree.h"

struct Fenwick2D {
  vector<vector<int>> ys;
  vector<Fenwick> ft;

  explicit Fenwick2D(int limx) : ys(limx) {
  }

  void fakeUpdate(int x, int y) {
    for (; x < sz(ys); x |= x + 1)
      ys[x].push_back(y);
  }

  void init() {
    for (auto& v : ys) {
      sort(WHOLE(v));
      ft.emplace_back(sz(v));
    }
  }

  int ind(int x, int y) {
    return (int)(lower_bound(WHOLE(ys[x]), y) - ys[x].begin());
  }

  void update(int x, int y, i64 delta) {
    for (; x < sz(ys); x |= x + 1)
      ft[x].update(ind(x, y), delta);
  }

  i64 query(int x, int y) {
    i64 sum = 0;
    for (; x; x &= x - 1)
      sum += ft[x-1].query(ind(x-1, y));
    return sum;
  }
};
