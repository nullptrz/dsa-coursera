#include <bits/stdc++.h>

using namespace std;
long long MaxPairwiseProduct(const vector<int>& numbers) {
    long long result = -1;
    int n = numbers.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            result = max(result, (long long)numbers[i] * numbers[j]);
        }
    }
    return result;
}

long long MaxPairwiseProductFast(const vector<int>& numbers) {
    int n = numbers.size();
    int index1 = -1;
    for (int i = 1; i < n; ++i) {
        if ((index1 == -1) || (numbers[i] > numbers[index1])) index1 = i;
    }
    int index2 = -1;
    for (int i = 0; i < n; ++i) {
        if ((i != index1) && ((index2 == -1) ||  (numbers[i] > numbers[index2]))) index2 = i;
    }

    return (long long)numbers[index1] * numbers[index2];
}

int main(){
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
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }
    cout << MaxPairwiseProductFast(numbers) << "\n";
}