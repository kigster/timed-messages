//
// Created by Konstantin Gredeskoul on 2019-07-31.
//

#include "FrolicSchedule.h"
#include "MessageScheduler.h"
#include "TimeSensitiveMessage.h"

FrolicSchedule::FrolicSchedule() {

  // Friday Day
  //
  //   3:00 - 4:30pm Simon Mark
  //   4:30 - 5:45pm Architecture
  //

  schedule.add(new TimeSensitiveMessage(2019, 8, 2, 3, 0, 90, "Simon Mark", sections[0]));
  schedule.add(new TimeSensitiveMessage(2019, 8, 2, 4, 30, 90, "Architecture", sections[0]));

  // Friday Night
  //
  //     9:00 - 10:15pm  Exoendo
  //    10:15 - 11:30pm  Betty Ray
  //    11:30 - 12:45am  LeftCtrl
  //    12:45 -  2:00am  aacdebo
  //     2:00 -  3:15am  Micron

  schedule.add(new TimeSensitiveMessage(2019, 8, 2, 21, 0, 75, "Exoendo", sections[1]));
  schedule.add(new TimeSensitiveMessage(2019, 8, 2, 22, 15, 75, "Betty Ray", sections[1]));
  schedule.add(new TimeSensitiveMessage(2019, 8, 2, 23, 30, 75, "LeftCtrl", sections[1]));
  schedule.add(new TimeSensitiveMessage(2019, 8, 3, 0, 45, 75, "aacdebo", sections[1]));
  schedule.add(new TimeSensitiveMessage(2019, 8, 3, 2, 30, 75, "Micron", sections[1]));


  //  Saturday - Poolside
  //
  //  11:30 - 12:45pm  bassben
  //  12:45 -  2:00pm  rrrus
  //   2:00 -  3:15pm  Ghost Squadron
  //   3:15 -  4:30pm  kev/null
  //   4:30 -  6:00pm  Daniel V

  schedule.add(new TimeSensitiveMessage(2019, 8, 3, 11, 30, 75, "bassben", sections[2]));
  schedule.add(new TimeSensitiveMessage(2019, 8, 3, 12, 45, 75, "rrrus", sections[2]));
  schedule.add(new TimeSensitiveMessage(2019, 8, 3,  2,  0, 75, "Ghost Squadron", sections[2]));
  schedule.add(new TimeSensitiveMessage(2019, 8, 3,  3, 15, 75, "kev/null", sections[2]));
  schedule.add(new TimeSensitiveMessage(2019, 8, 3,  4, 30, 90, "Daniel V", sections[2]));

  // Saturday - Night
  //
  //  9:30 - 10:45pm Chloramor
  // 10:45 - 11:00pm Ceremony
  // 11:00 - 12:15am davesimon
  // 12:15 -  1:30am Kem
  //  1:30 -  2:45am Dulce Vitas
  //  2:45 -  4:00am Dan Suda
  //  4:00 -  5:30am Stickybeats
  //  5:30 -  6:45am Mo Corleone

  schedule.add(new TimeSensitiveMessage(2019, 8, 3, 21, 30, 75, "Chloramor", sections[3]));
  schedule.add(new TimeSensitiveMessage(2019, 8, 3, 22, 45, 75, "Ceremony", sections[3]));
  schedule.add(new TimeSensitiveMessage(2019, 8, 3, 23, 0, 75, "davesimon", sections[3]));

  schedule.add(new TimeSensitiveMessage(2019, 8, 4, 0, 15, 75, "Kem", sections[3]));
  schedule.add(new TimeSensitiveMessage(2019, 8, 4, 1, 30, 75, "Dulce Vita", sections[3]));
  schedule.add(new TimeSensitiveMessage(2019, 8, 4, 2, 45, 75, "Dan Suda", sections[3]));
  schedule.add(new TimeSensitiveMessage(2019, 8, 4, 4, 0, 90, "Stickybeats", sections[3]));
  schedule.add(new TimeSensitiveMessage(2019, 8, 4, 5, 30, 75, "Mo Corleone", sections[3]));

  // Sunday Morning - Poolside
  //
  // 10:30 -12:00pm Erik Karki
  schedule.add(new TimeSensitiveMessage(2019, 8, 4, 10, 30, 90, "Erik Karki", sections[4]));
}

bool FrolicSchedule::isLive() {
  return (schedule.currentMessage() != nullptr);
}

const char *FrolicSchedule::currentSection() {
  TimeSensitiveMessage *msg = schedule.currentMessage();
  if (msg != nullptr) {
    return const_cast<char *>(msg->getSection());
  } else {
    return getError();
  }
}

const char *FrolicSchedule::currentMessage() {
  TimeSensitiveMessage *msg = schedule.currentMessage();
  if (msg != nullptr) {
    return const_cast<char *>(msg->getMessage());
  } else {
    return getError();
  }
}

const char *FrolicSchedule::nextMessageIn(int seconds) {
  TimeSensitiveMessage *msg = schedule.nextMessageIn(seconds);
  if (msg != nullptr) {
    return const_cast<char *>(msg->getMessage());
  } else {
    return getError();
  }
}

const char *FrolicSchedule::getError() const {
  return error;
}

const MessageScheduler FrolicSchedule::getSchedule() const {
  return schedule;
}

const char *FrolicSchedule::getSection(int index) {
  if (index <= sizeof(sections)) {
    return sections[index];
  } else {
    return nullptr;
  }
}
