#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        int left = 0;
        int right = m * n - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int row = mid / n;
            int col = mid % n;

            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};

void test()
{
    Solution s;
    vector<vector<int>> matrix = { {1,3,5,7},{10,11,16,20},{23,30,34,60} };
    int target = 3;

    bool result = s.searchMatrix(matrix, target);

    if (result)
        cout << "目标值在矩阵中。" << endl;
    else
        cout << "目标值不在矩阵中。" << endl;
}

int main()
{
    test();
    return 0;
}