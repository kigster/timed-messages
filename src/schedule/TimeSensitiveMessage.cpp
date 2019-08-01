
#include "TimeSensitiveMessage.h"

TimeSensitiveMessage::TimeSensitiveMessage(
  uint32_t year,
  uint8_t month,
  uint8_t day,
  uint8_t hour,
  uint8_t minute,
  uint32_t durationMinutes,
  const char *text) : year(year),
                      month(month),
                      day(day),
                      hour(hour),
                      minute(minute),
                      durationMinutes(durationMinutes) {

  this->message = text;

  time(&now);

  tm_t timeInfo;

  timeInfo.tm_year = year;
  timeInfo.tm_mon  = month;
  timeInfo.tm_mday = day;
  timeInfo.tm_hour = hour;
  timeInfo.tm_min  = minute;
  timeInfo.tm_sec  = 0;

  // startingAt is entirely from the input
  startingAt = mktime(&timeInfo);

  // endingAt is extra duration
  endingAt = startingAt + durationMinutes * 60;
};

