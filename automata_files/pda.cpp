#include "pda.hpp"
#include <iostream>
#include "automata.hpp"
#include "automaton_base.hpp"

void automata::Pda::SetAcceptance(int method) { acceptance = method; };

bool automata::Pda::Run(std::string str) {
  int current_state = start_state;
  int state = 0;
  std::vector<char> tape(str.c_str(), str.c_str() + str.length() + 1);
  std::stack<int> p_stack;
  if (tape.size() > 1) {
    int stack_ch;
    if (p_stack.empty() == true) {
      stack_ch = -1;
    } else {
      stack_ch = p_stack.top();
    }
    std::vector<std::array<int, 5>> choices = GetTransitions(
        std::array<int, 5>{current_state, Language(tape[0]), stack_ch, -2, -2});
    for (int j = 0; j < choices.size() && state != 1; j++) {
      current_state = choices[j][4];
      bool pop_check = false;
      if (choices[j][3] != -1) {
        pop_check = true;
      }
      if (choices[j][1] != -1) {
        state = SubRun(std::vector<char>(tape.begin() + 1, tape.end()), p_stack,
                       current_state, choices[j][3], pop_check);
      } else {
        state = SubRun(tape, p_stack, current_state, choices[j][3], pop_check);
      }
    }
    if (choices.size() == 0) {
      state = -1;
    }
  } else if (tape.size() == 1) {
    if (acceptance == PDA_FINAL_STATE && IsAccept(current_state) == true) {
      state = 1;
    } else if (acceptance == PDA_EMPTY_STACK && p_stack.empty()) {
      state = 1;
    } else if (acceptance == PDA_BOTH && IsAccept(current_state) &&
               p_stack.empty()) {
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

bool automata::Pda::SubRun(std::vector<char> tape, std::stack<int> p_stack,
                           int current_state, int stack_push, bool pop_off) {
  if (pop_off && p_stack.empty() == false) {
    p_stack.pop();
  }
  if (stack_push != -1) {
    p_stack.push(stack_push);
  }
  int state = 0;
  if (tape.size() > 1) {
    int stack_ch;
    if (p_stack.empty() == true) {
      stack_ch = -1;
    } else {
      stack_ch = p_stack.top();
    }
    std::vector<std::array<int, 5>> choices = GetTransitions(
        std::array<int, 5>{current_state, Language(tape[0]), stack_ch, -2, -2});
    for (int j = 0; j < choices.size() && state != 1; j++) {
      current_state = choices[j][4];
      bool pop_check = false;
      if (choices[j][2] != -1) {
        pop_check = true;
      }
      if (choices[j][1] != -1) {
        state = SubRun(std::vector<char>(tape.begin() + 1, tape.end()), p_stack,
                       current_state, choices[j][3], pop_check);
      } else {
        state = SubRun(tape, p_stack, current_state, choices[j][3], pop_check);
      }
    }
    if (choices.size() == 0) {
      state = -1;
    }
  } else if (tape.size() == 1) {
    if (acceptance == PDA_FINAL_STATE && IsAccept(current_state) == true) {
      state = 1;
    } else if (acceptance == PDA_EMPTY_STACK && p_stack.empty()) {
      state = 1;
    } else if (acceptance == PDA_BOTH && IsAccept(current_state) &&
               p_stack.empty()) {
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

std::string automata::Pda::TransString(int trans) {
  std::string out =
      states[transitions[trans][0]] + "," + language[transitions[trans][1]] +
      " " + alphabet[transitions[trans][2]] + "/" +
      alphabet[transitions[trans][3]] + "->" + states[transitions[trans][4]];
  return (out);
}
std::string automata::Pda::TransString(std::array<int, 5> trans) {
  std::string out;
  if (trans[0] != -1) {
    out += states[trans[0]];
  } else {
    out += "\u03B5";
  }
  out += ",";
  if (trans[1] != -1) {
    out += language[trans[1]];
  } else {
    out += "\u03B5";
  }
  out += " ";
  if (trans[2] != -1) {
    out += alphabet[trans[2]];
  } else {
    out += "\u03B5";
  }
  out += "/";
  if (trans[3] != -1) {
    out += alphabet[trans[3]];
  } else {
    out += "\u03B5";
  }
  out += "->";
  if (trans[4] != -1) {
    out += states[trans[4]];
  } else {
    out += "\u03B5";
  }
  return (out);
}

int automata::Pda::Type() { return (PDA); }
