//
// Created by Konstantin Gredeskoul on 2019-07-30.
//

#include "MessageScheduler.h"
#include "TimeSensitiveMessage.h"

// Adds the message, and returns the total number of messages thus far. If it returns
// 0, that means it wrapped around and the message with index 0 will get replaced.
MessageScheduler *MessageScheduler::add(TimeSensitiveMessage *message) {
  messages[__addIndex] = message;

  __addIndex++;
  __totalCount++;

  if (__totalCount > MAX_MESSAGE_COUNT) {
    __totalCount = MAX_MESSAGE_COUNT;
  }

  __addIndex %= MAX_MESSAGE_COUNT;
  return this;
}

uint32_t MessageScheduler::size() const {
  return __totalCount;
}

TimeSensitiveMessage *MessageScheduler::currentMessage() {
  for (TimeSensitiveMessage *msg : messages) {
    if (msg != nullptr && msg->isOnNow())
      return msg;
  }
  return nullptr;
}

bool MessageScheduler::isLive() {
  return (nullptr != currentMessage());
}

TimeSensitiveMessage *MessageScheduler::nextMessageIn(int seconds) {
  time(&now);
  for (TimeSensitiveMessage *msg : messages) {
    if (msg->isOnAt(now + seconds))
      return (msg);
  }

  return nullptr;
}

MessageScheduler::MessageScheduler() {
  __addIndex = 0;
  __totalCount = 0;
}
