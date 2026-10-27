#include <benchmark/benchmark.h>
#include "monte_carlo.h"

static void BM_MonteCarloSimulate(benchmark::State& state) {
    for (auto _ : state) {
        auto res = MonteCarloSimulator::simulate(100.0, 0.05, 0.2, 1.0, 252, 10000);
        benchmark::DoNotOptimize(res);
    }
}

BENCHMARK(BM_MonteCarloSimulate);
BENCHMARK_MAIN();