/**
 * Author: Fedor Alekseev
 * Status: tested on some ShAD contest
 * Description: Each node is a set of substrings with same set of end positions.
 * The lengths of substrings in each node lie on segment $[maxlen(link(v)); maxlen(v)]$.
 * Each path covers disjoint sets of substrings.
 * Each path from 0 is a unique substring.
 */
#pragma once

struct Node {
  int maxLen;
  int sufLink;
  int trans[26];
} nodes[200005];

class Automaton {
public:
  void append(const int ch) {
    auto p = last;
    last = newNode(nodes[last].maxLen + 1, 0);

    for (; p > -1; p = nodes[p].sufLink) {
      const auto q = nodes[p].trans[ch];
      if (q == -1) {
        nodes[p].trans[ch] = last;
      } else {
        auto clone = q;
        if (nodes[p].maxLen + 1 != nodes[q].maxLen) {
          clone = copyNode(q);
          nodes[clone].maxLen = nodes[p].maxLen + 1;
          nodes[q].sufLink = clone;
          for (; p > -1 && nodes[p].trans[ch] == q; p = nodes[p].sufLink)
            nodes[p].trans[ch] = clone;
        }
        nodes[last].sufLink = clone;
        break;
      }
    }
  }

private:
  int nsz = 0;
  int last = newNode(0);

  int newNode(int maxLen, int sufLink = -1) {
    memset(nodes[nsz], -1, sizeof nodes[nsz]);
    nodes[nsz].maxLen = maxLen;
    nodes[nsz].sufLink = sufLink;
    return nsz++;
  };

  int copyNode(int orig) {
    memcpy(nodes + nsz, nodes + orig, sizeof(Node));
    return nsz++;
  }
};
