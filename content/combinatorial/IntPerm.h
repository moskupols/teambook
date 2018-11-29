/**
 * Author: Fedor Alekseev
 * Description: perm <-> id
 * Time: O(n)
 */
#pragma once

i64 permToInt(const vector<int>& perm, const vector<i64>& fact) {
	int use = 0, i = 0, r = 0;
	for (auto x : perm) {
		r += fact[x - __builtin_popcount(use & ((1 << x) - 1))];
		use |= 1 << x;
	}
	return r;
}

vector<int> intToPerm(i64 id, size_t n, const vector<i64>& fact) {
	vector<int> perm(n), numbers(n);
	iota(WHOLE(numbers), 0);
	for (int& res : perm) {
		res
	}
}
