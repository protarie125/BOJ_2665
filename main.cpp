#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;
using vvl = vector<vl>;
using vs = vector<string>;
using Pos = pair<ll, ll>;

constexpr auto kInf = numeric_limits<ll>::max() / 2 - 1;

ll n;
vs M;

vvl dist;

vl dx{-1, 1, 0, 0};
vl dy{0, 0, -1, 1};

void bfs() {
  queue<Pos> Q{};
  Q.push({0, 0});
  dist[0][0] = 0;

  while (!Q.empty()) {
    auto [fy, fx] = Q.front();
    Q.pop();

    if (fx == n - 1 && fy == n - 1) continue;

    for (auto i = 0; i < 4; ++i) {
      const auto& nx = fx + dx[i];
      const auto& ny = fy + dy[i];

      if (nx < 0 || n <= nx || ny < 0 || n <= ny) continue;

      const auto& next_dist = dist[fy][fx] + (1 - (M[ny][nx] - '0'));
      if (next_dist < dist[ny][nx]) {
        Q.push({ny, nx});
        dist[ny][nx] = next_dist;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n;
  M = vs(n);
  for (auto&& s : M) cin >> s;

  dist = vvl(n, vl(n, kInf));
  bfs();
  cout << dist[n - 1][n - 1];

  return 0;
}