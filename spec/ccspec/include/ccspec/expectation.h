#ifndef INCLUDE_CCSPEC_EXPECTATION_H_
#define INCLUDE_CCSPEC_EXPECTATION_H_

#include "expectation/target.h"

#define expect(...) expect(__VA_ARGS__).set_file_info(__FILE__, __LINE__)

#endif  // INCLUDE_CCSPEC_EXPECTATION_H_
