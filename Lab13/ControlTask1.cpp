#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <typeinfo>
#include <string>

// Базовый абстрактный класс Vehicle
class Vehicle {
public:
   virtual void move() const = 0;
   virtual std::string type() const = 0;
   virtual ~Vehicle() = default;

   // Статический счетчик всех созданных транспортных средств
   static int getTotalCount() {
      return totalCount;
   }

protected:
   static int totalCount;
};

// Инициализация статического поля
int Vehicle::totalCount = 0;

// Класс Car
class Car : public Vehicle {
public:
   Car() {
      totalCount++;
   }

   void move() const override {
      std::cout << "Car is driving on the road." << std::endl;
   }

   std::string type() const override {
      return "Car";
   }

   ~Car() override {
      totalCount--;
   }
};

// Класс Boat
class Boat : public Vehicle {
public:
   Boat() {
      totalCount++;
   }

   void move() const override {
      std::cout << "Boat is sailing on water." << std::endl;
   }

   std::string type() const override {
      return "Boat";
   }

   ~Boat() override {
      totalCount--;
   }
};

// Класс Plane
class Plane : public Vehicle {
public:
   Plane() {
      totalCount++;
   }

   void move() const override {
      std::cout << "Plane is flying in the sky." << std::endl;
   }

   std::string type() const override {
      return "Plane";
   }

   ~Plane() override {
      totalCount--;
   }
};

// Дополнительный класс AmphibiousVehicle
class AmphibiousVehicle : public Vehicle {
public:
   AmphibiousVehicle() {
      totalCount++;
   }

   void move() const override {
      std::cout << "AmphibiousVehicle is driving on road and sailing on water." << std::endl;
   }

   std::string type() const override {
      return "AmphibiousVehicle";
   }

   ~AmphibiousVehicle() override {
      totalCount--;
   }
};

// Функция для сериализации в файл
void serializeToFile(const std::vector<std::unique_ptr<Vehicle>>& vehicles, const std::string& filename) {
   std::ofstream file(filename);
   if (!file.is_open()) {
      std::cerr << "Error opening file: " << filename << std::endl;
      return;
   }

   for (const auto& v : vehicles) {
      // Сохраняем поведение в строку
      std::string behavior;
      if (v->type() == "Car") {
         behavior = "Car is driving on the road.";
      }
      else if (v->type() == "Boat") {
         behavior = "Boat is sailing on water.";
      }
      else if (v->type() == "Plane") {
         behavior = "Plane is flying in the sky.";
      }
      else if (v->type() == "AmphibiousVehicle") {
         behavior = "AmphibiousVehicle is driving on road and sailing on water.";
      }

      file << v->type() << ";" << behavior << std::endl;
   }

   file.close();
   std::cout << "Data serialized to " << filename << std::endl;
}

int ControlTask1() {
   // Создаем вектор умных указателей на Vehicle
   std::vector<std::unique_ptr<Vehicle>> vehicles;

   // Наполняем вектор объектами разных типов
   vehicles.push_back(std::make_unique<Car>());
   vehicles.push_back(std::make_unique<Boat>());
   vehicles.push_back(std::make_unique<Plane>());
   vehicles.push_back(std::make_unique<AmphibiousVehicle>());
   vehicles.push_back(std::make_unique<Car>());
   vehicles.push_back(std::make_unique<Boat>());

   // Выводим информацию о типе и поведении каждого объекта
   std::cout << "=== Vehicle Information ===" << std::endl;
   for (const auto& v : vehicles) {
      std::cout << v->type() << ": ";
      v->move();
   }

   // Демонстрация RTTI (Run-Time Type Information)
   std::cout << "\n=== RTTI Information ===" << std::endl;
   for (const auto& v : vehicles) {
      std::cout << "Type: " << v->type()
         << ", RTTI name: " << typeid(*v).name() << std::endl;
   }

   // Выводим счетчик созданных транспортных средств
   std::cout << "\nTotal vehicles created: " << Vehicle::getTotalCount() << std::endl;

   // Сериализация в файл
   serializeToFile(vehicles, "vehicles.txt");

   // Чтение и вывод содержимого файла для проверки
   std::cout << "\n=== Serialized File Content ===" << std::endl;
   std::ifstream inputFile("vehicles.txt");
   std::string line;
   while (std::getline(inputFile, line)) {
      std::cout << line << std::endl;
   }
   inputFile.close();

   return 0;
}