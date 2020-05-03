/*
 Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
update(3, 2, 2)
sumRegion(2, 1, 4, 3) -> 10
Note:
The matrix is only modifiable by the update function.
You may assume the number of calls to update and sumRegion function is distributed evenly.
You may assume that row1 ≤ row2 and col1 ≤ col2.
 */

// Time : O(k * log(n)) k is query row range , insertion O(n log n)
// Space : O(n)

// Solution 1 : 1D Binary indexed tree

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        this->matrix = matrix;
        rows = matrix.size();
        if (rows == 0) return;
        cols = matrix[0].size();
        if (cols == 0) return;
        n = rows * cols;
        Bitree = vector<int>(n+1, 0);
        BuildBitree(matrix);
    }

    void update(int row, int col, int val) {
        int diff = val - matrix[row][col];
        matrix[row][col] = val;
        int index = getIndex(row,col);
        init(index, diff);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        int index1;
        int index2;
        for(int i=row1; i<=row2;i++) {
            index1 = getIndex(i,col1);
            index2 = getIndex(i,col2);
            sum += getSumRange(index1, index2);
        }
        return sum;
    }
private:
    int getIndex(int i, int j) {
        return i * cols + j;
    }
    void BuildBitree(vector<vector<int>>& matrix) {
        int index;
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                index = getIndex(i,j);
                init(index, matrix[i][j]);
            }
        }
    }

    void init(int index, int value) {
        index++;
        while(index <= n) {
            Bitree[index] += value;
            index = index + (index & -index);
        }
    }

    int getSum(int index) {
        int sum = 0;
        index++;
        while(index > 0) {
            sum += Bitree[index];
            index = index - (index & -index);
        }
        return sum;
    }

    int getSumRange(int i, int j) {
        return getSum(j) - getSum(i-1);
    }

    vector<vector<int>> matrix;
    vector<int> Bitree;
    int rows;
    int cols;
    int n;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */

// Solution 2 : 2D binary indexed tree

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        m_row = matrix.size();
        if (m_row == 0)
            return;
        m_col = matrix[0].size();
        if(m_col == 0)
            return;
        m_matrix = matrix;
        buildBiTree();
    }

    void update(int row, int col, int val) {
        int diff = val - m_matrix[row][col];
        m_matrix[row][col] = val;
        updateBIT(row, col, diff);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return getSum(row2,col2) - getSum(row1-1, col2) - getSum(row2, col1-1) + getSum(row1-1, col1-1);
    }
private:
    void buildBiTree() {
        // Bitree is 1 indexed.
        m_bitree = vector(m_row+1, vector<int>(m_col+1, 0));
        for(int i=0; i<m_row;i++) {
            for(int j=0; j<m_col; j++) {
                updateBIT(i,j, m_matrix[i][j]);
            }
        }
    }
    void updateBIT(int row, int col, int delta) {
        row++;
        col++;
        for(int i=row; i<=m_row; i+=(i&-i)) {
            for(int j=col;j<=m_col;j+=(j&-j)) {
                m_bitree[i][j] += delta;
            }
        }
    }
    int getSum(int row, int col) {
        row++;
        col++;
        int sum = 0;
        for(int i=row; i>0; i-=(i&-i)) {
            for(int j=col; j>0; j-=(j&-j)) {
                sum += m_bitree[i][j];
            }
        }
        return sum;
    }

    vector<vector<int>> m_matrix;
    vector<vector<int>> m_bitree;
    int m_row;
    int m_col;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */
