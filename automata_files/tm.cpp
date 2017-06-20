#include "tm.hpp"
#include "automata.hpp"
#include "automaton_base.hpp"

bool automata::Tm::Run(std::string str) { return (false); }

bool automata::Tm::SubRun(std::vector<char> tape, int current_state) {
  return (false);
}

void automata::Tm::SetTapeBase(std::string base) { tape_base = base; }

std::string automata::Tm::TransString(int trans) { return (std::string()); }

std::string automata::Tm::TransString(std::array<int, 5> trans) {
  std::string out;
  return (out);
}

int automata::Tm::Type() { return (TM); }
