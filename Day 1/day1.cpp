#include <iostream>
#include <fstream>

using namespace std;

// Converts char to int based on offset from '0' in ASCII table
int charToInt(char c) {
    return c - '0';
}

// Code for part 1
double part1 (string captcha) {
  double current, next, first, last, sum;

  // Loops from first to end
  for (int i = 0; i < captcha.length() - 1; i++) {
      current = charToInt(captcha.at(i));
      next = charToInt(captcha.at(i + 1));

      if (current == next) {
          sum += (current);
      }
  }

  // Handles "circular" summing
  first = charToInt(captcha.at(0));
  last = charToInt(captcha.at(captcha.length() - 1));

  if (first == last) {
      sum += (first);
  }

  return sum;
}

// Code for part 2
double part2 (string captcha) {
    double current, next, first, last, sum, nextIndex;

    double captchaSize = captcha.length();
    double halfway = captchaSize / 2;

    // Loops from first to end
    for (int i = 0; i < captchaSize; i++) {
      current = charToInt(captcha.at(i));

      // Calculate "circular halfway" index and check if it's out of bounds
      nextIndex = i + halfway;
      if (nextIndex > (captchaSize - 1)) { // If out of bounds, wrap circularly
          nextIndex = nextIndex - captchaSize;
      }

      next = charToInt(captcha.at(nextIndex));

      if (current == next) {
          sum += current;
      }
    }

    return sum;
}

int main() {
    ifstream infile;
    string captcha;

    infile.open("day1input.txt");
    infile >> captcha;

    cout << part1(captcha) << endl;
    cout << part2(captcha) << endl;
}
