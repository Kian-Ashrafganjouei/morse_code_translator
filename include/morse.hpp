#include <map>
#include <string>
#include <vector>

class MorseSolver {
private:
  const static std::map<char, std::string> morseCodeMap;
  static std::vector<std::string> split(const std::string &s,
                                        const char delimiter = ' ');

public:
  static bool isValidMorse(const std::string &morse);
  static bool isValidString(const std::string &string);
  static std::string stringToMorse(const std::string &string);
  static std::string morseToString(const std::string &morse);
};