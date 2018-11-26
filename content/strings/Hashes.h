/**
 * Author: Fedor Alekseev
 * Status: Tested on http://codeforces.com/contest/1056/problem/E
 */
using Hash = array<ui64, 3>;
#define HOP(op) \
  inline Hash operator op (Hash a, Hash b) { \
    return {a[0] op b[0], a[1] op b[1], a[2] op b[2]}; \
  }
HOP(+)HOP(-)HOP(*)HOP(%)
inline Hash makeHash(ui64 val) { return {val, val, val}; }

const Hash Multiplier{{228227, 227223, 22823}};
const Hash Modulus{{424242429, 2922827, 22322347}};

vector<Hash> pows(1);
struct Hashes {
  explicit Hashes(const string& s) {
    pows.front().fill(1);
    while (pows.size() <= s.size())
      pows.push_back(pows.back() * Multiplier % Modulus);
    prefs.push_back(makeHash(0));
    for (auto c : s)
      prefs.push_back((prefs.back() * Multiplier + makeHash(c))
          % Modulus);
  }
  Hash get(size_t begin, size_t end) const {
    return (prefs[end] - prefs[begin] * pows[end - begin]
        % Modulus + Modulus) % Modulus;
  }
private:
  vector<Hash> prefs;
};
