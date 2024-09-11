#include <iostream>

class Calculator {
private:
    double num1;
    double num2;

public:
    
    Calculator() : num1(0), num2(0) {}

    
    double add() {
        return num1 + num2;
    }

    
    double multiply() {
        return num1 * num2;
    }

    
    double subtract_1_2() {
        return num1 - num2;
    }

    
    double subtract_2_1() {
        return num2 - num1;
    }

    
    double divide_1_2() {
        if (num2 != 0)
            return num1 / num2;
        else {
            std::cerr << "Ошибка: Деление на ноль!" << std::endl;
            return 0;
        }
    }

    
    double divide_2_1() {
        if (num1 != 0)
            return num2 / num1;
        else {
            std::cerr << "Ошибка: Деление на ноль!" << std::endl;
            return 0;
        }
    }

    
    bool set_num1(double number) {
        if (number != 0) {
            num1 = number;
            return true;
        }
        return false;
    }

    
    bool set_num2(double number) {
        if (number != 0) {
            num2 = number;
            return true;
        }
        return false;
    }
};

int main() {
    Calculator calc;
    double a, b;

    while (true) {
        std::cout << "Введите два числа (или 'q' для выхода):" << std::endl;

        std::cout << "Введите num1: ";
        if (!(std::cin >> a) || !calc.set_num1(a)) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Недопустимое значение для num1. Попробуйте снова." << std::endl;
            continue;
        }

        std::cout << "Введите num2: ";
        if (!(std::cin >> b) || !calc.set_num2(b)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Недопустимое значение для num2. Попробуйте снова." << std::endl;
            continue;
        }

        std::cout << "Сумма: " << calc.add() << std::endl;
        std::cout << "Произведение: " << calc.multiply() << std::endl;
        std::cout << "num1 - num2: " << calc.subtract_1_2() << std::endl;
        std::cout << "num2 - num1: " << calc.subtract_2_1() << std::endl;
        std::cout << "num1 / num2: " << calc.divide_1_2() << std::endl;
        std::cout << "num2 / num1: " << calc.divide_2_1() << std::endl;
        std::cout << std::endl;

        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return 0;
}