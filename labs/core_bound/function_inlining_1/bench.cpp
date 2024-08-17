
#include "benchmark/benchmark.h"
#include "solution.h"

static void bench(benchmark::State &state) {
  std::array<S, N> arr;
  init(arr);

  for (auto _ : state) {
    auto copy = arr;
    solution(copy);
    benchmark::DoNotOptimize(copy);
  }
}


static void baseline(benchmark::State &state) {
  std::array<S, N> arr;
  init(arr);

  for (auto _ : state) {
    auto copy = arr;
    solution_baseline(copy);
    benchmark::DoNotOptimize(copy);
  }
}

// Register the function as a benchmark
BENCHMARK(bench)->Unit(benchmark::kMicrosecond);
BENCHMARK(baseline)->Unit(benchmark::kMicrosecond);

// Run the benchmark
BENCHMARK_MAIN();
