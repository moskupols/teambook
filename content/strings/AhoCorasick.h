/**
 * Author: Fedor Alekseev
 * License: Unlicense
 * Description: on-line tracking of the set of suffixes of a text that are
 * prefixes of some words from a dictionary.
 * Status: tested on a mipt contest
 */
#pragma once

struct Node {
	Node(int parent, Char ch): parent(parent), lastChar(ch) {
		memset(trans, -1, sizeof trans);
	}
	int trans[Alph];
	int link = 0, nextTerm = -1, termId = -1, parent;
	Char lastChar;
};
struct AhoCorasick {
	void addWord(const string& word, int id) {
		int v = 0;
		for (int ch : word) {
			ch -= 'a';
			auto& u = n[v].trans[ch];
			if (u == -1) {
				n.emplace_back(v, ch);
				u = int(n.size() - 1);
			}
			v = u;
		}
		n[v].termId = id;
	}
	void build() {
		queue<int> q;
		for (auto& tr : n[0].trans) {
			if (tr != -1) {
				q.push(tr);
			} else
				tr = 0;
		}
		while (!q.empty()) {
			auto v = q.front();
			q.pop();
			auto& li = n[v].link;
			auto par = n[v].parent;
			li = (par ? n[n[par].link].trans[n[v].lastChar] : 0);
			n[v].nextTerm = n[li].termId != -1 ? li : n[li].nextTerm;
			for (Char ch = 0; ch < Alph; ++ch) {
				if (auto& u = n[v].trans[ch]; u != -1) {
					q.push(u);
				} else
					u = n[li].trans[ch];
			}
		}
	}
private:
	vector<Node> n{{-1, 0}};
};
