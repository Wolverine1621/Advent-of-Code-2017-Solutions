#include <iostream>
#include <cmath>

using namespace std;

// Calculates the next smallest odd square, or the closest bottom right corner
int smallerOddSquare(int num) {
    int oddSquare = num;

    while (fmod(sqrt(oddSquare), 1) != 0) {
        oddSquare = oddSquare - 1;
    }

    return oddSquare;
}

int calcRingNum(int num) {
    return ceil(sqrt(num) / 2);
}

int calculateManhattanDist(int x1, int x2, int y1, int y2) {
    return abs(x2 - x1) + abs(y2 - y1);
}

int part1(int input) {
    int oddSquare = smallerOddSquare(input); // Value for this input: 324900
    int ringNum = calcRingNum(oddSquare) + 1;
    int center = (ringNum * 2) / 2;
    int sideLength = sqrt(oddSquare) + 2;

    // Begin calculating an x coordinate for the Manhattan distance
    int xDiff = 0;
    int workingNumber = oddSquare;

    workingNumber += sideLength;
    while (workingNumber < input) { // Loops adding side lengths until the number > input
        workingNumber += sideLength - 1;
    }

    // Calculates an x coordinate based on offset from the nearest corner
    xDiff = workingNumber - input;

    int manhattanDist = calculateManhattanDist(xDiff - 1, center, 1, center);
    return manhattanDist;
}

int main() {
    const int input = 325489;
    // Output is still incorrect for some numbers (ex. 1024)
    cout << part1(input) << endl;
}
