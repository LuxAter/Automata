#include "tm.hpp"
#include "automata.hpp"
#include "automaton_base.hpp"

bool automata::Tm::Run(std::string str) { return (false); }

bool automata::Tm::SubRun(std::vector<char> tape, int current_state) {
  return (false);
}

void automata::Tm::SetTapeBase(std::string base) { tape_base = base; }

std::string automata::Tm::TransString(int trans) { return (TransString(transitions[trans])); }

std::string automata::Tm::TransString(std::array<int, 5> trans) {
  std::string out = StrState(trans[0]) + "," + StrLanguage(trans[1]) + "/" + StrAlphabet(trans[2]) + "->" + StrMove(trans[3]) + "," + StrState(trans[4]);
  return (out);
}

int automata::Tm::Type() { return (TM); }
