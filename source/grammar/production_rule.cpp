#include "grammar/production_rule.hpp"

#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

#include "characters.hpp"

automata::grammar::ProductionRule::ProductionRule() {}

automata::grammar::ProductionRule::ProductionRule(const ProductionRule& clone)
    : head_(clone.head_),
      tail_(clone.tail_),
      result_(clone.result_),
      body_(clone.body_) {}

automata::grammar::ProductionRule::ProductionRule(
    std::vector<std::string> head, std::string body,
    std::vector<std::string> tail, std::vector<std::string> result)
  : head_(head), tail_(tail), result_(result), body_(body) {
    Format();
  }

automata::grammar::ProductionRule::ProductionRule(std::string string_repr) {
  ParseString(string_repr);
}

void automata::grammar::ProductionRule::ParseString(std::string string_repr) {
  std::string input, output;
  std::size_t position = string_repr.find("->");
  if (position != std::string::npos) {
    input = string_repr.substr(0, position);
    output = string_repr.substr(position + 2, string_repr.size());
  } else {
    position = string_repr.find("\u2192");
    if (position != std::string::npos) {
      input = string_repr.substr(0, position);
      output = string_repr.substr(position + 4, string_repr.size());
    }
  }
  std::string head, tail, body;
  unsigned int read_state = 0;
  for (std::string::iterator ch = input.begin();
       ch != input.end() && read_state != 4; ++ch) {
    if (characters::IsGroupOpen(*ch) == true) {
      if (read_state == 0) {
        read_state = 1;
      } else if (read_state == 2) {
        read_state = 3;
      }
    } else if (characters::IsGroupEnd(*ch) == true) {
      if (read_state == 1) {
        read_state = 2;
      } else if (read_state == 3) {
        read_state = 4;
      }
    } else {
      if (read_state == 1) {
        head += *ch;
      } else if (read_state == 2) {
        body += *ch;
      } else if (read_state == 3) {
        tail += *ch;
      } else if(read_state == 0){
        body += *ch;
        read_state = 2;
      }
    }
  }
  std::istringstream head_stream(head);
  head_ =
      std::vector<std::string>{std::istream_iterator<std::string>{head_stream},
                               std::istream_iterator<std::string>{}};
  std::istringstream tail_stream(tail);
  tail_ =
      std::vector<std::string>{std::istream_iterator<std::string>{tail_stream},
                               std::istream_iterator<std::string>{}};
  std::istringstream result_stream(output);
  result_ = std::vector<std::string>{
      std::istream_iterator<std::string>{result_stream},
      std::istream_iterator<std::string>{}};
  body_ = body;
  Format();
}

void automata::grammar::ProductionRule::SetHead(std::vector<std::string> head) {
  head_ = head;
}
void automata::grammar::ProductionRule::SetHead() {
  head_ = std::vector<std::string>();
}
void automata::grammar::ProductionRule::SetBody(std::string body) {
  body_ = body;
}
void automata::grammar::ProductionRule::SetBody() { body_ = std::string(); }
void automata::grammar::ProductionRule::SetTail(std::vector<std::string> tail) {
  tail_ = tail;
}
void automata::grammar::ProductionRule::SetTail() {
  tail_ = std::vector<std::string>();
}
void automata::grammar::ProductionRule::SetResult(
    std::vector<std::string> result) {
  result_ = result;
}
void automata::grammar::ProductionRule::SetResult() {
  result_ = std::vector<std::string>();
}

std::string automata::grammar::ProductionRule::StringRepr() const {
  std::string repr;
  for (std::vector<std::string>::const_iterator it = head_.begin();
       it != head_.end(); ++it) {
    repr += (*it);
  }
  if (body_ != std::string()) {
    repr += body_;
  } else {
    repr += "\u039B";
  }
  for (std::vector<std::string>::const_iterator it = tail_.begin();
       it != tail_.end(); ++it) {
    repr += (*it);
  }
  repr += "\u2192";
  for (std::vector<std::string>::const_iterator it = result_.begin();
       it != result_.end(); ++it) {
    repr += (*it);
  }
  if (result_.size() == 0) {
    repr += "\u039B";
  }
  return repr;
}

std::vector<std::string> automata::grammar::ProductionRule::VecRepr() const {
  std::vector<std::string> repr;
  repr.reserve(head_.size() + tail_.size() + result_.size());
  repr.insert(repr.end(), head_.begin(), head_.end());
  repr.insert(repr.end(), tail_.begin(), tail_.end());
  repr.insert(repr.end(), result_.begin(), result_.end());
  repr.push_back(body_);
  return repr;
}

void automata::grammar::ProductionRule::Format() {
  for (std::vector<std::string>::iterator it = head_.begin(); it != head_.end();
       ++it) {
    if ((*it).find('/') == 0) {
      (*it).erase((*it).begin());
      *it = characters::GetUnicode(*it);
    }
  }
  for (std::vector<std::string>::iterator it = tail_.begin(); it != tail_.end();
       ++it) {
    if ((*it).find('/') == 0) {
      (*it).erase((*it).begin());
      *it = characters::GetUnicode(*it);
    }
  }
  for (std::vector<std::string>::iterator it = result_.begin();
       it != result_.end(); ++it) {
    if ((*it).find('/') == 0) {
      (*it).erase((*it).begin());
      *it = characters::GetUnicode(*it);
    }
  }
  if (body_.find('/') == 0) {
    body_.erase(body_.begin());
    body_ = characters::GetUnicode(body_);
  }
}

std::ostream& automata::grammar::operator<<(std::ostream& out,
                                            const ProductionRule& rhs) {
  out << rhs.StringRepr();
  return out;
}

bool automata::grammar::operator==(const ProductionRule& lhs,
                                   const ProductionRule& rhs) {
  return lhs.VecRepr() == rhs.VecRepr();
}
bool automata::grammar::operator!=(const ProductionRule& lhs,
                                   const ProductionRule& rhs) {
  return lhs.VecRepr() != rhs.VecRepr();
}
bool automata::grammar::operator<(const ProductionRule& lhs,
                                  const ProductionRule& rhs) {
  return lhs.VecRepr() < rhs.VecRepr();
}
bool automata::grammar::operator>(const ProductionRule& lhs,
                                  const ProductionRule& rhs) {
  return lhs.VecRepr() > rhs.VecRepr();
}
bool automata::grammar::operator<=(const ProductionRule& lhs,
                                   const ProductionRule& rhs) {
  return lhs.VecRepr() <= rhs.VecRepr();
}
bool automata::grammar::operator>=(const ProductionRule& lhs,
                                   const ProductionRule& rhs) {
  return lhs.VecRepr() >= rhs.VecRepr();
}
