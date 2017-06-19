#ifndef AUTOMATA_PDA_HPP
#define AUTOMATA_PDA_HPP
#include <stack>
#include <string>
#include "automaton_base.hpp"
namespace automata {
  enum PdaAccept { PDA_EMPTY_STACK, PDA_FINAL_STATE, PDA_BOTH };
  class Pda : public Automaton {
   public:
    void SetAcceptance(int method);

    bool Run(std::string str);
    bool SubRun(std::vector<char> tape, std::stack<int> p_stack,
                int current_state, int stack_push, bool pop_off);
    std::string TransString(int trans);
    std::string TransString(std::array<int, 5> trans);
    int Type();

   private:
    std::string tab = ">";
    int acceptance = PDA_BOTH;
  };
}
#endif
