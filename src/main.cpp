
#include <iostream>

#include "schedule/FrolicSchedule.h"

int main(int argc, const char *argv[]) {
  struct tm tm{};

  FrolicSchedule frolic = FrolicSchedule();

  std::cout << "———————| FROLIC 2019 DJ Scheduler |——————— \n\n";

  std::cout << "Total DJ Count   : " << frolic.getSchedule().size() << "\n";
  std::cout << "Are we live yet? : " << frolic.currentSection() << "\n\n\n";

  if (argc > 1) {
    const char *time = argv[1];
    strptime(time, "%Y/%m/%e %T", &tm);
    time_t ts = mktime(&tm);

    std::cout << "———> Checking DJ Schedule for " << time << "....\n\n";

    const TimeSensitiveMessage *msg = frolic.getSchedule().messageAt(ts);
    if (nullptr == msg) {
      std::cout << "———> Unfortunately, nothing appears to be happening at " << time << "\n\n";
    } else {
      std::cout << "     Hallelujah! \n";
      std::cout << "———> At " << time << " is a special time of " << msg->getSection() << "\n";
      std::cout << "———> and the DJ is... /" << msg->getMessage() << "/\n";
    }
  } else {
    std::cout << "Usage: " << argv[0] << " 'YYYY/MM/DD HH:MM:SS'\n";
    std::cout << "   eg. " << argv[0] << " '2019/08/02 21:30:00'\n";
  }

  return 0;
}
