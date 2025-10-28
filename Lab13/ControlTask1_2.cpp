// ���������� ��� ������� � ����� �����

#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <typeinfo>
#include <string>

using namespace std;

// ������� ����������� ����� Vehicle
class Vehicle {
public:
   virtual void move() const = 0;
   virtual void stop() const = 0;  // ��������� ��� ������� 2
   virtual int getMaxSpeed() const = 0;  // ��������� ��� ������� 2
   virtual string getEnvironment() const = 0;  // ��������� ��� ������� 2
   virtual string type() const = 0;
   virtual ~Vehicle() = default;

   static int getTotalCount() {
      return totalCount;
   }

protected:
   static int totalCount;  // ����������
};

// ����������� ����������� ���������� (������ ���� ���)
int Vehicle::totalCount = 0;

// ����� Car
class Car : public Vehicle {
public:
   Car() { totalCount++; }
   ~Car() override { totalCount--; }

   void move() const override {
      cout << "Car is driving on the road." << endl;
   }

   void stop() const override {
      cout << "Car is braking to a stop." << endl;
   }

   int getMaxSpeed() const override {
      return 200;
   }

   string getEnvironment() const override {
      return "Road";
   }

   string type() const override {
      return "Car";
   }
};

// ����� Boat
class Boat : public Vehicle {
public:
   Boat() { totalCount++; }
   ~Boat() override { totalCount--; }

   void move() const override {
      cout << "Boat is sailing on water." << endl;
   }

   void stop() const override {
      cout << "Boat is dropping anchor." << endl;
   }

   int getMaxSpeed() const override {
      return 80;
   }

   string getEnvironment() const override {
      return "Water";
   }

   string type() const override {
      return "Boat";
   }
};

// ����� Plane
class Plane : public Vehicle {
public:
   Plane() { totalCount++; }
   ~Plane() override { totalCount--; }

   void move() const override {
      cout << "Plane is flying in the sky." << endl;
   }

   void stop() const override {
      cout << "Plane is landing and taxiing to a halt." << endl;
   }

   int getMaxSpeed() const override {
      return 900;
   }

   string getEnvironment() const override {
      return "Air";
   }

   string type() const override {
      return "Plane";
   }
};

// ����� AmphibiousVehicle
class AmphibiousVehicle : public Vehicle {
public:
   AmphibiousVehicle() { totalCount++; }
   ~AmphibiousVehicle() override { totalCount--; }

   void move() const override {
      cout << "AmphibiousVehicle is driving on road and sailing on water." << endl;
   }

   void stop() const override {
      cout << "AmphibiousVehicle is stopping on land or water." << endl;
   }

   int getMaxSpeed() const override {
      return 120;
   }

   string getEnvironment() const override {
      return "Road and Water";
   }

   string type() const override {
      return "AmphibiousVehicle";
   }
};

// ������� ��� ������������ � ���� (�� ������� 1)
void serializeToFile(const vector<unique_ptr<Vehicle>>& vehicles, const string& filename) {
   ofstream file(filename);
   if (!file.is_open()) {
      cerr << "Error opening file: " << filename << endl;
      return;
   }

   for (const auto& v : vehicles) {
      string behavior;
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

      file << v->type() << ";" << behavior << endl;
   }

   file.close();
   cout << "Data serialized to " << filename << endl;
}

// ������� ��� ������������ ������������ (������� 2)
void demonstratePolymorphism(const vector<unique_ptr<Vehicle>>& vehicles) {
   cout << "\n=== Polymorphic Behavior ===" << endl;
   for (const auto& v : vehicles) {
      cout << "\nVehicle type: " << v->type() << endl;
      cout << "Environment: " << v->getEnvironment() << endl;
      cout << "Max speed: " << v->getMaxSpeed() << " km/h" << endl;
      v->move();
      v->stop();
   }
}

// ������� ������� 1
int ControlTask1() {
   // ������� ������ ����� ���������� �� Vehicle
   vector<unique_ptr<Vehicle>> vehicles;

   // ��������� ������ ��������� ������ �����
   vehicles.push_back(make_unique<Car>());
   vehicles.push_back(make_unique<Boat>());
   vehicles.push_back(make_unique<Plane>());
   vehicles.push_back(make_unique<AmphibiousVehicle>());
   vehicles.push_back(make_unique<Car>());
   vehicles.push_back(make_unique<Boat>());

   // ������� ���������� � ���� � ��������� ������� �������
   cout << "=== Vehicle Information ===" << endl;
   for (const auto& v : vehicles) {
      cout << v->type() << ": ";
      v->move();
   }

   // ������������ RTTI
   cout << "\n=== RTTI Information ===" << endl;
   for (const auto& v : vehicles) {
      cout << "Type: " << v->type()
         << ", RTTI name: " << typeid(*v).name() << endl;
   }

   // ������� ������� ��������� ������������ �������
   cout << "\nTotal vehicles created: " << Vehicle::getTotalCount() << endl;

   // ������������ � ����
   serializeToFile(vehicles, "vehicles.txt");

   // ������ � ����� ����������� ����� ��� ��������
   cout << "\n=== Serialized File Content ===" << endl;
   ifstream inputFile("vehicles.txt");
   string line;
   while (getline(inputFile, line)) {
      cout << line << endl;
   }
   inputFile.close();

   return 0;
}

// ������� ������� 2
int ControlTask2() {
   // ������� ������ ����� ���������� �� Vehicle
   vector<unique_ptr<Vehicle>> vehicles;

   // ��������� ������ ��������� ������ �����
   vehicles.push_back(make_unique<Car>());
   vehicles.push_back(make_unique<Boat>());
   vehicles.push_back(make_unique<Plane>());
   vehicles.push_back(make_unique<AmphibiousVehicle>());

   // ������������� ����������� ���������
   demonstratePolymorphism(vehicles);

   // ������� ����� ���������� ������������ �������
   cout << "\nTotal vehicles created: " << Vehicle::getTotalCount() << endl;

   return 0;
}

