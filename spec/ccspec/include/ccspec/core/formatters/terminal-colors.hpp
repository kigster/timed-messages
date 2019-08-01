/** @file */
#ifndef INCLUDE_CCSPEC_CORE_FORMATTERS_TERMINAL_COLORS_HPP_
#define INCLUDE_CCSPEC_CORE_FORMATTERS_TERMINAL_COLORS_HPP_
#pragma once
#include <iostream>
// the following are Unix/BASH ONLY terminal color codes.
inline constexpr const char* COLOR_RESET = "\033[0m";  
inline constexpr const char* COLOR_BLACK = "\033[30m" ;              /* Black */
inline constexpr const char* COLOR_RED = "\033[31m" ;                /* Red */
inline constexpr const char* COLOR_GREEN = "\033[32m" ;              /* Green */
inline constexpr const char* COLOR_YELLOW = "\033[33m" ;             /* Yellow */
inline constexpr const char* COLOR_BLUE = "\033[34m" ;               /* Blue */
inline constexpr const char* COLOR_MAGENTA = "\033[35m" ;            /* Magenta */
inline constexpr const char* COLOR_CYAN = "\033[36m" ;               /* Cyan */
inline constexpr const char* COLOR_WHITE = "\033[37m" ;              /* White */
inline constexpr const char* COLOR_BOLDBLACK = "\033[1m\033[30m" ;   /* Bold Black */
inline constexpr const char* COLOR_BOLDRED = "\033[1m\033[31m" ;     /* Bold Red */
inline constexpr const char* COLOR_BOLDGREEN = "\033[1m\033[32m" ;   /* Bold Green */
inline constexpr const char* COLOR_BOLDYELLOW = "\033[1m\033[33m" ;  /* Bold Yellow */
inline constexpr const char* COLOR_BOLDBLUE = "\033[1m\033[34m" ;    /* Bold Blue */
inline constexpr const char* COLOR_BOLDMAGENTA = "\033[1m\033[35m" ; /* Bold Magenta */
inline constexpr const char* COLOR_BOLDCYAN = "\033[1m\033[36m" ;    /* Bold Cyan */
inline constexpr const char* COLOR_BOLDWHITE = "\033[1m\033[37m" ;   /* Bold White */

namespace ccspec {
namespace core {
namespace formatters {

class TerminalColor
{
public:
  TerminalColor(const char* _color)
  {
    m_origin = s_instance;
    s_instance = _color;     
    set_terminal_color();   
  }

  ~TerminalColor(){
    s_instance = m_origin;    
    set_terminal_color();
  }
private:
  void set_terminal_color(){
    std::cout << s_instance;
  }  
private:
  const char* m_origin;
private:
  static inline const char* s_instance = COLOR_RESET;
};

}  // namespace formatters
}  // namespace core
}  // namespace ccspec

#endif //INCLUDE_CCSPEC_CORE_FORMATTERS_TERMINAL_COLORS_HPP_