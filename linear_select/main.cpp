#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include "select.hpp"

using namespace std;

int main() {
    /*if (argc != 2) {
        cerr << "Usage: ./program <input file>" << endl;
        return EXIT_FAILURE;
    }*/

    int n, i;
    vector<int> arr1;
    vector<int> arr2;
    double result1, result2;
    ifstream input("C:\\Users\\kyi88\\source\\repos\\21algo_hw1\\test_case\\6t1.in");

    // Read input.
    if (input.is_open()) {
        int a;
        input >> n >> i;
        for (int idx = 0; idx < n; ++idx) {
            input >> a;
            arr1.push_back(a);
            arr2.push_back(a);
        }
        input.close();
    }
    else {
        cerr << "Failed to read input." << endl;
        return EXIT_FAILURE;
    }
    // Select i-th element (randomized select).
    clock_t x_start = clock();
    int x = randomized_select(arr1, 0, n-1, i);
    clock_t x_finish = clock();
    result1 = ((double)x_finish - (double)x_start);
    // Select i-th element (deterministic select).
    clock_t y_start = clock();
    int y = linear_select(arr2, 0, n-1, i);
    clock_t y_finish = clock();
    result2 = ((double)y_finish - (double)y_start);

    // Check correctness.
    bool x_correct = check(arr1, i, x);
    bool y_correct = check(arr2, i, y);

    cout << "randomized select    : " << x << " ("
        << (x_correct ? "CORRECT" : "WRONG") << ") (elapsed time: "
        << result1 / CLOCKS_PER_SEC << " sec)"
        << endl;
    cout << "deterministic select : " << y << " ("
        << (y_correct ? "CORRECT" : "WRONG") << ") (elapsed time: "
        << result2 / CLOCKS_PER_SEC << " sec)"
        << endl;

    return EXIT_SUCCESS;
}
