#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <utility> // std::pair, make_pair

using namespace std;

// Reads passphrases into a vector from an ifstream
vector<string> readInPassphrases(ifstream &infile) {
  vector<string> passphrases;
  string currentPassphrase;

  while (true) {
      getline(infile, currentPassphrase);
      passphrases.push_back(currentPassphrase);

      if (infile.peek() == EOF) {
          break;
      }
  }

  return passphrases;
}

// Splits a single passphrase into a single vector delimited by spaces
vector<string> splitString(string s) {
  istringstream i(s);
  string word;
  vector<string> result;

  while (i.peek() != EOF) {
    i >> word;
    result.push_back(word);
  }

  return result;
}

// Determines if a passphrase is valid
bool validPassphrase(vector<string> words) {
    string currentWord;
    bool valid = true;

    while(!words.empty()) { // Checks each word in words against the others for equality
        currentWord = words[0];

        words.erase(words.begin());

        for (int i = 0; i < words.size(); i++) {
            if (currentWord == words[i]) {
                valid = false;
                break;
            }
        }

        if (!valid) {
            break;
        }
    }

    return valid;
}

// Determines if two strings are anagrams
bool areAnagrams(string s1, string s2) {
    if (s1.size() != s2.size()) {
        return false;
    }

    char currentChar;
    while (!s1.empty()) { // Loop gradually removes matching characters until proven anagram/not anagram
        currentChar = s1.at(0);

        s1.erase(s1.begin());
        if (s2.find(currentChar) == s2.npos) {
            return false;
        }
        s2.erase(s2.begin() + s2.find(currentChar));
    }

    if (s1.size() > 0 || s2.size() > 0) {
        return false;
    }

    return true;
}

bool validWithAnagrams(vector<string> words) { // Almost identical to validPassphrase
    string currentWord;
    bool valid = true;

    while(!words.empty()) {
        currentWord = words[0];

        words.erase(words.begin());

        for (int i = 0; i < words.size(); i++) {
            if (areAnagrams(currentWord, words[i])) {
                valid = false;
                break;
            }
        }

        if (!valid) {
            break;
        }
    }

    return valid;
}

// Part 1
void part1And2() {
  // Read in passphrases to vector
  vector<string> passphrases;
  ifstream infile("day4input.txt");
  passphrases = readInPassphrases(infile);
  int part1Count = 0;
  int part2Count = 0;

  // Splits each passphrase into a vector of words and determines its validity
  for (int i = 0; i < passphrases.size(); i++) {
      vector<string> wordsInPassphrase = splitString(passphrases[i]);

      if (validPassphrase(wordsInPassphrase)) {
          part1Count++;
      }

      if (validPassphrase(wordsInPassphrase) && validWithAnagrams(wordsInPassphrase)) {
          part2Count++;
      }
  }

  cout << part1Count << endl;
  cout << part2Count << endl;
}


int main() {
  part1And2();
}
