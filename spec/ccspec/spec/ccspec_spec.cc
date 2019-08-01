#include <iostream>

#include "ccspec/core.h"
#include "ccspec/cmdline.h"

using std::cout;
using ccspec::core::formatters::DocumentationFormatter;
using ccspec::core::ExampleGroup;
using ccspec::core::Reporter;

namespace spec {
namespace core {

extern ExampleGroup* execution_result_spec;
extern ExampleGroup* unexpected_throw_spec;

}  // namespace core

namespace expectation {

extern ExampleGroup* mismatch_spec;
extern ExampleGroup* unexpected_match_spec;

}  // namespace expectation

namespace matchers {

extern ExampleGroup* be_compared_to_spec;
extern ExampleGroup* be_falsey_spec;
extern ExampleGroup* be_something_spec;
extern ExampleGroup* be_spec;
extern ExampleGroup* be_truthy_spec;
extern ExampleGroup* contain_spec;
extern ExampleGroup* eq_spec;
extern ExampleGroup* match_spec;

}  // namespace matchers

namespace support {

extern ExampleGroup* exception_spec;
extern ExampleGroup* inspect_spec;

}  // namespace support
}  // namespace spec

int main(int argc, char **argv) {

  // create a parser
  cmdline::parser cmd_parser;

  // add specified type of variable.
  // 1st argument is long name
  // 2nd argument is short name (no short name if '\0' specified)
  // 3rd argument is description
  // 4th argument is mandatory (optional. default is false)
  // 5th argument is default value  (optional. it used when mandatory is false)
  cmd_parser.add<std::string>("tags", '\0', "special tags",false, "");
  cmd_parser.parse_check(argc, argv);

  std::string tag = cmd_parser.get<std::string>("tags");

  DocumentationFormatter formatter(cout);
  Reporter reporter(&formatter);

  // ExampleGroup* example_groups[] = {
  //   spec::core::execution_result_spec,
  //   spec::core::unexpected_throw_spec,
  //   spec::expectation::mismatch_spec,
  //   spec::expectation::unexpected_match_spec,
  //   spec::matchers::be_compared_to_spec,
  //   spec::matchers::be_falsey_spec,
  //   spec::matchers::be_something_spec,
  //   spec::matchers::be_spec,
  //   spec::matchers::be_truthy_spec,
  //   spec::matchers::contain_spec,
  //   spec::matchers::eq_spec,
  //   spec::matchers::match_spec,
  //   spec::support::exception_spec,
  //   spec::support::inspect_spec,
  // };
  bool succeeded = true;  
  
  auto& group_manager = ccspec::core::ExampleGroupManager::getInstance();
  auto example_groups = group_manager.filter_groups(tag);
  for (auto example_group : example_groups) {
    succeeded = example_group->run(reporter) && succeeded;
    delete example_group;
  }

  return !succeeded;
}
