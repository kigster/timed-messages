//
// Created by Konstantin Gredeskoul on 2019-07-30.
//

#ifndef MESSAGE_SCHEDULER_
#define MESSAGE_SCHEDULER_

#include <cstdint>
#include "TimeSensitiveMessage.h"

#define MAX_MESSAGE_COUNT 50

class MessageScheduler {
private:
  time_t now;
  TimeSensitiveMessage *messages[MAX_MESSAGE_COUNT]{};

  uint32_t
    __totalCount = 0, // total count of messages loaded, can not exceed MAX_MESSAGE_COUNT
    __addIndex   = 0; // index of the message slot that the next addMessage() will use

public:
  MessageScheduler();
  MessageScheduler *add(TimeSensitiveMessage *message);

  [[nodiscard]] uint32_t size() const;
  TimeSensitiveMessage *currentMessage();
  TimeSensitiveMessage *nextMessageIn(int seconds);
  [[nodiscard]] TimeSensitiveMessage * messageAt(time_t timestamp) const;

  bool isLive();
};

#endif //MESSAGE_SCHEDULER_R
