#pragma once
#include <string>

// Requirement C.
// Words in enum type are really placeholders for ints
enum DegreeProgram { SECURITY, NETWORK, SOFTWARE };

// Array to convert enum values to their representative string
static const std::string degreeProgramStrings[] = { "SECURITY", "NETWORK", "SOFTWARE" };
