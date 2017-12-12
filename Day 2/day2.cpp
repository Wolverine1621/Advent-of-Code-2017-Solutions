#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;

// Reads in one row of a spreadsheet (loops until next char is \n)
vector<int> createSpreadsheetRow(ifstream &infile) {
    vector<int> spreadsheetRow;
    int input;

    while (true) {
        infile >> input;

        spreadsheetRow.push_back(input);

        if (infile.peek() == '\n' || infile.peek() == EOF) {
            break;
        }
    }

    return spreadsheetRow;
}

// Finds minimum in a spreadsheet row
int findRowMin(vector<int> &row) {
    int min = INT_MAX;

    for (int i = 0; i < row.size(); i++) {
        if (row.at(i) < min) {
            min = row.at(i);
        }
    }

    return min;
}

// Finds maximum in a spreadsheet row
int findRowMax(vector<int> &row) {
    int max = INT_MIN;

    for (int i = 0; i < row.size(); i++) {
        if (row.at(i) > max) {
            max = row.at(i);
        }
    }

    return max;
}

int calculateDivision(vector<int> &v) {
    int firstValue;
    int secondValue;

    for (int i = 0; i < v.size(); i++) {
      firstValue = v.at(i);
        for (int j = 0; j < v.size(); j++) {
            secondValue = v.at(j);

            if (firstValue < secondValue) {
                if (secondValue % firstValue == 0 && secondValue / firstValue != 1) {
                    return secondValue / firstValue;
                }
            } else if (firstValue > secondValue) {
                if (firstValue % secondValue == 0 && firstValue / secondValue != 1) {
                    return firstValue / secondValue;
                }
            }
        }
    }

    return -1;
}

// Part 1 - sum of evenly divisble numbers in each row
void part1(vector < vector<int> > &spreadsheet) {
  int min, max, checksum;
  checksum = 0;

  // Calculate checksum row by row
  for (int i = 0; i < spreadsheet.size(); i++) {
      min = findRowMin(spreadsheet.at(i));
      max = findRowMax(spreadsheet.at(i));

      checksum += (max - min);
  }

  cout << "Checksum: " << checksum << endl;
}

// Part 2 - sum of evenly divisible numbers in each row
void part2(vector < vector<int> > &spreadsheet) {
  int evenlyDivisibleSum = 0;

  for (int i = 0; i < spreadsheet.size(); i++) {
      evenlyDivisibleSum += calculateDivision(spreadsheet.at(i));
  }

  cout << "Evenly Divisible Sum: " << evenlyDivisibleSum << endl;
}


int main() {
  // Reads in spreadsheet
  vector < vector<int> > spreadsheet;
  ifstream infile("day2input.txt");

  // Populate spreadsheet with rows
  while (!infile.fail()) {
      spreadsheet.push_back(createSpreadsheetRow(infile));
  }

  part1(spreadsheet);
  part2(spreadsheet);
}
