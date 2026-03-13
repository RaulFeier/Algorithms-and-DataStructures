#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ft first
#define sd second
#define sz(x) (i64) x.size()
#define srt(x) sort(x.begin(), x.end())
#define rvs(x) reverse(x.begin(), x.end())
#define all(x) x.begin(), x.end()

#define pq priority_queue
#define fn function
#define dbg(v)                                                                 \
  cerr << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

template <typename K, typename V> using umap = unordered_map<K, V>;

using i64 = int64_t;
using d64 = long double;

using p32 = pair<int, int>;
using p64 = pair<i64, i64>;
using pd = pair<d64, d64>;

using graph = vector<vector<int>>;
using wgraph = vector<vector<p64>>;

template <typename T1, typename T2>
istream &operator>>(istream &stream, pair<T1, T2> &p) {
  stream >> p.ft;
  stream >> p.sd;
  return stream;
}

template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &out, const std::pair<T1, T2> &pair) {
  return out << '(' << pair.first << ", " << pair.second << ')';
}

template <typename T> istream &operator>>(istream &stream, vector<T> &v) {
  if (v.empty()) {
    unsigned long long len;
    stream >> len;
    v.assign(len, T());
  }
  for (auto i = 0; i < sz(v); i++) {
    stream >> v[i];
  }
  return stream;
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &vec) {
  if (vec.empty()) {
    out << "[]";
    return out;
  }
  out << '[';
  for (int i = 0; i < vec.size() - 1; i++) {
    out << vec[i] << ", ";
  }
  return out << vec.back() << ']';
}

template <typename T1, typename T2>
ostream &operator<<(ostream &out, const unordered_map<T1, T2> &map) {
  out << '{';
  for (auto it = map.begin(); it != map.end(); it++) {
    pair<T1, T2> element = *it;
    out << element.first << ": " << element.second;
    if (next(it) != map.end()) {
      out << ", ";
    }
  }
  return out << '}';
}

template <typename T1, typename T2>
ostream &operator<<(ostream &out, const map<T1, T2> &map) {
  out << '{';
  for (auto it = map.begin(); it != map.end(); it++) {
    pair<T1, T2> element = *it;
    out << element.first << ": " << element.second;
    if (next(it) != map.end()) {
      out << ", ";
    }
  }
  return out << '}';
}

template <typename T>
ostream &operator<<(ostream &out, const unordered_set<T> &set) {
  out << '{';
  for (auto it = set.begin(); it != set.end(); it++) {
    T element = *it;
    out << element;
    if (next(it) != set.end()) {
      out << ", ";
    }
  }
  return out << '}';
}

template <typename T>
ostream &operator<<(ostream &out, const multiset<T> &set) {
  out << '{';
  for (auto it = set.begin(); it != set.end(); it++) {
    T element = *it;
    out << element;
    if (next(it) != set.end()) {
      out << ", ";
    }
  }
  return out << '}';
}

template <typename T>
ostream &operator<<(ostream &out, const unordered_multiset<T> &set) {
  out << '{';
  for (auto it = set.begin(); it != set.end(); it++) {
    T element = *it;
    out << element;
    if (next(it) != set.end()) {
      out << ", ";
    }
  }
  return out << '}';
}

struct hash_pair {
  template <class T1, class T2> size_t operator()(const pair<T1, T2> &p) const {
    size_t hash1 = hash<T1>{}(p.first);
    size_t hash2 = hash<T2>{}(p.second);
    return hash1 ^ (hash2 + 0x9e3779b9 + (hash1 << 6) + (hash1 >> 2));
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  return 0;
}
