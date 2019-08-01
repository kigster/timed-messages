#ifndef INCLUDE_CCSPEC_CORE_FORMATTER_H_
#define INCLUDE_CCSPEC_CORE_FORMATTER_H_

#include <exception>
#include <list>
#include <ostream>
#include <string>

#include "ccspec/core/execution_result.h"

namespace ccspec {
namespace core {
struct summary_data{
  int m_total;
  int m_failed;  
};
class Formatter {
 public:
  virtual void exampleGroupStarted(std::string desc);
  virtual void exampleGroupFinished(std::string desc);
  virtual void examplePassed(std::string desc, const ExecutionResult&) const;
  virtual void exampleFailed(std::string desc, const ExecutionResult&) const;
  virtual void afterEachHookFailed(std::exception_ptr failure) const;
  virtual void afterAllHookFailed(std::exception_ptr failure) const;
  virtual void aroundHookFailed(std::exception_ptr failure) const;
  virtual void startDump() const;
  virtual void dumpFailures(
      const std::list<std::exception_ptr>& failures) const;

  virtual void dump_message(const std::string& _message) const;
  virtual void dump_summary(const summary_data& _data) const;
 protected:
  explicit Formatter(std::ostream&);
  virtual ~Formatter();

  std::ostream& output() const;

 private:
  std::ostream& output_;
};

}  // namespace core
}  // namespace ccspec

#endif  // INCLUDE_CCSPEC_CORE_FORMATTER_H_
