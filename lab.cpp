#include <iostream>
#include <cstring>
#include <cmath>
#include <cassert>
#include <cstdlib>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;

// Перечисление типов классов
enum class CarType {
    BASE_CAR,
    SPORTS_CAR,
    TRUCK
};

// Базовый класс автомобиля
class Car {
private:
    double x; // координата X
    double y; // координата Y
    double speed; // скорость
    double acceleration; // ускорение
    double angle; // угол движения (в градусах)

protected:
    CarType type; // тип автомобиля

public:
    // Конструктор по умолчанию
    Car() : x(0), y(0), speed(0), acceleration(0), angle(0), type(CarType::BASE_CAR) {}

    // Конструктор инициализации
    Car(double init_x, double init_y, double init_speed, double init_acceleration, double init_angle)
        : x(init_x), y(init_y), speed(init_speed), acceleration(init_acceleration), angle(init_angle), type(CarType::BASE_CAR) {
        assert(init_angle < 360 && init_angle >= 0); // проверка корректности угла
    }

    // Конструктор копирования
    Car(const Car& other) {
        x = other.x;
        y = other.y;
        speed = other.speed;
        acceleration = other.acceleration;
        angle = other.angle;
        type = other.type;
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

    // Виртуальный метод для идентификации типа класса
    virtual CarType identify() const {
        return type;
    }

    // Вывод текущего состояния автомобиля
    virtual void printState() const {
        cout << "Type: Base Car, X: " << x << ", Y: " << y
            << ", Speed: " << speed << ", Acceleration: "
            << acceleration << ", Angle: " << angle << endl;
    }

    // Виртуальный деструктор
    virtual ~Car() {}
};

// Класс спортивной машины (наследник Car)
class SportsCar : public Car {
public:
    SportsCar() : Car() {
        type = CarType::SPORTS_CAR;
    }

    SportsCar(double init_x, double init_y, double init_speed, double init_acceleration, double init_angle)
        : Car(init_x, init_y, init_speed, init_acceleration, init_angle) {
        type = CarType::SPORTS_CAR;
    }

    // Переопределение метода идентификации
    CarType identify() const override {
        return CarType::SPORTS_CAR;
    }

    // Переопределение метода вывода состояния
    void printState() const override {
        cout << "Type: Sports Car, X: " << getX() << ", Y: " << getY()
            << ", Speed: " << getSpeed() << ", Acceleration: "
            << getAcceleration() << ", Angle: " << getAngle() << endl;
    }
};

// Класс грузовика (наследник Car)
class Truck : public Car {
public:
    Truck() : Car() {
        type = CarType::TRUCK;
    }

    Truck(double init_x, double init_y, double init_speed, double init_acceleration, double init_angle)
        : Car(init_x, init_y, init_speed, init_acceleration, init_angle) {
        type = CarType::TRUCK;
    }


    // Переопределение метода идентификации
    CarType identify() const override {
        return CarType::TRUCK;
    }

