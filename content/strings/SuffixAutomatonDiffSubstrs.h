/**
 * Author: Fedor Alekseev
 * Description: An excerpt from a problem with map-based implementation of
 * automaton.  Still probably gives a taste.
 */
#include "SuffixAutomaton.h"

std::int64_t diffSubstrs() {
  std::int64_t total = -1;

  std::vector<int> perm(nodes.size());
  std::iota(perm.begin(), perm.end(), 0);
  std::sort(
    perm.begin(), perm.end(),
    [&](int fi, int se) {
        return nodes[fi].maxLen < nodes[se].maxLen;
    }
  );

  nodes[0].dp = 1;
  for (auto i : perm) {
    total += nodes[i].dp;
    for (auto pa : nodes[i].trans) {
        pa.second->dp += nodes[i].dp;
    }
  }

  return total;
}
