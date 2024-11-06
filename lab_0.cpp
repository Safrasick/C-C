#include <iostream>
#include <cstring>
#include <cmath>
#include <cassert>
#include <cstdlib>
#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

using namespace std;

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
    Car(double init_x, double init_y, double init_speed, double init_acceleration,
        double init_angle) {
        assert(init_angle < 360 && init_angle >= 0); // проверка корректности угла
        assert(init_acceleration >= 0); // ускорение не может быть отрицательным
        x = init_x;
        y = init_y;
        speed = init_speed;
        acceleration = init_acceleration;
        angle = init_angle;
    }

    // Конструктор копирования
    Car(const Car& other) {
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
        double radians = angle * M_PI / 180.0; // перевод угла в радианы
        double distance = speed * time_interval +
            0.5 * acceleration * time_interval * time_interval;
        x += distance * cos(radians);
        y += distance * sin(radians);
        // Обновляем скорость, учитывая ускорение
        speed += acceleration * time_interval;
    }

    // Вывод текущего состояния автомобиля
    void printState() const {
        cout << "X: " << x << ", Y: " << y
            << ", Speed: " << speed << ", Acceleration: "
            << acceleration << ", Angle: " << angle << endl;
    }

    // Деструктор
    ~Car() {}
};

// Функция тестирования
void assertation(Car& outer_car, int test, double time, double expectedX = 0,
    double expectedY = 0, double expectedSpeed = 0,
    double expectedAcceleration = 0, double expectedAngle = 0) {
    switch (test) {
    case 0: {// Тест конструктора по умолчанию
        assert(outer_car.getX() == expectedX);
        assert(outer_car.getY() == expectedY);
        assert(outer_car.getSpeed() == expectedSpeed);
        assert(outer_car.getAcceleration() == expectedAcceleration);
        assert(outer_car.getAngle() == expectedAngle);

        cout << "Tests 'Default Constructor' passed successfully!" << endl;
        break;
    }
    case 1: {// Тест конструктора инициализации
        assert(outer_car.getX() == expectedX);
        assert(outer_car.getY() == expectedY);
        assert(outer_car.getSpeed() == expectedSpeed);
        assert(outer_car.getAcceleration() == expectedAcceleration);
        assert(outer_car.getAngle() == expectedAngle);

        cout << "Tests 'Init Constructor' passed successfully!" << endl;
        break;
    }
    case 2: {// Тест конструктора копирования
        Car copy_car(outer_car);
        assert(copy_car.getX() == outer_car.getX());
        assert(copy_car.getY() == outer_car.getY());
        assert(copy_car.getSpeed() == outer_car.getSpeed());
        assert(copy_car.getAcceleration() == outer_car.getAcceleration());
        assert(copy_car.getAngle() == outer_car.getAngle());

        cout << "Tests 'Copy Constructor' passed successfully!" << endl;
        break;
    }
    case 3: {// Тест сеттеров
        outer_car.setSpeed(expectedSpeed);
        assert(outer_car.getSpeed() == expectedSpeed);

        outer_car.setAcceleration(expectedAcceleration);
        assert(outer_car.getAcceleration() == expectedAcceleration);

        outer_car.setAngle(expectedAngle);
        assert(outer_car.getAngle() == expectedAngle);

        cout << "Tests 'Setters' passed successfully!" << endl;
        break;
    }
    case 4: {// Тест обновления позиции
        // Сохраняем начальные значения до обновления позиции
        double initialX = outer_car.getX();
        double initialY = outer_car.getY();
        double initialSpeed = outer_car.getSpeed();
        double initialAcceleration = outer_car.getAcceleration();
        double initialAngle = outer_car.getAngle();

        outer_car.updatePosition(time); // Обновим позицию на время, введенное пользователем

        double radians = initialAngle * M_PI / 180.0;

        // Расчет расстояния на основании начальной скорости и ускорения
        double distance = initialSpeed * time +
            0.5 * initialAcceleration * time * time;
        double expectedX = initialX + distance * cos(radians);
        double expectedY = initialY + distance * sin(radians);

        cout << "Expected X: " << expectedX
            << ", Actual X: " << outer_car.getX() << endl;
        cout << "Expected Y: " << expectedY
            << ", Actual Y: " << outer_car.getY() << endl;

        assert(abs(outer_car.getX() - expectedX) < 0.1); // Погрешность
        assert(abs(outer_car.getY() - expectedY) < 0.1); // Погрешность

        cout << "Tests 'Position' passed successfully!" << endl;
        break;
    }
    default: {
        cout << "Test variant not available!" << endl;
        break;
    }
    }
}

int main() {
    // Ввод времени для обновления позиции
    double time;
    cout << "Enter time interval: ";
    cin >> time;

    // Создаем экземпляры машин
    Car default_car;
    Car init_car(0, 0, 10, 2, 90);

    // Тестируем созданные машинки
    assertation(default_car, 0, time, 0, 0, 0, 0, 0);
    assertation(init_car, 1, time, 0, 0, 10, 2, 90);
    assertation(init_car, 2, time);
    assertation(default_car, 3, time, 0, 0, 10, 2, 90);
    assertation(init_car, 4, time);

    return 0;
}

