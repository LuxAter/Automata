#include "automata.hpp"
#include <pessum.h>

void automata::InitAutomata() {
  pessum::Log(pessum::INFO, "Automata Version: %i.%i.%i",
              "automata::InitAutomata", AUTOMATA_VERSION_MAJOR,
              AUTOMATA_VERSION_MINOR, AUTOMATA_VERSION_PATCH);
}

void automata::TermAutomata() {}

void automata::GetVersion(int& major, int& minor, int& patch) {
  major = AUTOMATA_VERSION_MAJOR;
  minor = AUTOMATA_VERSION_MINOR;
  patch = AUTOMATA_VERSION_PATCH;
}
