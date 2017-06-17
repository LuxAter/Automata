#include "automaton_base.hpp"
#include <string>
#include <vector>
#include <array>

automata::Automaton::Automaton(){
 name = "automaton";
}

automata::Automaton::Automaton(const Automaton& copy){
  current_state = copy.current_state;
  name = copy.name;
  language = copy.language;
  accepting_states = copy.accepting_states;
  states = copy.states;
  transitions = copy.transitions;
}

automata::Automaton::~Automaton(){
  language.clear();
  accepting_states.clear();
  states.clear();
  transitions.clear();
}

void automata::Automaton::SetName(std::string in_name){
  name = in_name;
}

void automata::Automaton::SetLanguage(char lang){
  language.clear();
  language = {lang};
}

void automata::Automaton::SetLanguage(std::vector<char> lang){
  language.clear();
  language = lang;
}

void automata::Automaton::SetLanguage(std::string lang){
  language.clear();
  language = std::vector<char>(lang.c_str(), lang.c_str() + lang.length() + 1);
}

void automata::Automaton::AddLanguage(char lang){
  language.push_back(lang);
}

void automata::Automaton::AddLanguage(std::vector<char> lang){
  language.insert(language.end(), lang.begin(), lang.end());
}

void automata::Automaton::AddLanguage(std::string lang){
  std::vector<char> lang_vec(lang.c_str(), lang.c_str() + lang.length() + 1);
  language.insert(language.end(), lang_vec.begin(), lang_vec.end());
}

void automata::Automaton::SetStates(std::string stat){
  states.clear();
  states = {stat};
}

void automata::Automaton::SetStates(std::vector<std::string> stat){
  states.clear();
  states = stat;
}

void automata::Automaton::AddStates(std::string stat){
  states.push_back(stat);
}

void automata::Automaton::AddStates(std::vector<std::string> stat){
  states.insert(states.end(), stat.begin(), stat.end());
}

void automata::Automaton::SetAccepting(std::string stat){
  accepting_states.clear();
  int state_index;
  for(state_index = 0; state_index < states.size(); state_index++){
    if(states[state_index] == stat){
      break;
    }
  }
  accepting_states = {state_index};
}

void automata::Automaton::SetAccepting(int stat){
  accepting_states.clear();
  accepting_states = {stat};
}

void automata::Automaton::SetAccepting(std::vector<std::string> stat){
  accepting_states.clear();
  for(int i = 0; i < stat.size(); i++){
    int state_index;
    for(state_index = 0; state_index < states.size(); state_index++){
      if(states[state_index] == stat[i]){
        break;
      }
    }
    accepting_states.push_back(state_index);
  }
}

void automata::Automaton::SetAccepting(std::vector<int> stat){
  accepting_states.clear();
  accepting_states = stat;
}

void automata::Automaton::AddAccepting(std::string stat){
  int state_index;
  for(state_index = 0; state_index < states.size(); state_index++){
    if(states[state_index] == stat){
      break;
    }
  }
  accepting_states.push_back(state_index);
}

void automata::Automaton::AddAccepting(int stat){
  accepting_states.push_back(stat);
}

void automata::Automaton::AddAccepting(std::vector<std::string> stat){
  for(int i = 0; i < stat.size(); i++){
    int state_index;
    for(state_index = 0; state_index < states.size(); state_index++){
      if(states[state_index] == stat[i]){
        break;
      }
    }
    accepting_states.push_back(state_index);
  }
}

void automata::Automaton::AddAccepting(std::vector<int> stat){
  accepting_states.insert(accepting_states.end(), stat.begin(), stat.end());
}
