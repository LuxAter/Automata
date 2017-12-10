#include <iostream>
#include <set>
#include "characters.hpp"
#include "grammar/production_rule.hpp"

using namespace automata;
using namespace automata::grammar;

int main(int argc, char const* argv[]) {
  std::set<ProductionRule> rules;
  rules.insert(ProductionRule({}, "S", {}, {"a", "S"}));
  rules.insert(ProductionRule("/alpha->/beta"));
  rules.insert(ProductionRule({}, "A", {}, {"c", "A"}));
  rules.insert(ProductionRule({}, "A", {}, {}));
  for (auto& str : rules) std::cout << str << std::endl;
  return 0;
}
