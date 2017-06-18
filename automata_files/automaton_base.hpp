#ifndef AUTOMATA_AUTOMATON_BASE_HPP
#define AUTOMATA_AUTOMATON_BASE_HPP
#include <array>
#include <string>
#include <vector>
namespace automata {
  class Automaton {
   public:
    Automaton();
    Automaton(const Automaton& copy);
    ~Automaton();

    void SetName(std::string in_name);

    void SetStartState(std::string stat);
    void SetStartState(int stat);

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

    bool IsAccept(int stat);

    void SetTransitions(std::vector<std::array<int, 3>> trans);
    void AddTransitions(std::array<int, 3> trans);
    void AddTransitions(std::string state_a, char ch, std::string state_b);

    std::vector<std::array<int, 3>> GetTransitions(std::array<int, 2> match);

    int State(std::string stat);
    int Language(char ch);

    void SaveAutomaton(std::string file);
    void LoadAutomaton(std::string file);

    virtual int Type();

   protected:
    int start_state;
    std::string name;
    std::vector<char> language;
    std::vector<int> accepting_states;
    std::vector<std::string> states;
    std::vector<std::array<int, 3>> transitions;

   private:
  };
}
#endif
