
#include <iostream>
#include "TimeSensitiveMessage.h"

TimeSensitiveMessage::TimeSensitiveMessage(
  uint32_t year,
  uint8_t month,
  uint8_t day,
  uint8_t hour,
  uint8_t minute,
  uint32_t durationMinutes,
  const char *text,
  const char *section) : year(year),
                         month(month),
                         day(day),
                         hour(hour),
                         minute(minute),
                         durationMinutes(durationMinutes) {
  this->message = text;
  this->section = section;

  time(&now);

  tm_t timeInfo;

  timeInfo.tm_year = year - 1900;
  timeInfo.tm_mon  = month - 1;
  timeInfo.tm_mday = day;
  timeInfo.tm_hour = hour;
  timeInfo.tm_min  = minute;
  timeInfo.tm_sec  = 0;

  // startingAt is entirely from the input
  this->startingAt = mktime(&timeInfo);
  // endingAt is extra duration
  this->endingAt = this->startingAt + durationMinutes * 60;

#ifdef DEBUG
  char buffer[1024];
  
  sprintf(buffer,
    "Secton [%s] DJ [%s] starts at [%d], done at [%d]\n",
    this->section,
    this->message,
    this->startingAt,
    this->endingAt);

  std::cout << buffer;
#endif

};


time_t TimeSensitiveMessage::getStartingAt() const {
  return startingAt;
}

time_t TimeSensitiveMessage::getEndingAt() const {
  return endingAt;
}

uint32_t TimeSensitiveMessage::getDurationMinutes() const {
  return durationMinutes;
}

const char *TimeSensitiveMessage::getMessage() const {
  return message;
}

const char *TimeSensitiveMessage::getSection() const {
  return section;
}

uint32_t TimeSensitiveMessage::getDurationSeconds() const {
  return durationMinutes * 60;
}

bool TimeSensitiveMessage::isOnAt(time_t when) {
  return (when >= getStartingAt() && when <= getEndingAt());
}

bool TimeSensitiveMessage::isOnNow() {
  time(&now);
  return isOnAt(now);
}

uint32_t TimeSensitiveMessage::secondsToStart() {
  time(&now);
  if (getStartingAt() > now) {
    return (getStartingAt() - now);
  } else {
    return (-1);
  }
}
