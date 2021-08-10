// Sudoku Solver

#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <ctime>
#include <cmath>

using namespace std;


// overloaded operator to display grid
ostream& operator<<(ostream& os, const array<array<int, 9>, 9>& puzzleGrid) {
    for(int r{0}; r < 9; r++) {
        os << ' ';
        for(int c{0}; c < 9; c++) {
            if(puzzleGrid[r][c] != 0)
                os << puzzleGrid[r][c] << ' ';
            else
                os << "  ";
            if(c % 3 == 2 && c < 8)
                os << "| ";
        }
        os << '\n';
        if(r % 3 == 2 && r < 8)
            os << string(23, '-') << '\n';
    }
    return os;
}


class Sudoku {

    // private method to identify seen numbers given grid position
    void seenNumbers(array<bool, 10>& vu, int row, int col) {
        for(int i{0}; i < 9; i++) {
            vu[grid[i][col]] = true;
            vu[grid[row][i]] = true;
        }
        for(int r{(row / 3) * 3}; r < ((row / 3) * 3 + 3); r++) {
            for(int c{(col / 3) * 3}; c < ((col / 3) * 3 + 3); c++)
                vu[grid[r][c]] = true;
        }
    }


public:
    unsigned int solutionCount{0};  // total number of solutions
    array<array<int, 9>, 9> grid;  // puzzle grid

    
    // constructor: open file and import into grid (2D array)
    Sudoku(string fileName) {
        ifstream inputFile(fileName);
        if(inputFile.fail()) {
            cout << "File does not exist. Exiting...\n";
            exit(0);
        }

        string inputRow;
        int inputVal;
        
        for(int i{0}; i < 9; i++) {
            inputFile >> inputRow;
            if(inputFile.good()) {
                for(int j{0}; j < 9; j++) {
                    inputVal = inputRow[j] - '0';
                    if(inputVal < 0 || inputVal > 9)
                        continue;
                    grid[i][j] = inputVal;
                }
            }
        }

        inputFile.close();
    }

    
    // recursive backtrack to find solutions
    void solve(int startRow=0, int startCol=0) {
        array<bool, 10> seen;  // denotes whether each number has been seen (is invalid) at given position

        for(int r{startRow}; r < 9; r++) {
            for(int c{startCol}; c < 9; c++) {
                if(grid[r][c] == 0) {

                    seen.fill(false);
                    seenNumbers(seen, r, c);  // find all invalid numbers

                    for(int potential{1}; potential < 10; potential++) {
                        if(!seen[potential]) {  // if false, potential has not been seen, is valid
                            grid[r][c] = potential;
                            solve(r, c);  // continue solve
                            grid[r][c] = 0;  // backtrack
                        }
                    }
                    return;
                }

            }

            if(r == startRow)
                startCol = 0;
        }

        cout << "\n———Possible Solution———\n" << grid;  // print possible solution
        solutionCount++;
    }
};


int main() {
    clock_t start, stop;

    // new puzzle grid
    Sudoku newGrid("grid.txt");
    cout << "————Original Sudoku————\n" << newGrid.grid;

    // solve sudoku, timed
    start = clock();
    newGrid.solve();
    stop = clock();

    cout << "\nNumber of Solutions: " << newGrid.solutionCount
         << "\nSeconds Elapsed: " << round(((stop - start) / static_cast<double>(CLOCKS_PER_SEC)) * 1000000.0) / 1000000.0
         << endl;

    return 0;
}
