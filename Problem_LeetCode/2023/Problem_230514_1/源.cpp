#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes)
    {
        unordered_map<int, int> map;
        for (int i : barcodes)
        {
            map[i]++;
        }
        sort(barcodes.begin(), barcodes.end(), [&](int a, int b) {return map[a] != map[b] ? map[a] > map[b] : a > b; });
        int n = barcodes.size();
        vector<int> ans; 
        int i = 0;
        for (int j = n / 2 + n % 2; j < n; i++, j++)
        {
            ans.push_back(barcodes[i]);
            ans.push_back(barcodes[j]);
        }
        if (n % 2)
            ans.push_back(barcodes[i]);
        return ans;
    }
};

void test()
{
    Solution s;
    vector<int> barcodes1 = { 1, 1, 1, 2, 2, 2 };
    vector<int> result1 = s.rearrangeBarcodes(barcodes1);
    for (int barcode : result1)
    {
        cout << barcode << " ";
    }
    cout << endl;

    vector<int> barcodes2 = { 1, 1, 1, 1, 2, 2, 3, 3 };
    vector<int> result2 = s.rearrangeBarcodes(barcodes2);
    for (int barcode : result2)
    {
        cout << barcode << " ";
    }
    cout << endl;
}

int main()
{
    test();
    return 0;
}