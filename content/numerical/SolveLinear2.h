/**
 * Author: Simon Lindholm, with style fixes by Fedor Alekseev
 * Date: 2016-09-06
 * License: CC0
 * Source: me
 * Description: To get all uniquely determined values of $x$ back from SolveLinear, make the following changes:
 * Status: tested on kattis:equationsolverplus
 */
#pragma once

#include "SolveLinear.h"

for(int j = 0; j < n; ++j)if(j != i) // instead of for(j=i+1; j<n)
// ... then at the end:
x.assign(m, undefined);
for (int i = 0; i < rank; ++i) {
	for (int j = rank; j < m; ++j)
		if (fabs(A[i][j]) > eps) goto fail;
	x[col[i]] = b[i] / A[i][i];
fail:; }
