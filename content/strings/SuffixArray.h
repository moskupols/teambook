/**
 * Author: Fedor Alekseev
 * Date: 2018-11-27
 * Status: Somewhat tested on http://codeforces.com/contest/1056/problem/E
 */
#pragma once

struct SuffixArray {
  string s;
  vector<int> order, rank, lcp;

  SuffixArray(const string& _s): s(_s + '$') {
    int n = sz(s);
    std::vector<int> count(n + 130), nextPos(count.size() + 1);
    std::vector<int> nextOrder(n), nextColor(n);
    std::vector<int> color(WHOLE(s));

    auto norm = [n](int i) {
      return i < 0 ? i + n : i >= n ? i - n : i;
    };

    order.resize(n);
    std::iota(WHOLE(order), 0);
    std::sort(WHOLE(order),
        [&](int aa, int bb) { return s[aa] < s[bb]; });

    for (int half = 1; half < n; half *= 2) {
      count.assign(count.size(), 0);
      for (auto col : color)
        ++count[col];

      nextPos[0] = 0;
      partial_sum(WHOLE(count), nextPos.begin() + 1);

      for (auto pos : order) {
        auto shifted = norm(pos - half);
        nextOrder[nextPos[color[shifted]]++] = shifted;
      }
      order.swap(nextOrder);

      nextColor[order[0]] = 0;
      for (int i = 1; i < n; ++i) {
        auto pos = order[i], prev = order[i - 1];
        nextColor[pos] = nextColor[prev] + (
            tie(color[pos], color[norm(pos + half)]) !=
            tie(color[prev], color[norm(prev + half)])
        );
      }
      color.swap(nextColor);
    }

    rank.resize(n);
    for (int i = 0; i < n; ++i)
      rank[order[i]] = i;

    lcp.resize(n);
    for (int i = 0; i < n; ++i) if (rank[i]) {
      for (int p0 = order[rank[i] - 1]; s[i + h] == s[p0 + h];)
        h++;
      lcp[rank[i]] = h;
      h -= h > 0;
    }
  }
};
