#ifndef INCLUDE_CCSPEC_CORE_FORMATTERS_DOCUMENTATION_FORMATTER_H_
#define INCLUDE_CCSPEC_CORE_FORMATTERS_DOCUMENTATION_FORMATTER_H_

#include <ostream>
#include <string>

#include "ccspec/core/execution_result.h"
#include "ccspec/core/formatters/text_formatter.h"

namespace ccspec {
namespace core {
namespace formatters {

class DocumentationFormatter : public TextFormatter {
 public:
  explicit DocumentationFormatter(std::ostream&);

  void exampleGroupStarted(std::string desc) override;
  void exampleGroupFinished(std::string desc) override;
  void examplePassed(std::string desc, const ExecutionResult&) const override;
  void exampleFailed(std::string desc, const ExecutionResult&) const override;

 private:
  void printIndentation() const;

  int group_level_;
};

}  // namespace formatters
}  // namespace core
}  // namespace ccspec

#endif  // INCLUDE_CCSPEC_CORE_FORMATTERS_DOCUMENTATION_FORMATTER_H_
