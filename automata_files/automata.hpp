#ifndef AUTOMATA_AUTOMATA_HPP
#define AUTOMATA_AUTOMATA_HPP

#define AUTOMATA_VERSION_MAJOR 0
#define AUTOMATA_VERSION_MINOR 0
#define AUTOMATA_VERSION_PATCH 1

namespace automata {

  enum AutomatonTypes { NONE, DFA, PDA, LBA, TM };
  void InitAutomata();
  void TermAutomata();
  void GetVersion(int& major, int& minor, int& patch);
}
#endif
