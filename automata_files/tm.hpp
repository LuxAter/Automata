#ifndef AUTOMATA_TM_HPP
#define AUTOMATA_TM_HPP
#include <string>
#include "automaton_base.hpp"
namespace automata {
  class Tm : public Automaton {
   public:
    bool Run(std::string str);
    bool SubRun(std::vector<char> tape, int current_state);
    void SetTapeBase(std::string base);
    std::string TransString(int trans);
    std::string TransString(std::array<int, 5> trans);
    int Type();

   private:
    std::string tape_base = "\u2423";
  };
}
#endif
