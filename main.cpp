#include <iostream>
#include <cmath>
#include <cassert>
#include <cstdlib>

class Car {
private:
    double x; // координата X
    double y; // координата Y
    double speed; // скорость
    double acceleration; // ускорение
    double angle; // угол движения (в градусах)

public:
    // Конструктор по умолчанию
    Car() : x(0), y(0), speed(0), acceleration(0), angle(0) {}

    // Конструктор инициализации
    Car(double init_x, double init_y, double init_speed, double init_acceleration, double init_angle) {
        assert(init_angle < 360 && init_angle >= 0); // проверка корректности угла
        assert(init_acceleration >= 0); // ускорение не может быть отрицательным
        x = init_x;
        y = init_y;
        speed = init_speed;
        acceleration = init_acceleration;
        angle = init_angle;
    }

    // Конструктор копирования
    Car(const Car &other) {
        x = other.x;
        y = other.y;
        speed = other.speed;
        acceleration = other.acceleration;
        angle = other.angle;
    }

    // Методы доступа к полям (геттеры)
    double getX() const { return x; }
    double getY() const { return y; }
    double getSpeed() const { return speed; }
    double getAcceleration() const { return acceleration; }
    double getAngle() const { return angle; }

    // Методы модификации полей (сеттеры)
    void setSpeed(double new_speed) { speed = new_speed; }
    void setAcceleration(double new_acceleration) {
        assert(new_acceleration >= 0);
        acceleration = new_acceleration;
    }
    void setAngle(double new_angle) {
        assert(new_angle < 360 && new_angle >= 0);
        angle = new_angle;
    }

    // Метод для обновления координат автомобиля
    void updatePosition(double time_interval) {
        // Рассчитываем новые координаты на основании скорости, ускорения и угла
        double radians = angle * M_PI / 180.0; // перевод угла в радианы
        double distance = speed * time_interval + 0.5 * acceleration * time_interval * time_interval;
        x += distance * cos(radians);
        y += distance * sin(radians);
        // Обновляем скорость, учитывая ускорение
        speed += acceleration * time_interval;
    }

    // Деструктор
    ~Car() {}
};

// Тестирование
void runTests() {
    // Тест конструктора по умолчанию
    Car default_car;
    assert(default_car.getX() == 0);
    assert(default_car.getY() == 0);
    assert(default_car.getSpeed() == 0);
    assert(default_car.getAcceleration() == 0);
    assert(default_car.getAngle() == 0);

    // Тест конструктора инициализации
    Car init_car(0, 0, 10, 2, 90);
    assert(init_car.getX() == 0);
    assert(init_car.getY() == 0);
    assert(init_car.getSpeed() == 10);
    assert(init_car.getAcceleration() == 2);
    assert(init_car.getAngle() == 90);

    // Тест конструктора копирования
    Car copy_car(init_car);
    assert(copy_car.getX() == init_car.getX());
    assert(copy_car.getY() == init_car.getY());
    assert(copy_car.getSpeed() == init_car.getSpeed());
    assert(copy_car.getAcceleration() == init_car.getAcceleration());
    assert(copy_car.getAngle() == init_car.getAngle());

    // Тест сеттеров
    default_car.setSpeed(20);
    assert(default_car.getSpeed() == 20);
    default_car.setAcceleration(1.5);
    assert(default_car.getAcceleration() == 1.5);
    default_car.setAngle(45);
    assert(default_car.getAngle() == 45);

    // Тест обновления позиции
    init_car.updatePosition(1); // Обновим позицию на 1 секунду
    assert(std::abs(init_car.getX() - 0) < 1e-5); // Ожидаем, что координата X почти не изменилась
    assert(std::abs(init_car.getY() - 11) < 1e-1); // Ожидаем, что координата Y приблизительно равна 11

    std::cout << "All tests passed successfully!" << std::endl;
}

int main() {
    runTests();
    system("pause");
    return 0;
}
