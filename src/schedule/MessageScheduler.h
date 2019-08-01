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
  TimeSensitiveMessage *messages[MAX_MESSAGE_COUNT]{};

  uint32_t
    __readIndex  = 0, // total count of messages loaded, can not exceed MAX_MESSAGE_COUNT
    __totalCount = 0, // total count of messages loaded, can not exceed MAX_MESSAGE_COUNT
    __addIndex   = 0; // index of the message slot that the next addMessage() will use
  // if all MAX_MESSAGE_COUNT slots are used, it overwrites the 0's and so on.

public:
  MessageScheduler() = default;

  MessageScheduler *add(TimeSensitiveMessage *message);

  uint32_t next();
  uint32_t current();
  uint32_t size();
};

#endif //MESSAGE_SCHEDULER_
