//
// Created by Konstantin Gredeskoul on 2019-07-31.
//

#ifndef MESSAGE_SCHEDULER_FROLICSCHEDULE_H
#define MESSAGE_SCHEDULER_FROLICSCHEDULE_H

#include "MessageScheduler.h"

class FrolicSchedule {
private:
  const char *error = "Frolic Is not Live Yet!";

  char sections[5][20] = {"Friday Poolside", "Friday Night", "Saturday Poolside", "Saturday Night", "Sunday Poolside"};

  MessageScheduler schedule = MessageScheduler();

public:
  FrolicSchedule();

  const MessageScheduler getSchedule() const;

  bool isLive();

  const char *currentSection();

  const char *getSection(int index);

  const char *currentMessage();

  const char *nextMessageIn(int seconds);

  const char *getError() const;
};

#endif //MESSAGE_SCHEDULER_FROLICSCHEDULE_H


