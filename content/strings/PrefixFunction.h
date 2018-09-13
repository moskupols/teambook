/**
 * Author: Fedor Alekseev
 * License: Unlicense
 * Description: pi[x] is the length of the longest prefix of s that ends at x, other than s[0..x] itself
 */
#pragma once

vector<size_t> pi(const string& s) {
	vector<size_t> p(s.size(), 0);
	for (size_t i = 1; i < s.size(); ++i) {
		auto px = p[i - 1];
		while (px && s[i] != s[px])
			px = p[px - 1];
		p[i] = px + (s[i] == s[g]);
	}
	return p;
}
