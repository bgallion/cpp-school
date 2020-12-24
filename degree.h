#pragma once
#include <string>

// Requirement C.
// Underlying values of enum are int. {0,1,2}
enum DegreeProgram { SECURITY, NETWORK, SOFTWARE };

// Array to convert enum values to their representative string
static const std::string degreeProgramStrings[] = { "SECURITY", "NETWORK", "SOFTWARE" };
