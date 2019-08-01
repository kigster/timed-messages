
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
  time_t     startingAt, endingAt, now;
  const char *message;
  const char *section;

public:
  uint32_t year;
  uint8_t  month;
  uint8_t  day;
  uint8_t  hour;
  uint8_t  minute;
  uint32_t durationMinutes;

  TimeSensitiveMessage(
    uint32_t year,
    uint8_t month,
    uint8_t day,
    uint8_t hour,
    uint8_t minute,
    uint32_t durationMinutes,
    const char *text,
    const char *section);

  [[nodiscard]] const char *getMessage() const;

  [[nodiscard]] const char *getSection() const;

  [[nodiscard]] time_t getStartingAt() const;

  [[nodiscard]] time_t getEndingAt() const;

  [[nodiscard]] uint32_t getDurationMinutes() const;

  [[nodiscard]] uint32_t getDurationSeconds() const;

  bool isOnAt(time_t when);
  bool isOnNow();

  uint32_t secondsToStart();

  bool operator<(TimeSensitiveMessage other) const {
    return startingAt < other.startingAt;
  }
};

#endif


