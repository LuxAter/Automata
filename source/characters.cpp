#include "characters.hpp"

#include <map>
#include <string>

bool automata::characters::IsGroupOpen(char ch) {
  if (ch == '(' || ch == '{' || ch == '<' || ch == '[') {
    return true;
  }
  return false;
}

bool automata::characters::IsGroupEnd(char ch) {
  if (ch == ')' || ch == '}' || ch == '>' || ch == ']') {
    return true;
  }
  return false;
}

std::string automata::characters::GetUnicode(std::string ch) {
  std::map<std::string, std::string> character_map;
  character_map["Alpha"] = "\u0391";
  character_map["Beta"] = "\u0392";
  character_map["Gamma"] = "\u0393";
  character_map["Delta"] = "\u0394";
  character_map["Epsilon"] = "\u0395";
  character_map["Zeta"] = "\u0396";
  character_map["Eta"] = "\u0397";
  character_map["Theta"] = "\u0398";
  character_map["Iota"] = "\u0399";
  character_map["Kappa"] = "\u039a";
  character_map["Lambda"] = "\u039b";
  character_map["Mu"] = "\u039c";
  character_map["Nu"] = "\u039d";
  character_map["Xi"] = "\u039e";
  character_map["Omicron"] = "\u039f";
  character_map["Pi"] = "\u03a0";
  character_map["Rhp"] = "\u03a1";
  character_map["Sigma"] = "\u03a3";
  character_map["Tau"] = "\u03a4";
  character_map["Upsilon"] = "\u03a5";
  character_map["Phi"] = "\u03a6";
  character_map["Chi"] = "\u03a7";
  character_map["Psi"] = "\u03a8";
  character_map["Omega"] = "\u03a9";
  character_map["alpha"] = "\u03b1";
  character_map["beta"] = "\u03b2";
  character_map["gamma"] = "\u03b3";
  character_map["delta"] = "\u03b4";
  character_map["epsilon"] = "\u03b5";
  character_map["zeta"] = "\u03b6";
  character_map["eta"] = "\u03b7";
  character_map["theta"] = "\u03b8";
  character_map["iota"] = "\u03b9";
  character_map["kappa"] = "\u03ba";
  character_map["lambda"] = "\u03bb";
  character_map["mu"] = "\u03bc";
  character_map["nu"] = "\u03bd";
  character_map["xi"] = "\u03be";
  character_map["omicron"] = "\u03bf";
  character_map["pi"] = "\u03c0";
  character_map["rhp"] = "\u03c1";
  character_map["sigma"] = "\u03c3";
  character_map["tau"] = "\u03c4";
  character_map["upsilon"] = "\u03c5";
  character_map["phi"] = "\u03c6";
  character_map["chi"] = "\u03c7";
  character_map["psi"] = "\u03c8";
  character_map["omega"] = "\u03c9";
  std::map<std::string, std::string>::iterator ret = character_map.find(ch);
  if (ret != character_map.end()){
    ch = (*ret).second;
  }
  return ch;
}
