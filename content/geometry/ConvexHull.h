/**
 * Author: Fedor Alekseev
 * Date: 2018-11-29
 * Status: tested on some evil tests at LKSh, and at India Workshops
*/
#pragma once

vector<Point> hull(vector<Point> pts) {
  sort(WHOLE(pts));
  pts.erase(unique(WHOLE(pts)), pts.end());
  sort(pts.begin()+1, pts.end(), [pivot=pts[0]](Point a, Point b){
    auto cross = (a - pivot) % (b - pivot);
    return cross > 0 || ( // Warning: consider using epsilon!
      cross == 0 && (pivot - a) * (b - a) < 0);
  });

  {  // Iff non strictly convex
    auto rit = pts.rbegin();
    while (rit != pts.rend()
        && 0 == (pts.back() - pts[0]) % (*rit - pts[0])
      ++rit;
    reverse(pts.rbegin(), rit);
  }

  vector<Point> ret;
  for (auto p : pts) // Warning: consider using epsilon!
    while (sz(ret) > 1 && 0 >= // > 0 non-strict convex
        (ret.back() - ret[sz(ret) - 2]) %
        (p - ret.back()))
      ret.pop_back();
    ret.push_back(pts[i]);
  }

  return ret;
}
