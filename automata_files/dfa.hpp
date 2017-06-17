#ifndef AUTOMATA_DFA_HPP
#define AUTOMATA_DFA_HPP
#include <string>
#include "automaton_base.hpp"
namespace automata {
  class Dfa : public Automaton {
   public:
    bool Run(std::string str);
    bool SubRun(std::vector<char> tape, int current_state);
    std::string TransitionStr(std::array<int, 3> trans);
    int Type();

   private:
  };
}
#endif
