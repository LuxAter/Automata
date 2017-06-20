#include "chars.hpp"
#include <map>
#include <string>

namespace automata {
  std::map<char, std::string> char_map;
};

void automata::LoadChars() {
  char_map['\e'] = "\u03B5";
  char_map['\t'] = "\u2534";
  char_map['\s'] = "\u2423";
}
