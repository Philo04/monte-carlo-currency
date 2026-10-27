# Monte Carlo Currency Simulator

Программа моделирует курс валют методом Монте-Карло с помощью геометрического броуновского движения.

## Сборка
```bash
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

## Запуск программы

### Параметры командной строки
```
  --initial-price <double>  Начальная цена валюты (по умолчанию: 100.0)
  --trend <double>          Ожидаемая доходность (тренд) (по умолчанию: 0.05)
  --volatility <double>     Волатильность (по умолчанию: 0.2)
  --time <double>           Время в годах (по умолчанию: 1.0)
  --steps <int>             Количество шагов (по умолчанию: 252)
  --simulations <int>       Количество симуляций (по умолчанию: 10000)
  --help                    Показать список параметров и выйти
```

### Примеры запуска
```bash
./build/monte_carlo_app
./build/monte_carlo_app --initial-price 150.5 --volatility 0.35 --time 2 --steps 504 --simulations 50000
```

## Документация

Документация кода доступна в https://philo04.github.io/monte-carlo-currency/