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
#include "../src/schedule/FrolicSchedule.h"

auto SchedulerSpec = describe("MessageScheduler", [] {
  describe("#add", [] {
    it("adds time sensitive messages to the schedule", [] {
      MessageScheduler scheduler = MessageScheduler();

      TimeSensitiveMessage m1 = TimeSensitiveMessage(2019, 7, 30, 11, 00, 90, "LeftCtrl", "Friday Poolside");
      TimeSensitiveMessage m2 = TimeSensitiveMessage(2019, 7, 30, 12, 30, 90, "StickyBeats", "Sunday Next Week");

      scheduler.add(&m1);
      scheduler.add(&m2);

      expect(scheduler.size()).to(eq(2));
    });
  });

  describe("#Frolic Schedule", [] {
    it("creates a proper Frolic Schedule", [] {
      FrolicSchedule frolic = FrolicSchedule();
      expect(frolic.getSchedule().size()).to(eq(21));
      expect(frolic.currentMessage()).to(eq("Frolic Is not Live Yet!"));
      expect(frolic.isLive()).to(eq(false));
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
