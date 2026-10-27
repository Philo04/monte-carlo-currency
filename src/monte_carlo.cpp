#include <cmath>
#include <random>
#include "monte_carlo.h"

std::vector<double> simulate(double s0, double mu, double sigma, double time, int steps, int simulations){
	std::vector<double> final_prices;
	final_prices.reserve(simulations);

	std::random_device rd;
	std::mt19937 gen(rd());
	std::normal_distribution<> d(0.0, 1.0);

	double dt = time / steps;

	for (int i = 0; i < simulations; ++i) {
		double price = s0;
		for (int j = 0; j < steps; ++j) {
			double z = d(gen);
			price *= std::exp((mu - 0.5 * sigma * sigma) * dt + sigma * std::sqrt(dt) * z);// Формула GBM
		}
		final_prices.push_back(price);
	}

	return final_prices;
}
