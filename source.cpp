#include <pessum.h>
#include "automata_files/automata_headers.hpp"

using namespace automata;

int main(int argc, const char* argv[]){
  InitAutomata();
  TermAutomata();
  pessum::SaveLog("out.log");
  return(0);
}
