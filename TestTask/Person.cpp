#include "Person.h"

Person::Person(const std::string& first, const std::string& last,
   const std::string& ph, const std::string& em)
   : firstName(first), lastName(last), phone(ph), email(em) {
}