
#include "benchmark/benchmark.h"
#include "solution.hpp"

static void checksum_solution(benchmark::State &state) {
  // Init benchmark data
  Blob blob;
  init(blob);

  // Run the benchmark
  for (auto _ : state) {
    auto output = checksum_solution(blob);
    benchmark::DoNotOptimize(output);
  }
}

static void checksum_baseline(benchmark::State &state) {
  // Init benchmark data
  Blob blob;
  init(blob);

  // Run the benchmark
  for (auto _ : state) {
    auto output = checksum_baseline(blob);
    benchmark::DoNotOptimize(output);
  }
}


// Register the function as a benchmark and measure time in microseconds
BENCHMARK(checksum_solution)->Unit(benchmark::kMicrosecond);
BENCHMARK(checksum_baseline)->Unit(benchmark::kMicrosecond);

// Run the benchmark
BENCHMARK_MAIN();
