#include <iostream>

#include <ccspec/core.h>
#include <ccspec/expectation.h>
#include <ccspec/matchers.h>

using std::cout;
using std::ostringstream;
using ccspec::core::Reporter;
using ccspec::core::after;
using ccspec::core::before;
using ccspec::core::describe;
using ccspec::core::formatters::DocumentationFormatter;
using ccspec::core::it;
using ccspec::matchers::be;
using ccspec::matchers::be_falsey;
using ccspec::matchers::be_truthy;
using ccspec::matchers::eq;
using ccspec::expect;

#include "../src/schedule/TimeSensitiveMessage.h"
#include "../src/schedule/MessageScheduler.h"

auto SchedulerSpec = describe("MessageScheduler", [] {
  describe("#add", [] {
    it("returns back the instance", [] {
      MessageScheduler scheduler = MessageScheduler();

      TimeSensitiveMessage m1 = TimeSensitiveMessage(2019, 7, 30, 11, 00, 90, "LeftCtrl");
      TimeSensitiveMessage m2 = TimeSensitiveMessage(2019, 7, 30, 12, 30, 90, "StickyBeats");

      scheduler.add(&m1);
      scheduler.add(&m2);

      expect(scheduler.size()).to(eq(2));
    });
  });
});

int main() {
  DocumentationFormatter formatter(cout);
  Reporter               reporter(&formatter);
  bool                   succeeded = SchedulerSpec->run(reporter);
  delete SchedulerSpec;
  return !succeeded;
}
