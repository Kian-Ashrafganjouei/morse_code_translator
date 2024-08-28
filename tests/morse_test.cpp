#include <gtest/gtest.h>
#include "morse.hpp"

TEST(MorseTest, test_stringToMorse) {
  EXPECT_STREQ(".- .- ", MorseSolver::stringToMorse("AA").c_str());
  EXPECT_STREQ(".---- ..--- ...-- ", MorseSolver::stringToMorse("123").c_str());
}

TEST(MorseTest, test_morseToStirng) {
  EXPECT_STREQ("A A ", MorseSolver::morseToString(".- .-").c_str());
  EXPECT_STREQ("1 2 3 ", MorseSolver::morseToString(".---- ..--- ...--").c_str());
}

TEST(MorseTest, test_isValidString) {
  EXPECT_TRUE(MorseSolver::isValidString("ASDASDFDS123"));
  EXPECT_TRUE(MorseSolver::isValidString("HGDJDRT65434"));
  EXPECT_FALSE(MorseSolver::isValidString("HGDJDR5a434"));
  EXPECT_FALSE(MorseSolver::isValidString("HGDbJDR5434"));
}

TEST(MorseTest, test_isValidMorse) {
  EXPECT_TRUE(MorseSolver::isValidMorse(".---- ..--- ...--"));
  EXPECT_TRUE(MorseSolver::isValidMorse(".- .-"));
  EXPECT_FALSE(MorseSolver::isValidMorse(".---- -..--- ...--"));
  EXPECT_FALSE(MorseSolver::isValidMorse("asd"));
}

