#include "ccspec/core/formatters/progress_formatter.h"

namespace ccspec {
namespace core {
namespace formatters {

using std::ostream;
using std::string;

// Public methods.

ProgressFormatter::ProgressFormatter(ostream& output) : TextFormatter(output) {}

void ProgressFormatter::examplePassed(string, const ExecutionResult&) const {
  TerminalColor color(COLOR_GREEN);
  output() << '.';
}

void ProgressFormatter::exampleFailed(string, const ExecutionResult&) const {
  TerminalColor color(COLOR_RED);
  output() << 'F';
}

void ProgressFormatter::startDump() const {
  output() << '\n';
}

}  // namespace formatters
}  // namespace core
}  // namespace ccspec
