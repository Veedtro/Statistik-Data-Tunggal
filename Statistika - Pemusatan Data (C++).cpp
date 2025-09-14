#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
using namespace std;

// Fungsi untuk menghitung mean
double mean(const vector<double>& data) {
    double sum = 0;
    for (double x : data) sum += x;
    return sum / data.size();
}

// Fungsi untuk menghitung median
double median(vector<double> data) {
    sort(data.begin(), data.end());
    int n = data.size();
    if (n % 2 == 1) return data[n / 2];
    else return (data[n / 2 - 1] + data[n / 2]) / 2.0;
}

// Fungsi untuk menghitung modus (bisa lebih dari 1)
vector<double> modus(const vector<double>& data) {
    map<double, int> freq;
    for (double x : data) freq[x]++;
    
    int maxFreq = 0;
    for (auto& p : freq) {
        if (p.second > maxFreq) maxFreq = p.second;
    }

    vector<double> result;
    for (auto& p : freq) {
        if (p.second == maxFreq && maxFreq > 1) result.push_back(p.first);
    }
    
    // Kalau semua frekuensinya 1 (tidak ada modus)
    if (result.empty()) result.push_back(-9999); 
    return result;
}

// Fungsi untuk menghitung kuartil
double quartile(vector<double> data, double q) {
    sort(data.begin(), data.end());
    double pos = q * (data.size() + 1);
    int idx = (int)pos - 1;
    double frac = pos - (int)pos;

    if (idx < 0) return data[0];
    if (idx >= data.size() - 1) return data.back();
    return data[idx] + frac * (data[idx + 1] - data[idx]);
}

int main() {
    cout << "Input Data\nMasukan data (pisahkan dengan koma): ";
    string input;
    getline(cin, input);

    // Parsing input
    vector<double> data;
    stringstream ss(input);
    string temp;
    while (getline(ss, temp, ',')) {
        data.push_back(stod(temp));
    }

    // Urutkan data
    sort(data.begin(), data.end());

    cout << "\nHasil :\n";
    cout << "Urutan data : ";
    for (double x : data) cout << x << " ";
    cout << "\n";

    cout << "Mean   : " << mean(data) << "\n";
    cout << "Median : " << median(data) << "\n";

    vector<double> m = modus(data);
    cout << "Modus  : ";
    if (m.size() == 1 && m[0] == -9999) cout << "Tidak ada modus\n";
    else {
        for (double x : m) cout << x << " ";
        cout << "\n";
    }

    cout << "Quartil :\n";
    cout << " Q1 = " << quartile(data, 0.25) << "\n";
    cout << " Q2 = " << quartile(data, 0.50) << " (Median)\n";
    cout << " Q3 = " << quartile(data, 0.75) << "\n";

    return 0;
}
