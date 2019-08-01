
#ifndef ScheduleMessage_H
#define ScheduleMessage_H

#include <cstddef>
#include <cstdint>
#include <ctime>

#include <cstddef>
#include <cstdint>
#include <ctime>

typedef struct tm tm_t;

class TimeSensitiveMessage {
private:
  time_t startingAt, endingAt, now;

public:
  uint32_t   year;
  uint8_t    month;
  uint8_t    day;
  uint8_t    hour;
  uint8_t    minute;
  uint32_t   durationMinutes;

  const char *message;

  TimeSensitiveMessage(
    uint32_t year,
    uint8_t month,
    uint8_t day,
    uint8_t hour,
    uint8_t minute,
    uint32_t durationMinutes,
    const char *text);

//  bool TimeSensitiveMessage::operator<(TimeSensitiveMessage other) const {
//    return startingAt < other.startingAt;
//  }
};

#endif


