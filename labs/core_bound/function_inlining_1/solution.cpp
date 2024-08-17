
#include "solution.h"
#include <algorithm>
#include <stdlib.h>

static __forceinline int compare_inlined(const void *lhs, const void *rhs) {
  auto &a = *reinterpret_cast<const S *>(lhs);
  auto &b = *reinterpret_cast<const S *>(rhs);

  if (a.key1 < b.key1)
    return -1;

  if (a.key1 > b.key1)
    return 1;

  if (a.key2 < b.key2)
    return -1;

  if (a.key2 > b.key2)
    return 1;

  return 0;
}

static int compare(const void *lhs, const void *rhs) {
  auto &a = *reinterpret_cast<const S *>(lhs);
  auto &b = *reinterpret_cast<const S *>(rhs);

  if (a.key1 < b.key1)
    return -1;

  if (a.key1 > b.key1)
    return 1;

  if (a.key2 < b.key2)
    return -1;

  if (a.key2 > b.key2)
    return 1;

  return 0;
}

void solution_baseline(std::array<S, N> &arr) {
  qsort(arr.data(), arr.size(), sizeof(S), compare);
}

void solution(std::array<S, N> &arr) {
  std::sort(arr.begin(), arr.end(), [](S& a, S& b) {
    return a.key1 < b.key1 || (a.key1 == b.key1) && (a.key2 < b.key2);
  });
}