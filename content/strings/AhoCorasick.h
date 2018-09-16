/**
 * Author: Fedor Alekseev
 * License: Unlicense
 * Description: on-line tracking of the set of suffixes of a text that are
 * prefixes of some words from a dictionary.
 * Status: tested on a mipt contest
 */
#pragma once

struct AhoCorasick {
	AhoCorasick(): n(1) {
		n.reserve(TrieSize);
	}

	void addWord(const string& word, int id) {
		int v = 0;
		for (int ch : word) {
			ch -= 'a';
			auto& u = n[v].trans[ch];
			if (!u) {
				u = int(n.size());
				n.emplace_back();
			}
			v = u;
		}
		n[v].termId = id;
	}

	void build() {
		queue<int> q;
		for (q.push(0); !q.empty(); q.pop()) {
			auto v = q.front();
			for (Char ch = 0; ch < Alph; ++ch) {
				auto& u = n[v].trans[ch];
				if (!u) {
					u = n[n[v].link].trans[ch];
					continue;
				}
				q.push(u);
				auto i = n[u].link = (v ? n[n[v].link].trans[ch] : 0);
				n[u].nextTerm = (n[i].termId >= 0 ? i : n[i].nextTerm);
			}
		}
	}

private:
	struct Node {
		int trans[Alph]{};
		int nextTerm = -1, termId = -1, link = 0;
	};

	vector<Node> n;
};
