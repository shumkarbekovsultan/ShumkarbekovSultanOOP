#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

class Cannon {
private:
    double p; 
public:
    void setProbability(double probability) {
        p = probability;
    }

   int shoot(int n) {
    srand(time(0)); 
    std::cout << "RAND_MAX = " << RAND_MAX << std::endl; 

    for (int i = 0; i < n; ++i) {
        
        double randomValue = (double) rand() / RAND_MAX; 
        std::cout << "Случайное число " << i+1 << ": " << randomValue << std::endl; 
        if (randomValue < p) {
            return 1; 
        }
    }
    return 0; 
}
    double estimatedHitProbability(int n) {
        return 1 - std::pow(1 - p, n);
    }
};

int main() {
    Cannon cannon;
    double probability;
    int n;

    std::cout << "Введите вероятность попадания (в промежутке от 0 до 1): ";
    std::cin >> probability;
    cannon.setProbability(probability);

    std::cout << "Введите количество выстрелов: ";
    std::cin >> n;

    int result = cannon.shoot(n);
    std::cout << "Результат стрельбы: " << result << std::endl;

    double estimatedProbability = cannon.estimatedHitProbability(n);
    std::cout << "Оценочная вероятность поражения цели: " << estimatedProbability << std::endl;

    return 0;
}

