#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>
#include <cmath>
#include "monte_carlo.h"

TEST_CASE("Monte Carlo Simulation basic test", "[simulate]") {
    double s0 = 100.0;
    double mu = 0.05;
    double sigma = 0.2;
    double time = 1.0;
    int steps = 252;
    int simulations = 1000;

    auto results = simulate(s0, mu, sigma, time, steps, simulations);

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

    auto results = simulate(s0, mu, sigma, time, steps, simulations);
    double expected = s0 * std::exp(mu * time);

    for (double price : results) {
        // В Catch2 v3 используется Catch::Approx
        REQUIRE(price == Catch::Approx(expected).epsilon(0.001));
    }
}