#include "dfa.hpp"
#include <iostream>
#include <string>
#include "automata.hpp"
#include "automaton_base.hpp"

bool automata::Dfa::Run(std::string str) {
  int current_state = start_state;
  int state = 0;
  std::vector<char> tape(str.c_str(), str.c_str() + str.length() + 1);
  if (tape.size() > 1) {
    std::vector<std::array<int, 3>> choices =
        GetTransitions(std::array<int, 2>{current_state, Language(tape[0])});
    for (int j = 0; j < choices.size() && state != 1; j++) {
      current_state = choices[j][2];
      state = SubRun(std::vector<char>(tape.begin() + 1, tape.end()),
                     current_state);
    }
    if (choices.size() == 0) {
      state = -1;
    }
  } else if (tape.size() == 1) {
    if (IsAccept(current_state) == true) {
      state = 1;
    }
  }
  if (state == 0 || state == -1) {
    return (false);
  } else if (state == 1) {
    return (true);
  }
  return (false);
}

bool automata::Dfa::SubRun(std::vector<char> tape, int current_state) {
  int state = 0;
  if (tape.size() > 1) {
    std::vector<std::array<int, 3>> choices =
        GetTransitions(std::array<int, 2>{current_state, Language(tape[0])});
    for (int j = 0; j < choices.size() && state != 1; j++) {
      current_state = choices[j][2];
      state = SubRun(std::vector<char>(tape.begin() + 1, tape.end()),
                     current_state);
    }
    if (choices.size() == 0) {
      state = -1;
    }
  } else if (tape.size() == 1) {
    if (IsAccept(current_state) == true) {
      state = 1;
    }
  }
  if (state == 0 || state == -1) {
    return (false);
  } else if (state == 1) {
    return (true);
  }
  return (false);
}

std::string automata::Dfa::TransitionStr(std::array<int, 3> trans) {
  std::string out =
      states[trans[0]] + "," + language[trans[1]] + "->" + states[trans[2]];
  return (out);
}

int automata::Dfa::Type() { return (DFA); }