    // Переопределение метода вывода состояния
    void printState() const override {
        cout << "Type: Truck, X: " << getX() << ", Y: " << getY()
            << ", Speed: " << getSpeed() << ", Acceleration: "
            << getAcceleration() << ", Angle: " << getAngle() << endl;
    }
};

// Функция тестирования
void assertation(Car& outer_car, int test, double time, double expectedX = 0,
    double expectedY = 0, double expectedSpeed = 0,
    double expectedAcceleration = 0, double expectedAngle = 0) {
    const double tolerance = 0.001; // Допустимая погрешность

    switch (test) {
    case 0: { // Тест конструктора по умолчанию
        assert(abs(outer_car.getX() - expectedX) < tolerance);
        assert(abs(outer_car.getY() - expectedY) < tolerance);
        assert(abs(outer_car.getSpeed() - expectedSpeed) < tolerance);
        assert(abs(outer_car.getAcceleration() - expectedAcceleration) < tolerance);
        assert(abs(outer_car.getAngle() - expectedAngle) < tolerance);

        cout << "Tests 'Default Constructor' passed successfully!" << endl;
        break;
    }
    case 1: { // Тест конструктора инициализации
        assert(abs(outer_car.getX() - expectedX) < tolerance);
        assert(abs(outer_car.getY() - expectedY) < tolerance);
        assert(abs(outer_car.getSpeed() - expectedSpeed) < tolerance);
        assert(abs(outer_car.getAcceleration() - expectedAcceleration) < tolerance);
        assert(abs(outer_car.getAngle() - expectedAngle) < tolerance);

        cout << "Tests 'Init Constructor' passed successfully!" << endl;
        break;
    }
    case 2: { // Тест конструктора копирования
        Car copy_car(outer_car);
        assert(abs(copy_car.getX() - outer_car.getX()) < tolerance);
        assert(abs(copy_car.getY() - outer_car.getY()) < tolerance);
        assert(abs(copy_car.getSpeed() - outer_car.getSpeed()) < tolerance);
        assert(abs(copy_car.getAcceleration() - outer_car.getAcceleration()) < tolerance);
        assert(abs(copy_car.getAngle() - outer_car.getAngle()) < tolerance);

        cout << "Tests 'Copy Constructor' passed successfully!" << endl;
        break;
    }
    case 3: { // Тест сеттеров
        outer_car.setSpeed(expectedSpeed);
        assert(abs(outer_car.getSpeed() - expectedSpeed) < tolerance);

        outer_car.setAcceleration(expectedAcceleration);
        assert(abs(outer_car.getAcceleration() - expectedAcceleration) < tolerance);

        outer_car.setAngle(expectedAngle);
        assert(abs(outer_car.getAngle() - expectedAngle) < tolerance);

        cout << "Tests 'Setters' passed successfully!" << endl;
        break;
    }
    case 4: { // Тест обновления позиции
        double initialX = outer_car.getX();
        double initialY = outer_car.getY();
        double initialSpeed = outer_car.getSpeed();
        double initialAcceleration = outer_car.getAcceleration();
        double initialAngle = outer_car.getAngle();

        outer_car.updatePosition(time);

        double radians = initialAngle * M_PI / 180.0;
        double distance = initialSpeed * time + 0.5 * initialAcceleration * time * time;
        double expectedX = initialX + distance * cos(radians);
        double expectedY = initialY + distance * sin(radians);

        cout << "Expected X: " << expectedX << ", Actual X: " << outer_car.getX() << endl;
        cout << "Expected Y: " << expectedY << ", Actual Y: " << outer_car.getY() << endl;

        assert(abs(outer_car.getX() - expectedX) < tolerance);
        assert(abs(outer_car.getY() - expectedY) < tolerance);

        cout << "Tests 'Update Position' passed successfully!" << endl;
        break;
    }
    default:
        cout << "Unknown test!" << endl;
    }
}

int main() {
    // Ввод интервала времени
    double time;
    cout << "Enter time interval: ";
    cin >> time;

    // Тест конструктора по умолчанию
    Car default_car;
    assertation(default_car, 0, time);

    // Тест конструктора инициализации
    SportsCar sports_car(5, 10, 12, -3, 45); // тест спортивного автомобиля
    Truck truck(15, 25, 8, -2, 90); // тест грузовика
    assertation(sports_car, 1, time, 5, 10, 12, -3, 45);
    assertation(truck, 1, time, 15, 25, 8, -2, 90);

    // Вывод информации о каждом автомобиле
    sports_car.printState();
    truck.printState();

    // Тест работы конструктора копирования
    assertation(sports_car, 2, time);

    // Тест работы сеттеров
    assertation(sports_car, 3, time, 0, 0, 50, 2, 60);

    // Тест обновления позиции
    assertation(sports_car, 4, time);
    assertation(truck, 4, time);

    return 0;
}

