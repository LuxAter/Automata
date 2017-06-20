#include "automaton_base.hpp"
#include <pessum.h>
#include <array>
#include <fstream>
#include <string>
#include <vector>
#include "automata.hpp"
#include "chars.hpp"

automata::Automaton::Automaton() { name = "automaton"; }

automata::Automaton::Automaton(const Automaton& copy) {
  start_state = copy.start_state;
  name = copy.name;
  language = copy.language;
  accepting_states = copy.accepting_states;
  states = copy.states;
  transitions = copy.transitions;
}

automata::Automaton::~Automaton() {
  language.clear();
  accepting_states.clear();
  states.clear();
  transitions.clear();
}

void automata::Automaton::SetName(std::string in_name) { name = in_name; }

void automata::Automaton::SetStartState(std::string stat) {
  start_state = State(stat);
}

void automata::Automaton::SetStartState(int stat) { start_state = stat; }

void automata::Automaton::SetLanguage(char lang) {
  language.clear();
  language = {lang};
}

void automata::Automaton::SetLanguage(std::vector<char> lang) {
  language.clear();
  language = lang;
}

void automata::Automaton::SetLanguage(std::string lang) {
  language.clear();
  language = std::vector<char>(lang.c_str(), lang.c_str() + lang.length() + 1);
}

void automata::Automaton::AddLanguage(char lang) { language.push_back(lang); }

void automata::Automaton::AddLanguage(std::vector<char> lang) {
  language.insert(language.end(), lang.begin(), lang.end());
}

void automata::Automaton::AddLanguage(std::string lang) {
  std::vector<char> lang_vec(lang.c_str(), lang.c_str() + lang.length() + 1);
  language.insert(language.end(), lang_vec.begin(), lang_vec.end());
}

void automata::Automaton::SetAlphabet(char alpha) {
  alphabet.clear();
  alphabet = {alpha};
}

void automata::Automaton::SetAlphabet(std::vector<char> alpha) {
  alphabet.clear();
  alphabet = alpha;
}

void automata::Automaton::SetAlphabet(std::string alpha) {
  alphabet.clear();
  alphabet =
      std::vector<char>(alpha.c_str(), alpha.c_str() + alpha.length() + 1);
}

void automata::Automaton::AddAlphabet(char alpha) { alphabet.push_back(alpha); }

void automata::Automaton::AddAlphabet(std::vector<char> alpha) {
  alphabet.insert(alphabet.end(), alpha.begin(), alpha.end());
}

void automata::Automaton::AddAlphabet(std::string alpha) {
  std::vector<char> alpha_vec(alpha.c_str(),
                              alpha.c_str() + alpha.length() + 1);
  alphabet.insert(alphabet.end(), alpha_vec.begin(), alpha_vec.end());
}

void automata::Automaton::SetStates(std::string stat) {
  states.clear();
  states = {stat};
}

void automata::Automaton::SetStates(std::vector<std::string> stat) {
  states.clear();
  states = stat;
}

void automata::Automaton::AddStates(std::string stat) {
  states.push_back(stat);
}

void automata::Automaton::AddStates(std::vector<std::string> stat) {
  states.insert(states.end(), stat.begin(), stat.end());
}

void automata::Automaton::SetAccepting(std::string stat) {
  accepting_states.clear();
  int state_index;
  for (state_index = 0; state_index < states.size(); state_index++) {
    if (states[state_index] == stat) {
      break;
    }
  }
  accepting_states = {state_index};
}

void automata::Automaton::SetAccepting(int stat) {
  accepting_states.clear();
  accepting_states = {stat};
}

void automata::Automaton::SetAccepting(std::vector<std::string> stat) {
  accepting_states.clear();
  for (int i = 0; i < stat.size(); i++) {
    int state_index;
    for (state_index = 0; state_index < states.size(); state_index++) {
      if (states[state_index] == stat[i]) {
        break;
      }
    }
    accepting_states.push_back(state_index);
  }
}

void automata::Automaton::SetAccepting(std::vector<int> stat) {
  accepting_states.clear();
  accepting_states = stat;
}

void automata::Automaton::AddAccepting(std::string stat) {
  int state_index;
  for (state_index = 0; state_index < states.size(); state_index++) {
    if (states[state_index] == stat) {
      break;
    }
  }
  accepting_states.push_back(state_index);
}

