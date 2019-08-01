//
// Created by Konstantin Gredeskoul on 2019-07-30.
//

#include "MessageScheduler.h"
#include "TimeSensitiveMessage.h"

// Adds the message, and returns the total number of messages thus far. If it returns
// 0, that means it wrapped around and the message with index 0 will get replaced.
MessageScheduler *MessageScheduler::add(TimeSensitiveMessage *message) {
  messages[++__addIndex] = message;

  __totalCount++;

  if (__totalCount > MAX_MESSAGE_COUNT) {
    __totalCount = MAX_MESSAGE_COUNT;
  }

  __addIndex %= MAX_MESSAGE_COUNT;
  return this;
}

uint32_t MessageScheduler::next() {
  return (__readIndex++) % MAX_MESSAGE_COUNT;
}

uint32_t MessageScheduler::current() {
  return (__readIndex);
}

uint32_t MessageScheduler::size() {
  return __totalCount;
}
