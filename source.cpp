#include <pessum.h>
#include <iostream>
#include "automata_files/automata_headers.hpp"

using namespace automata;

int main(int argc, const char *argv[]) {
  InitAutomata();
  Dfa dfa;

  // dfa.LoadAutomaton("mot.dfa");

  /*dfa.SetName("Multiple of 3");
  dfa.SetStates(std::vector<std::string>{"s0", "s1", "s2"});
  dfa.SetAccepting("s0");
  dfa.SetStartState("s0");
  dfa.SetLanguage(std::vector<char>{'0', '1'});

  dfa.AddTransitions("s0", '0', "s0");
  dfa.AddTransitions("s0", '1', "s1");
  dfa.AddTransitions("s1", '0', "s2");
  dfa.AddTransitions("s1", '1', "s0");
  dfa.AddTransitions("s2", '0', "s1");
  dfa.AddTransitions("s2", '1', "s2");
  */
  // dfa.SaveAutomaton("mot.dfa");
  dfa.SetStates(std::vector<std::string>{"p", "q"});
  dfa.SetAccepting("q");
  dfa.SetStartState("p");
  dfa.SetLanguage(std::vector<char>{'0', '1'});

  dfa.AddTransitions("p", '0', "p");
  dfa.AddTransitions("p", '1', "p");
  dfa.AddTransitions("p", '1', "q");

  // std::vector<std::string> strings = {"11"};
  std::vector<std::string> strings = {
      "1",    "10",   "11",   "100",  "101",  "110",  "111",  "1000",
      "1001", "1010", "1011", "1100", "1101", "1110", "1111", "10000"};
  for (int i = 0; i < strings.size(); i++) {
    std::cout << strings[i] << "->";
    bool result = dfa.Run(strings[i]);
    if (result == false) {
      std::cout << "false\n";
    } else if (result == true) {
      std::cout << "true\n";
    }
  }
  TermAutomata();
  pessum::SaveLog("out.log");
  return (0);
}
