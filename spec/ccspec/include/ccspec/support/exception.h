#ifndef INCLUDE_CCSPEC_SUPPORT_EXCEPTION_H_
#define INCLUDE_CCSPEC_SUPPORT_EXCEPTION_H_

#include <exception>
#include <string>

namespace ccspec {
namespace support {

// Base class for CCSpec exceptions.
class Exception : public std::exception {
 public:
  const char* what() const noexcept override;

 public:
   Exception& set_file_info(const char* _file_name, int _file_line){
     desc_ = std::string(_file_name) + ":" + std::to_string(_file_line) + " : " + desc_;     
     return *this;
   }
 protected:
  // Constructs a CCSpec exception with the given description.
  explicit Exception(std::string desc);

 private:
   std::string desc_;
};

}  // namespace support
}  // namespace ccspec

#endif  // INCLUDE_CCSPEC_SUPPORT_EXCEPTION_H_
