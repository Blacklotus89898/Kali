#include <iostream>
#include <vector>

int main()
{
    std::vector<std::vector<int>> matrix(4, std::vector<int>(4, 0)); // Initialize a 4x4 matrix with zeros
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            int num = 0;
            std::cin >> num;    // Read input for each element
            matrix[i][j] = num; // Assign the input value to the matrix
        }
    }
    int direction = 0; // 0: left, 1: up, 2: right, 3: down
    std::cin >> direction;

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

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            std::cout << matrix[i][j] << " "; // Print the updated matrix
        }
        std::cout << std::endl;
    }
    return 0;
}