#ifndef AUTOMATA_CHARS_HPP
#define AUTOMATA_CHARS_HPP
#include <map>
#include <string>
namespace automata {
  extern std::map<char, std::string> char_map;
  void LoadChars();
}
#endif
