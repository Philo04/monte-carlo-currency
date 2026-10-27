#ifndef MONTE_CARLO_H
#define MONTE_CARLO_H

#include <vector>

/**
 * @brief Симуляция геометрического броуновского движения (GBM).
 * 
 * @param s0 Начальная цена валюты.
 * @param mu Ожидаемая доходность (тренд).
 * @param sigma Волатильность.
 * @param time Время в годах.
 * @param steps Количество шагов.
 * @param simulations Количество симуляций.
 * @return std::vector<double> Массив конечных цен.
 */
std::vector<double> simulate(double s0, double mu, double sigma, double time, int steps, int simulations);

#endif