#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "monte_carlo.h"

TEST_CASE("Monte Carlo Simulation basic test", "[simulate]") {
    double s0 = 100.0;
    double mu = 0.05;
    double sigma = 0.2;
    double time = 1.0;
    int steps = 252;
    int simulations = 1000;

    auto results = MonteCarloSimulator::simulate(s0, mu, sigma, time, steps, simulations);

    REQUIRE(results.size() == simulations);
    
    for (double price : results) {
        REQUIRE(price > 0.0); // Цена не может быть отрицательной
    }
}

TEST_CASE("Zero volatility deterministic test", "[simulate]") {
    // При нулевой волатильности цена должна расти строго по формуле
    double s0 = 100.0;
    double mu = 0.05;
    double sigma = 0.0;
    double time = 1.0;
    int steps = 10;
    int simulations = 10;

    auto results = MonteCarloSimulator::simulate(s0, mu, sigma, time, steps, simulations);
    double expected = s0 * std::exp(mu * time);

    for (double price : results) {
        REQUIRE(price == Approx(expected).epsilon(0.001));
    }
}