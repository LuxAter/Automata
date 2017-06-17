#include <pessum.h>
#include <iostream>
#include "automata_files/automata_headers.hpp"

using namespace automata;

int main(int argc, const char *argv[]) {
  InitAutomata();
  Dfa dfa;

  dfa.SetStates(std::vector<std::string>{"p", "q"});
  dfa.SetAccepting("q");
  dfa.SetStartState("p");
  dfa.SetLanguage(std::vector<char>{'0', '1'});

  dfa.AddTransitions("p", '0', "p");
  dfa.AddTransitions("p", '1', "p");
  dfa.AddTransitions("p", '1', "q");

  // std::vector<std::string> strings = {"1"};
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
