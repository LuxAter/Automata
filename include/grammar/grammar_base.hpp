/* Copyright (C) 
 * 2017 - Arden Rasmussen
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 * 
 */

#ifndef AUTOMATA_GRAMMAR_GRAMMAR_BASE_HPP_
#define AUTOMATA_GRAMMAR_GRAMMAR_BASE_HPP_

#include <string>
#include <set>

#include "production_rule.hpp"

namespace automata {
  namespace grammar {
    class Grammar{
      public:
        Grammar();
        Grammar(const Grammar& clone);
        ~Grammar();

        void SetTerminals(std::set<std::string> terminals);
        void SetNonTerminals(std::set<std::string> non_terminals);
        void SetProductionRules(std::set<ProductionRule> rules);
      protected:
        std::set<std::string> terminals_;
        std::set<std::string> non_terminals_;
        std::set<ProductionRule> production_rules_;
      private:
    };

    std::ostream& operator<<(std::ostream& out, const Grammar& lhs);
  } // namespace grammar
} // namespace automata

#endif  // AUTOMATA_GRAMMAR_GRAMMAR_BASE_HPP_
