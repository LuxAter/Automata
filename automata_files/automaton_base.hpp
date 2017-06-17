#ifndef AUTOMATA_AUTOMATON_BASE_HPP
#define AUTOMATA_AUTOMATON_BASE_HPP
#include <string>
#include <vector>
#include <array>
namespace automata{
  class Automaton{
    public:
      Automaton();
      Automaton(const Automaton& copy);
      ~Automaton();
      
      void SetName(std::string in_name);

      void SetLanguage(char lang);
      void SetLanguage(std::vector<char> lang);
      void SetLanguage(std::string lang);
      void AddLanguage(char lang);
      void AddLanguage(std::vector<char> lang);
      void AddLanguage(std::string lang);
      
      void SetStates(std::string stat);
      void SetStates(std::vector<std::string> stat);
      void AddStates(std::string stat);
      void AddStates(std::vector<std::string> stat);

      void SetAccepting(std::string stat);
      void SetAccepting(int stat);
      void SetAccepting(std::vector<std::string> stat);
      void SetAccepting(std::vector<int> stat);
      void AddAccepting(std::string stat);
      void AddAccepting(int stat);
      void AddAccepting(std::vector<std::string> stat);
      void AddAccepting(std::vector<int> stat);
    protected:
      int current_state;
      std::string name;
      std::vector<char> language;
      std::vector<int> accepting_states;
      std::vector<std::string> states;
      std::vector<std::array<int, 3>> transitions;
    private:
  };
}
#endif
