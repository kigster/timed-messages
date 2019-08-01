
#include <iostream>

#include "schedule/TimeSensitiveMessage.h"
#include "schedule/MessageScheduler.h"

int main(int argc, const char *argv[]) {

  TimeSensitiveMessage m1 = TimeSensitiveMessage(2019, 7, 30, 11, 00, 90, "LeftCtrl");
  TimeSensitiveMessage m2 = TimeSensitiveMessage(2019, 7, 30, 12, 30, 90, "StickyBeats");

  MessageScheduler scheduler = MessageScheduler();

  scheduler.add(&m1);
  scheduler.add(&m2);

  std::cout << "COMPILED!" << "\n";
  return 0;
}
