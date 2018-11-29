/**
 * Author: Lukas Polacek, with some adaptation by Fedor Alekseev
 * Date: 2009-10-30
 * License: CC0
 * Source: folklore/TopCoder
 */
#pragma once
struct Fenwick {
  vector<i64> s;
  explicit Fenwick(int size): s(size, 0) {}

  void add(int at, i64 delta) {
    for (; at < sz(s); at |= at + 1)
      s[at] += delta;
  }

  i64 get_prefix(int end) {
    i64 sum = 0;
    for (; end > 0; end &= end - 1)
      sum += s[end - 1];
    return sum;
  }

  int lower_bound(i64 sum) {// min pos st sum of [0, pos] >= sum
    // Returns n if no sum is >= sum, or -1 if empty sum is.
    if (sum <= 0) return -1;
    int pos = 0;
    for (int pw = 1 << 25; pw; pw >>= 1)
      if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
        pos += pw, sum -= s[pos-1];
    return pos;
  }
};
