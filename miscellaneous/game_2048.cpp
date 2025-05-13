#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <conio.h> // For _getch(), direct console input

// Function declarations
int generateRandomPowerOf2();
std::vector<std::vector<int>> generateMatrix();
void printMatrix(const std::vector<std::vector<int>> &matrix);
bool checkGameOver(const std::vector<std::vector<int>> &matrix);
void addNewPowerOf2(std::vector<std::vector<int>> &matrix);
void makeMove(std::vector<std::vector<int>> &matrix, int direction);
void parseInput(int &direction);

int main()
{


    // Seed the random number generator
    srand(static_cast<unsigned>(time(0)));

    // Generate the matrix
    std::vector<std::vector<int>> matrix = generateMatrix();
    printMatrix(matrix); // Print the updated matrix





    int direction = -1; // 0: left, 1: up, 2: right, 3: down
    while(true) {
        parseInput(direction); // Get the direction input from the user

        makeMove(matrix, direction); // Move the tiles in the specified direction
        // printMatrix(matrix); // Print the updated matrix

        if (checkGameOver(matrix)) {
            std::cout << "Game Over!" << std::endl; // Check if the game is over
            return 0;
        }  // Check if the game is over

        addNewPowerOf2(matrix); // Add a new power of 2 to the matrix
        printMatrix(matrix); // Print the updated matrix
    }


    return 0;
}


void parseInput(int &direction) {
    while (true) {
        std::cout << "Enter direction (Arrow keys or h/j/k/l): ";
        char input = _getch(); // Get a single character input without pressing Enter

        if (input == -32) { // Arrow keys are preceded by -32
            input = _getch(); // Get the actual arrow key code
            switch (input) {
                case 75: direction = 0; return; // Left arrow
                case 80: direction = 3; return; // Down arrow
                case 72: direction = 1; return; // Up arrow
                case 77: direction = 2; return; // Right arrow
                default:
                    std::cout << "\nInvalid input. Use arrow keys or h/j/k/l." << std::endl;
            }
        } else {
            switch (input) {
                case 'h': case 'a': direction = 0; return; // Left
                case 'j': case 's': direction = 3; return; // Down
                case 'k': case 'w': direction = 1; return; // Up
                case 'l': case 'd': direction = 2; return; // Right
                case 'q': case 'Q': exit(0); // Quit the game
                default:
                    std::cout << "\nInvalid input. Use arrow keys or h/j/k/l." << std::endl;
            }
        }
    }
}

// get max score
int getMaxScore(const std::vector<std::vector<int>> &matrix) {
    int maxScore = 0;
    for (const auto &row : matrix) {
        for (int num : row) {
            if (num > maxScore) {
                maxScore = num;
            }
        }
    }
    return maxScore;
}

// Function to generate a random power of 2
int generateRandomPowerOf2()
{
    int exponent = rand() % 4; // Random exponent between 0 and 10 (2^0 to 2^10)

    return 1 << exponent + 1;       // Equivalent to 2^exponent
}

// Function to generate a 4x4 matrix with values that are powers of 2
std::vector<std::vector<int>> generateMatrix()
{
    std::vector<std::vector<int>> matrix(4, std::vector<int>(4, 0));
    // Add two random powers of 2 to start the game
    addNewPowerOf2(matrix);
    addNewPowerOf2(matrix);
    return matrix;
}

void printMatrix(const std::vector<std::vector<int>> &matrix) {
    std::cout << "\n\n\n#######################" << std::endl;
    std::cout << "Matrix Status:" << std::endl;
    for (const auto &row : matrix) {
        for (int num : row) {
            std::cout << num << "\t"; // Use tab for better alignment
        }
        std::cout << std::endl;
    }
}

bool checkGameOver(const std::vector<std::vector<int>> &matrix)
{
    // Check if the game is over (no valid moves left)
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (matrix[i][j] == 0)
            {
                return false; // Empty cell found, game is not over
            }
            if (i < 3 && matrix[i][j] == matrix[i + 1][j])
            {
                return false; // Adjacent cells in the same column are equal
            }
            if (j < 3 && matrix[i][j] == matrix[i][j + 1])
            {
                return false; // Adjacent cells in the same row are equal
            }
        }
    }
    return true; // No valid moves left, game is over
}

