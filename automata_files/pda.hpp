#ifndef AUTOMATA_PDA_HPP
#define AUTOMATA_PDA_HPP
#include <string>
#include "automaton_base.hpp"
namespace automata {
  class Pda : public Automaton {
   public:
    bool Run(std::string str);
    bool SubRun(std::vector<char> tape, int current_state);
    std::string TransString(int trans);
    int Type();

    void SetStackAlphabet(std::string alpha);
    void SetStackAlphabet(std::vector<char> alpha);

   private:
    std::vector<char> alphabet;
  };
}
#endif
