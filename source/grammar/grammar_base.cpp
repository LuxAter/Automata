#include "grammar/grammar_base.hpp"

#include <set>
#include <string>

#include "grammar/production_rule.hpp"

automata::grammar::Grammar::Grammar() {}

automata::grammar::Grammar::Grammar(const Grammar& clone)
    : terminals_(clone.terminals_),
      non_terminals_(clone.non_terminals_),
      production_rules_(clone.production_rules_) {}

void automata::grammar::Grammar::SetTerminals(std::set<std::string> terminals) {
  terminals_ = terminals;
}
void automata::grammar::Grammar::SetNonTerminals(std::set<std::string> non_terminals) {
  non_terminals_ = non_terminals;
}
void automata::grammar::Grammar::SetProductionRules(std::set<ProductionRule> rules) {
  production_rules_= rules;
}


std::ostream& automata::grammar::Grammar::operator<<(std::ostream& out, const Grammar& lhs);
