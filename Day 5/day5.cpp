#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Reads instructions into a vector
vector<int> readInValues(ifstream &infile) {
    vector<int> result;
    int currentValue;

    infile >> currentValue;
    while (!infile.fail()) {
        result.push_back(currentValue);

        infile >> currentValue;
    }

    return result;
}

int part1And2() {
    ifstream infile("day5input.txt");
    vector<int> instructions = readInValues(infile);

    bool boundsExceeded = false;
    int currentIndex = 0;
    int temp;
    int count = 0;

    // Loops and changes currentIndex according to instructions until out of bounds
    while (!boundsExceeded) {
        if (currentIndex > instructions.size() - 1 || currentIndex < 0) {
            break;
        }

        temp = currentIndex;
        currentIndex += instructions.at(currentIndex);

        // Part 1 instruction: instructions[temp] = instructions[temp] + 1;
        if (instructions[temp] >= 3) {
            instructions[temp] = instructions[temp] - 1;
        } else {
            instructions[temp] += 1;
        }

        count++;
    }

    return count;
}

int main() {
    cout << part1And2() << endl;
}
