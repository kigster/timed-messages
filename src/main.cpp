
#include <iostream>

#include "schedule/FrolicSchedule.h"

int main(int argc, const char *argv[]) {
  time_t now;
  time(&now);

  std::cout << "Current Timestamp is: " << now << "\n";
  FrolicSchedule frolic = FrolicSchedule();

  std::cout << "Frolic X (2019)" << "\n";

  std::cout << "Total DJ Count : " << frolic.getSchedule().size() << "\n";
  std::cout << "Current Section: " << frolic.currentSection() << "\n";
  std::cout << "Current DJ     : " << frolic.currentMessage() << "\n";

  return 0;
}
