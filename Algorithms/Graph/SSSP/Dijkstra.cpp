#include "../../../HEADER.h"

vi64 dij(i64 s, const vec<vp64> &g) {
  vi64 ans(g.size() + 1, INF);
  priority_queue<p64, vp64, greater<p64>> pq;

  ans[s] = 0;
  pq.push({0, s});

  while (!pq.empty()) {
    let crt = pq.top();
    pq.pop();

    if (crt.ft > ans[crt.sd]) {
      continue;
    }

    for (let &c : g[crt.sd]) {
      i64 cand = crt.first + c.sd;
      if (cand < ans[c.ft]) {
        ans[c.ft] = cand;
        pq.push({cand, c.ft});
      }
    }
  }

  return ans;
}