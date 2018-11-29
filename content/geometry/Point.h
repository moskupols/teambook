/**
 * Author: Ulf Lundstrom, with some adaptation by Fedor Alekseev
 * Date: 2009-02-26
 * License: CC0
 * Source: My head with inspiration from tinyKACTL
 * Status: Works fine, used a lot
 */
#pragma once

template<class T>
struct PointT {
  using P = PointT;
  T x, y;
  PointT() = default;
  PointT(T x, T y): x(x), y(y) {}
  explicit PointT(P a, P b): PointT(b - a) {}

  bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
  bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }

  P operator+(P p) const { return P(x+p.x, y+p.y); }
  P operator-(P p) const { return P(x-p.x, y-p.y); }

  T operator*(P p) const { return x*p.x + y*p.y; }
  T operator%(P p) const { return x*p.y - y*p.x; }

  T hypot2() const { return x*x + y*y; }
  double hypot() const { return hypot(x, y); }

  P operator*(T d) const { return P(x*d, y*d); }
  P operator/(T d) const { return P(x/d, y/d); }

  P unit() const { return *this/dist(); } // makes dist()=1
  P perp() const { return P(-y, x); } // rotates +90 degrees
  P normal() const { return perp().unit(); }

  // returns point rotated 'a' radians ccw around the origin
  P rotate(double a) const {
    return P(
        x * cos(a) - y * sin(a),
        x * sin(a) + y * cos(a)
    );
  }
};
