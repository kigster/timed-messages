#ifndef INCLUDE_CCSPEC_CORE_FORMATTERS_TEXT_FORMATTER_H_
#define INCLUDE_CCSPEC_CORE_FORMATTERS_TEXT_FORMATTER_H_

#include <exception>
#include <list>
#include <ostream>

#include "ccspec/core/formatter.h"
#include "ccspec/core/formatters/terminal-colors.hpp"

namespace ccspec {
namespace core {
namespace formatters {

class TextFormatter : public Formatter {
 public:
  virtual void afterEachHookFailed(std::exception_ptr failure) const override;
  virtual void afterAllHookFailed(std::exception_ptr failure) const override;
  virtual void aroundHookFailed(std::exception_ptr failure) const override;
  virtual void dumpFailures(
      const std::list<std::exception_ptr>& failures) const override;
  virtual void dump_summary(const summary_data& _data) const override;
 protected:
  explicit TextFormatter(std::ostream&);

 private:
  void outputException(std::exception_ptr failure) const;
};

}  // namespace formatters
}  // namespace core
}  // namespace ccspec

#endif  // INCLUDE_CCSPEC_CORE_FORMATTERS_TEXT_FORMATTER_H_