void automata::Automaton::AddAccepting(int stat) {
  accepting_states.push_back(stat);
}

void automata::Automaton::AddAccepting(std::vector<std::string> stat) {
  for (int i = 0; i < stat.size(); i++) {
    int state_index;
    for (state_index = 0; state_index < states.size(); state_index++) {
      if (states[state_index] == stat[i]) {
        break;
      }
    }
    accepting_states.push_back(state_index);
  }
}

void automata::Automaton::AddAccepting(std::vector<int> stat) {
  accepting_states.insert(accepting_states.end(), stat.begin(), stat.end());
}

bool automata::Automaton::IsAccept(int stat) {
  for (int i = 0; i < accepting_states.size(); i++) {
    if (accepting_states[i] == stat) {
      return (true);
    }
  }
  return (false);
}

void automata::Automaton::SetTransitions(
    std::vector<std::array<int, 5>> trans) {
  transitions.clear();
  transitions = trans;
}

void automata::Automaton::AddTransitions(std::array<int, 5> trans) {
  transitions.push_back(trans);
}

void automata::Automaton::AddTransitions(std::string state_a, char ch,
                                         std::string state_b) {
  if (this->Type() != DFA && this->Type() != NONE) {
    pessum::Log(pessum::WARNING,
                "Transtions for this automaton require different parameters",
                "automata::Automaton::AddTransitions");
  } else {
    transitions.push_back(
        std::array<int, 5>{State(state_a), Language(ch), State(state_b), 0, 0});
  }
}

void automata::Automaton::AddTransitions(std::string state_a, char ch_a,
                                         char ch_b, char ch_c,
                                         std::string state_b) {
  if (this->Type() != PDA && this->Type() != NONE && this->Type() != TM) {
    pessum::Log(pessum::WARNING,
                "Transitions for this automaton require different parameters",
                "automata::Automaton::AddTransitions");
  } else if (this->Type() == PDA) {
    transitions.push_back(std::array<int, 5>{State(state_a), Language(ch_a),
                                             Alphabet(ch_b), Alphabet(ch_c),
                                             State(state_b)});
  } else if (this->Type() == TM) {
    transitions.push_back(std::array<int, 5>{State(state_a), Language(ch_a),
                                             Alphabet(ch_b), Move(ch_c),
                                             State(state_b)});
  }
}

std::vector<std::array<int, 5>> automata::Automaton::GetTransitions(
    std::array<int, 5> match) {
  std::vector<std::array<int, 5>> matched;
  for (int i = 0; i < transitions.size(); i++) {
    bool good = true;
    for (int j = 0; j < 5 && good == true; j++) {
      if ((match[j] != -2 && transitions[i][j] != -1) &&
          match[j] != transitions[i][j]) {
        good = false;
      }
    }
    if (good == true) {
      matched.push_back(transitions[i]);
    }
  }
  return (matched);
}

int automata::Automaton::State(std::string stat) {
  for (int i = 0; i < states.size(); i++) {
    if (states[i] == stat) {
      return (i);
    }
  }
  pessum::Log(pessum::WARNING, "State %s does not exist",
              "automata::Automaton::State", stat.c_str());
  return (0);
}

int automata::Automaton::Language(char ch) {
  for (int i = 0; i < language.size(); i++) {
    if (language[i] == ch) {
      return (i);
    }
  }
  if (ch == '\e') {
    return (-1);
  }
  pessum::Log(pessum::WARNING, "Language does not contain %c",
              "automata::Automaton::Language", ch);
  return (0);
}

int automata::Automaton::Alphabet(char ch) {
  for (int i = 0; i < alphabet.size(); i++) {
    if (alphabet[i] == ch) {
      return (i);
    }
  }
  if (this->Type() == TM) {
    for (int i = 0; i < language.size(); i++) {
      if (language[i] == ch) {
        return (i + alphabet.size());
      }
    }
  }
  if (ch == '\e') {
    return (-1);
  }
  pessum::Log(pessum::WARNING, "Alphabet does not contain %c",
              "automata::Automaton::Alphabet", ch);
  return (0);
}

int automata::Automaton::Move(char ch) {
  if (ch == 'R' || ch == 'r' || ch == 'D' || ch == 'd') {
    return (1);
  } else if (ch == 'L' || ch == 'l' || ch == 'U' || ch == 'u') {
    return (2);
  } else if (ch == 'S' || ch == 's') {
    return (3);
  }
  return (0);
}

