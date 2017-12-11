#include <iostream>
#include <fstream>

using namespace std;

int charToInt(char c) {
    return c - '0';
}

int main() {
    ifstream infile;
    string captcha;
    double current, next, first, last, sum;

    infile.open("day1input.txt");
    infile >> captcha;

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

    cout << sum << endl;
}
