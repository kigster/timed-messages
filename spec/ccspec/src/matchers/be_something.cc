#include "ccspec/matchers/be_something.h"

namespace ccspec {
namespace matchers {

const BeSomething& be = BeSomething::instance();

// Public methods.

const BeSomething& BeSomething::instance() {
  static BeSomething instance;
  return instance;
}

}  // namespace matchers
}  // namespace ccspec
