/**
 * Author: Fedor Alekseev
 * Date: 2018-11-27
 * Status: Somewhat tested on http://codeforces.com/contest/1056/problem/E
 */
template<class T, class Better = std::less<T>>
struct SparseTable {
  explicit SparseTable(vector<T> vals) {
    log2.push_back(0);
    for (int i = 1; i <= sz(vals); ++i) {
      log2.push_back(log2.back() + (2 << log2.back() < i));
    }

    table.push_back(std::move(vals));
    for (int p = 1; log2.back() >= sz(table); ++p) {
      auto& row = table.emplace_back();
      for (int i = 0; i + (1<<p) <= sz(table[0]); ++i) {
        row.push_back(get(i, i + (1<<p)));
      }
    }
  }

  T get(int begin, int end) const {
    int p = log2[end - begin];
    return min(table[p][begin], table[p][end - (1<<p)], better);
  }

private:
  vector<vector<T>> table;
  vector<int> log2;
  Better better;
};
