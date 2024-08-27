#include "morse.hpp"
#include <iostream>
#include <sstream>
#include <vector>

const std::map<char, std::string> MorseSolver::morseCodeMap = {
    {'A', ".-"},    {'B', "-..."},  {'C', "-.-."},  {'D', "-.."},
    {'E', "."},     {'F', "..-."},  {'G', "--."},   {'H', "...."},
    {'I', ".."},    {'J', ".---"},  {'K', "-.-"},   {'L', ".-.."},
    {'M', "--"},    {'N', "-."},    {'O', "---"},   {'P', ".--."},
    {'Q', "--.-"},  {'R', ".-."},   {'S', "..."},   {'T', "-"},
    {'U', "..-"},   {'V', "...-"},  {'W', ".--"},   {'X', "-..-"},
    {'Y', "-.--"},  {'Z', "--.."},  {'0', "-----"}, {'1', ".----"},
    {'2', "..---"}, {'3', "...--"}, {'4', "....-"}, {'5', "....."},
    {'6', "-...."}, {'7', "--..."}, {'8', "---.."}, {'9', "----."},
    {' ', " "}};

std::vector<std::string> MorseSolver::split(const std::string &s,
                                            char delimiter) {
  std::vector<std::string> tokens;
  std::string token;
  std::istringstream tokenStream(s);
  while (std::getline(tokenStream, token, delimiter)) {
    if (!token.empty()) {
      tokens.push_back(token);
    }
  }
  return tokens;
}

bool MorseSolver::isValidMorse(const std::string &morse) {
  std::vector<std::string> words = split(morse);
  for (const std::string &word : words) {
    bool isValid = false;
    for (const auto &pair : morseCodeMap) {
      if (word == pair.second) {
        isValid = true;
        break;
      }
    }
    if (!isValid) {
      return false;
    }
  }
  return true;
}

bool MorseSolver::isValidString(const std::string &string) {
  for (const char &c : string) {
    bool isValid = false;
    for (const auto &pair : morseCodeMap) {
      const char &key = pair.first;
      if (key == c) {
        isValid = true;
        break;
      }
    }
    if (!isValid) {
      return false;
    }
  }
  return true;
}

std::string MorseSolver::stringToMorse(const std::string &string) {
  std::ostringstream oss;
  for (const char &c : string) {
    for (const auto &pair : morseCodeMap) {
      const char &key = pair.first;
      if (key == c) {
        oss << pair.second << " ";
        break;
      }
    }
  }
  return oss.str();
}

std::string MorseSolver::morseToString(const std::string &morse) {
  std::ostringstream oss;
  std::vector<std::string> words = split(morse);
  for (const std::string &word : words) {
    for (const auto &pair : morseCodeMap) {
      if (word == pair.second) {
        oss << pair.first << " ";
        break;
      }
    }
  }
  return oss.str();
}