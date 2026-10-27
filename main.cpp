#include <iostream>
#include <iomanip>
#include <numeric>
#include <algorithm>
#include <string>
#include <cstdio>
#include "monte_carlo.h"

int main(int argc, char** argv){
	double s0 = 100.0;       // Начальная цена валюты
	double mu = 0.05;        // Ожидаемая доходность (тренд)
	double sigma = 0.2;      // Волатильность
	double time = 1.0;       // Время (1 год)
	int steps = 252;         // Количество шагов (торговых дней в году)
	int simulations = 10000; // Количество симуляций
	
	for (int i = 1;i < argc;i++) {
		std::string arg = argv[i];
		int res = 2;
		if(arg == "--help") {
			std::cout << "Использование: " << argv[0] << " [ОПЦИИ]\n\n"
				<< "Моделирование курса валют методом Монте-Карло (GBM)\n\n"
				<< "Опции:\n"
				<< "  --initial-price <double>  Начальная цена валюты (по умолчанию: 100.0)\n"
				<< "  --trend <double>          Ожидаемая доходность (тренд) (по умолчанию: 0.05)\n"
				<< "  --volatility <double>     Волатильность (по умолчанию: 0.2)\n"
				<< "  --time <double>           Время в годах (по умолчанию: 1.0)\n"
				<< "  --steps <int>             Количество шагов (по умолчанию: 252)\n"
				<< "  --simulations <int>       Количество симуляций (по умолчанию: 10000)\n"
				<< "  --help                    Показать это сообщение и выйти\n";
			return 0;
		} else if(arg == "--initial-price" && i + 1 < argc){
			res = std::sscanf(argv[i + 1], "%lf", &s0);
		} else if(arg == "--trend" && i + 1 < argc){
			res = std::sscanf(argv[i + 1], "%lf", &mu);
		} else if(arg == "--volatility" && i + 1 < argc){
			res = std::sscanf(argv[i + 1], "%lf", &sigma);
		} else if(arg == "--time" && i + 1 < argc){
			res = std::sscanf(argv[i + 1], "%lf", &time);
		} else if(arg == "--steps" && i + 1 < argc){
			res = std::sscanf(argv[i + 1], "%d", &steps);
		} else if(arg == "--simulations" && i + 1 < argc){
			res = std::sscanf(argv[i + 1], "%d", &simulations);
		} else {
			std::cerr << "Ошибка: Неизвестный аргумент: " << arg << "\n"
				<< "Используйте --help для получения справки.\n";
			return 1;
		}
		i++;
		if(res != 1){
			std::cerr << "Ошибка: значение " << arg << " некорректно или отсутствует\n"
				<< "Используйте --help для получения справки.\n";
			return 1;
		}
	}

	std::cout << "Моделирование курса валют методом Монте-Карло (GBM)\n"
		<< "Начальная цена: " << s0 << "\n"
		<< "Ожидаемая доходность: " << mu * 100 << "%\n"
		<< "Волатильность: " << sigma * 100 << "%\n"
		<< "Время: " << time << " г\n"
		<< "Количество симуляций: " << simulations << "\n\n";

	auto results = simulate(s0, mu, sigma, time, steps, simulations);

	double sum = std::accumulate(results.begin(), results.end(), 0.0);
	double mean = sum / results.size();
	auto minmax = std::minmax_element(results.begin(), results.end());

	std::cout << "Результаты\n" << std::fixed << std::setprecision(2)
		<< "Средняя ожидаемая цена через указанное время: " << mean << "\n"
		<< "Минимальная возможная цена: " << *minmax.first << "\n"
		<< "Максимальная возможная цена: " << *minmax.second << "\n";

	return 0;
}