void addNewPowerOf2(std::vector<std::vector<int>> &matrix)
{
    std::vector<std::pair<int, int>> emptyCells;

    // Find all empty cells
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (matrix[i][j] == 0)
            {
                emptyCells.emplace_back(i, j);
            }
        }
    }

    // If there are no empty cells, do nothing
    if (emptyCells.empty())
    {
        return;
    }

    // Choose a random empty cell
    int randomIndex = rand() % emptyCells.size();
    int row = emptyCells[randomIndex].first;
    int col = emptyCells[randomIndex].second;

    // Add a new power of 2 (2 or 4) to the chosen cell
    matrix[row][col] =  generateRandomPowerOf2();
}

void makeMove(std::vector<std::vector<int>> &matrix, int direction)
{
    // Implement the logic to move the tiles in the specified direction
    // (left, right, up, down) and merge them accordingly.
    // This function should modify the matrix in place.
    // You can use the existing code for moving tiles as a reference.

    if (direction == 0) // Left
    {
        for (int i = 0; i < 4; ++i)
        {
            std::vector<int> newRow(4, 0);
            int pos = 0;
            bool merged = false;
            for (int j = 0; j < 4; ++j)
            {
                if (matrix[i][j] != 0)
                {
                    if (pos > 0 && newRow[pos - 1] == matrix[i][j] && !merged)
                    {
                        newRow[pos - 1] *= 2;
                        merged = true;
                    }
                    else
                    {
                        newRow[pos] = matrix[i][j];
                        pos++;
                        merged = false;
                    }
                }
            }
            matrix[i] = newRow;
        }
    }
    else if (direction == 1) // Up
    {
        for (int j = 0; j < 4; ++j)
        {
            std::vector<int> newCol(4, 0);
            int pos = 0;
            bool merged = false;
            for (int i = 0; i < 4; ++i)
            {
                if (matrix[i][j] != 0)
                {
                    if (pos > 0 && newCol[pos - 1] == matrix[i][j] && !merged)
                    {
                        newCol[pos - 1] *= 2;
                        merged = true;
                    }
                    else
                    {
                        newCol[pos] = matrix[i][j];
                        pos++;
                        merged = false;
                    }
                }
            }
            for (int i = 0; i < 4; ++i)
            {
                matrix[i][j] = newCol[i];
            }
        }
    }
    else if (direction == 2) // Right
    {
        for (int i = 0; i < 4; ++i)
        {
            std::vector<int> newRow(4, 0);
            int pos = 3;
            bool merged = false;
            for (int j = 3; j >= 0; --j)
            {
                if (matrix[i][j] != 0)
                {
                    if (pos < 3 && newRow[pos + 1] == matrix[i][j] && !merged)
                    {
                        newRow[pos + 1] *= 2;
                        merged = true;
                    }
                    else
                    {
                        newRow[pos] = matrix[i][j];
                        pos--;
                        merged = false;
                    }
                }
            }
            matrix[i] = newRow;
        }
    }
    else if (direction == 3) // Down
    {
        for (int j = 0; j < 4; ++j)
        {
            std::vector<int> newCol(4, 0);
            int pos = 3;
            bool merged = false;
            for (int i = 3; i >= 0; --i)
            {
                if (matrix[i][j] != 0)
                {
                    if (pos < 3 && newCol[pos + 1] == matrix[i][j] &&
                        !merged)
                    {
                        newCol[pos + 1] *= 2;
                        merged = true;
                    }
                    else
                    {
                        newCol[pos] = matrix[i][j];
                        pos--;
                        merged = false;
                    }
                }
            }
            for (int i = 0; i < 4; ++i)
            {
                matrix[i][j] = newCol[i];
            }
        }
    }

}