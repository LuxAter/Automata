#ifndef AUTOMATA_DFA_HPP
#define AUTOMATA_DFA_HPP
#include <vector>
#include <array>
#include <string>
namespace automata{
  class dfa{
    public:
     dfa();
     ~dfa();
    void SetName(std::string in_name);
    void SetLanguage(std::vector<char> in_language);
    void SetLanguage(std::string in_language);
    void AddToLanguage(char ch);
    void
    private:
     std::string name;
     std::vector<char> language;
     std::vector<std::string> states;
     std::vector<std::array<int 3>> transitions;
  };
}
#endif
