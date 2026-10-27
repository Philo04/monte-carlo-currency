/**
 * @mainpage Моделирование курса валют методом Монте-Карло
 *
 * @section intro Введение
 * Реализована симуляция геометрического броуновского движения (GBM) для оценки цен валют.
 *
 * @section usage Пример использования
 * @code
 * #include "monte_carlo.h"
 * 
 * auto prices = simulate(100., 0.05, 0.2, 1.0, 252, 10000);
 * @endcode
 */
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
