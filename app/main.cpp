#include <iostream>
#include <limits>
#include <string>

#include "morse.hpp"

int main() {
  std::string input;
  int choice;

  while (true) {
    std::cout << "Choose an option:\n"
              << "1. Convert String to Morse code\n"
              << "2. Convert Morse code to String\n"
              << "3. Quit\n"
              << "Enter your choice (1, 2, or 3): ";

    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (choice == 3) {
      std::cout << "Exiting the program. Goodbye!" << std::endl;
      break;
    }

    if (choice != 1 && choice != 2) {
      std::cout << "Invalid choice. Please enter 1, 2, or 3." << std::endl;
      continue;
    }

    std::cout << "Enter a line of text (or type 'quit' to exit): ";

    std::getline(std::cin, input);

    if (input == "quit" || input == "QUIT") {
      std::cout << "Exiting the program. Goodbye!" << std::endl;
      break;
    }

    std::cout << "You entered: " << input << std::endl;

    if (choice == 1) {
      std::cout << "Converting String to Morse!" << std::endl;
      if (MorseSolver::isValidString(input)) {
        std::cout << input << " is a valid String" << std::endl;
        std::cout << "Morse Code: " << MorseSolver::stringToMorse(input)
                  << std::endl;
      } else {
        std::cout << input << " is not a valid String" << std::endl;
      }
    } else {
      std::cout << "Converting Morse to String!" << std::endl;
      if (MorseSolver::isValidMorse(input)) {
        std::cout << input << " is a valid Morse" << std::endl;
        std::cout << "String: " << MorseSolver::morseToString(input)
                  << std::endl;
      } else {
        std::cout << input << " is not a valid Morse" << std::endl;
      }
    }

    std::cout << std::endl;
  }

  return 0;
}
