#include <pessum.h>
#include <iostream>
#include "automata_files/automata_headers.hpp"

using namespace automata;

int main(int argc, const char *argv[]) {
  InitAutomata();
  Dfa dfa;
  dfa.LoadAutomaton("mot.dfa");
  Pda pda;
  pda.LoadAutomaton("pal.pda");
  // std::vector<std::string> strings = {"aa", "ab"};
  std::vector<std::string> strings = {
      "1",    "10",   "11",   "100",  "101",  "110",  "111",  "1000",
      "1001", "1010", "1011", "1100", "1101", "1110", "1111", "10000"};
  std::cout << "DFA:\n";
  for (int i = 0; i < strings.size(); i++) {
    std::cout << strings[i] << "->";
    bool result = true;
    result = dfa.Run(strings[i]);
    if (result == false) {
      std::cout << "false\n";
    } else if (result == true) {
      std::cout << "true\n";
    }
  }
  std::cout << "PDA:\n";
  for (int i = 0; i < strings.size(); i++) {
    std::cout << strings[i] << "->";
    bool result = true;
    result = pda.Run(strings[i]);
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