std::string automata::Automaton::StrState(int state) {
  if (state >= 0 && state < states.size()) {
    return (states[state]);
  } else if (state < 0) {
    return (char_map['\e']);
  } else {
    return ("null");
  }
}

std::string automata::Automaton::StrLanguage(int lang) {
  if (lang >= 0 && lang < language.size()) {
    if (char_map.find(language[lang]) != char_map.end()) {
      return (char_map[language[lang]]);
    } else {
      return (std::string(1, language[lang]));
    }
  } else if (lang < 0) {
    return (char_map['\e']);
  } else if (lang >= language.size()) {
    return (StrAlphabet(lang - language.size()));
  } else {
    return ("null");
  }
}

std::string automata::Automaton::StrAlphabet(int alpha) {
  if (alpha >= 0 && alpha < alphabet.size()) {
    if (char_map.find(alphabet[alpha]) != char_map.end()) {
      return (char_map[alphabet[alpha]]);
    } else {
      return (std::string(1, alphabet[alpha]));
    }
  } else if (alpha < 0) {
    return (char_map['\e']);
  } else if (alpha >= alphabet.size()) {
    return (StrLanguage(alpha - alphabet.size()));
  } else {
    return ("null");
  }
}

std::string automata::Automaton::StrMove(int move) {
  if (move == 1) {
    return ("R");
  } else if (move == 2) {
    return ("L");
  } else if (move == 3) {
    return ("S");
  } else {
    return ("null");
  }
}

void automata::Automaton::SaveAutomaton(std::string file) {
  std::ofstream out(file.c_str());
  if (out.is_open()) {
    out << name << "\n";
    for (int i = 0; i < language.size(); i++) {
      out << language[i];
    }
    out << "\n";
    for (int i = 0; i < states.size(); i++) {
      out << states[i] << " ";
    }
    out << "\n";
    out << start_state << "\n";
    for (int i = 0; i < accepting_states.size(); i++) {
      out << accepting_states[i] << " ";
    }
    out << "\n";
    for (int i = 0; i < transitions.size(); i++) {
      for (int j = 0; j < 5; j++) {
        out << transitions[i][j] << " ";
      }
      out << "\n";
    }
    out.close();
  } else {
    pessum::Log(pessum::ERROR, "Failed to open output file \"%s\"",
                "automata::Automaton::SaveAutomaton", file.c_str());
  }
}

void automata::Automaton::LoadAutomaton(std::string file) {
  language.clear();
  accepting_states.clear();
  states.clear();
  transitions.clear();
  name = "";
  start_state = 0;
  std::ifstream load(file.c_str());
  if (load.is_open()) {
    std::string line;
    int stage = 0;
    while (getline(load, line)) {
      if (stage == 0) {
        name = line;
        stage = 1;
      } else if (stage == 1) {
        SetLanguage(line);
        stage = 2;
      } else if (stage == 2) {
        std::string sub_string = "";
        for (int i = 0; i < line.size(); i++) {
          if (line[i] == ' ') {
            states.push_back(sub_string);
            sub_string = "";
          } else {
            sub_string += line[i];
          }
        }
        stage = 3;
      } else if (stage == 3) {
        SetStartState(stoi(line));
        stage = 4;
      } else if (stage == 4) {
        std::string sub_string = "";
        for (int i = 0; i < line.size(); i++) {
          if (line[i] == ' ') {
            accepting_states.push_back(stoi(sub_string));
            sub_string = "";
          } else {
            sub_string += line[i];
          }
        }
        stage = 5;
      } else if (stage == 5) {
        std::array<int, 5> trans;
        int index = 0;
        std::string sub_string = "";
        for (int i = 0; i < line.size(); i++) {
          if (line[i] == ' ') {
            trans[index] = stoi(sub_string);
            index++;
            sub_string = "";
          } else {
            sub_string += line[i];
          }
        }
        transitions.push_back(trans);
      }
    }
  } else {
    pessum::Log(pessum::ERROR, "Failed to open input file \"%s\"",
                "automata::Automaton::LoadAutomaton", file.c_str());
  }
}

int automata::Automaton::Type() { return (NONE); }
