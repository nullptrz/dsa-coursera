#include <bits/stdc++.h>

using namespace std;
long long MaxPairwiseProduct(const vector<int> &numbers)
{
    long long result = -1;
    int n = numbers.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            result = max(result, (long long)numbers[i] * numbers[j]);
        }
    }
    return result;
}

long long MaxPairwiseProductFast(const vector<int> &numbers)
{
    int n = numbers.size();
    int index1 = -1;
    for (int i = 1; i < n; ++i)
    {
        if ((index1 == -1) || (numbers[i] > numbers[index1]))
            index1 = i;
    }
    int index2 = -1;
    for (int i = 0; i < n; ++i)
    {
        if ((i != index1) && ((index2 == -1) || (numbers[i] > numbers[index2])))
            index2 = i;
    }

    return (long long)numbers[index1] * numbers[index2];
}

int main()
{
    /*
    while(true) {
        int n = rand() % 10 + 2;
        vector<int> numbers;
        cout << n << "\n";
        for (int i = 0; i < n; ++i) {
            numbers.push_back(rand() % 10);
        }
        for (int i = 0; i < n; ++i) {
            cout << numbers[i] << " ";
        }
        cout << "\n";
        long long res1 = MaxPairwiseProduct(numbers);
        long long res2 = MaxPairwiseProductFast(numbers);
        if (res1 != res2) {
            cout << "Wrong answer: " << res1 << " " << res2 << "\n";
            break;
        } else {
            cout << "OK\n";
        }
    }*/

    int iterations = 100;
    int sequence_length = 100000;
    int number_length = 100000;
    int sum_naive = 0;
    int sum_fast = 0;
    for (int i = 0; i < iterations; ++i)
    {
        int n = rand() % sequence_length + 2;
        vector<int> numbers;
        for (int i = 0; i < n; ++i)
        {
            numbers.push_back(rand() % number_length);
        }
        // Naive Solution

        auto start_naive = chrono::high_resolution_clock::now();
        MaxPairwiseProduct(numbers);
        auto end_naive = chrono::high_resolution_clock::now();
        auto duration_naive = chrono::duration_cast<chrono::nanoseconds>(end_naive - start_naive);
        sum_naive += duration_naive.count();

        auto start_fast = chrono::high_resolution_clock::now();
        MaxPairwiseProductFast(numbers);
        auto end_fast = chrono::high_resolution_clock::now();
        auto duration_fast = chrono::duration_cast<chrono::nanoseconds>(end_fast - start_fast);
        sum_fast = duration_fast.count();
    }

    cout << "Average time for naive solution: " << sum_naive / iterations << " ns\n";
    cout << "Average time for fast solution: " << sum_fast / iterations << " ns\n";

    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> numbers[i];
    }

    cout << MaxPairwiseProductFast(numbers) << "\n";
}