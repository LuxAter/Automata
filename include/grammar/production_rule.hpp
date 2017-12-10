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

#ifndef AUTOMATA_GRAMMAR_PRODUCTION_RULE_HPP_
#define AUTOMATA_GRAMMAR_PRODUCTION_RULE_HPP_

#include <string>
#include <vector>

namespace automata {
  namespace grammar {
    class ProductionRule {
     public:
      ProductionRule();
      ProductionRule(const ProductionRule& clone);
      ProductionRule(std::vector<std::string> head, std::string body,
                     std::vector<std::string> tail,
                     std::vector<std::string> result);
      ProductionRule(std::string string_repr);

      void ParseString(std::string string_repr);

      void SetHead(std::vector<std::string> head);
      void SetHead();
      void SetBody(std::string body);
      void SetBody();
      void SetTail(std::vector<std::string> tail);
      void SetTail();
      void SetResult(std::vector<std::string> result);
      void SetResult();

      std::string StringRepr() const;
      std::vector<std::string> VecRepr() const;

      void Format();

     protected:
     private:
      std::vector<std::string> head_, tail_, result_;
      std::string body_;
    };

    std::ostream& operator<<(std::ostream& out, const ProductionRule& rhs);
    bool operator==(const ProductionRule& lhs, const ProductionRule& rhs);
    bool operator!=(const ProductionRule& lhs, const ProductionRule& rhs);
    bool operator<(const ProductionRule& lhs, const ProductionRule& rhs);
    bool operator>(const ProductionRule& lhs, const ProductionRule& rhs);
    bool operator<=(const ProductionRule& lhs, const ProductionRule& rhs);
    bool operator>=(const ProductionRule& lhs, const ProductionRule& rhs);
  }  // namespace grammar
}  // namespace automata

#endif  // AUTOMATA_GRAMMAR_PRODUCTION_RULE_HPP_
