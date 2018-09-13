/**
 * License: Unlicense
 * Description: z[x] is max L: s[x:x+L] == s[:L]
 */
#pragma once

vector<size_t> zFun(const string& s) {
	vector<size_t> z(s.size(), 0);
	for (size_t left = 0, right = 0, i = 1; i < s.size(); ++i) {
		z[i] = (i < right ? min(right - i, z[i - left]) : 0);
		while (i + z[i] < s.size() && s[i + z[i]] == s[z[i]])
			++z[i];
		if (i + z[i] > right)
			tie(left, right) = {i, i + z[i]};
	}
	return z;
}
