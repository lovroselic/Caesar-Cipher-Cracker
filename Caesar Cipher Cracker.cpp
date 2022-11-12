// https://www.codeabbey.com/index/task_view/caesar-cipher-cracker
// https://www.codeabbey.com/index/task_view/caesar-shift-cipher
// https://www.codeabbey.com/index/wiki/caesar-cipher-breaking-with-least-squares

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <chrono>
#include <cmath>
#include <cassert>
#include <limits>

#include "Console.h"
#include "CodeAbbey.h"
#include "LS_library.h"
#define VERSION "1.0"

using namespace std;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;

string CaesarShift(string str, int key);
vector<double> AnalyzeFrequency(string str);
int CrackCaesar(vector<double> FREQ, vector<double> analysis);
double MSE(vector<double> ref, vector<double> comp);

int main() {
	auto t1 = high_resolution_clock::now();
	cout << "Caesar Cipher Cracker v" << VERSION << "!\n\n";
	//string path = "Test.txt";
	string path = "Try.txt";
	vector<string> raw_data = loadData(path);
	vector<double> FREQ = { 8.1, 1.5, 2.8, 4.3, 13.0, 2.2, 2.0, 6.1, 7.0, 0.15, 0.77, 7.0, 2.4, 6.8, 7.5, 1.9, 0.095, 6.0, 6.3, 9.1, 2.8, 0.98, 2.4, 0.15, 2.0, 0.074 };

	vector<string> solution;

	for (int i = 1; i < raw_data.size(); i++) {
		string problem = raw_data[i];
		vector<double> analysis = AnalyzeFrequency(problem);
		int key = CrackCaesar(FREQ, analysis);
		string decoded = CaesarShift(problem, key);
		vector<string> dec_vector = splitString(decoded, " ");
		vector<string> sub_vector(dec_vector.begin(), dec_vector.begin() + 3);
		decoded = joinVector(sub_vector, " ");
		cout << problem <<  " : " << key << " : " << decoded << endl;
		solution.push_back(decoded);
		solution.push_back(to_string(key));
	}

	cout << "\nSolution: " << joinVector(solution, " ") << endl;;

	/***********************/
	auto t2 = high_resolution_clock::now();
	auto ms_int = duration_cast<milliseconds>(t2 - t1);
	cout << "Execution time: " << ms_int.count() << " ms" << endl;
}

int CrackCaesar(vector<double> FREQ, vector<double> analysis) {
	int minIndex = -1;
	double minMSE = std::numeric_limits<double>::infinity();

	for (int shift = 0; shift < 26; shift++) {
		double mse = MSE(FREQ, analysis);
		if (mse < minMSE) {
			minMSE = mse;
			minIndex = shift;
		}
		analysis.insert(analysis.end(), analysis[0]);
		analysis.erase(analysis.begin());
	}

	return minIndex;
}

double MSE(vector<double> ref, vector<double> comp) {
	vector<double> SE;
	assert(ref.size() == comp.size());
	int size = ref.size();

	for (int i = 0; i < size; i++) {
		SE.push_back(pow(ref[i] - comp[i], 2));
	}
	return average(SE);
}

vector<double> AnalyzeFrequency(string str) {
	vector<double> analysis(26);
	vector<int> count(26);
	int C = 0;
	for (auto& chr : str) {
		int idx = int(chr);
		if (idx != 32 && idx != 46) {
			count[idx - 65] += 1;
			C++;
		}
	}
	for (int i = 0; i < 26; i++) {
		analysis[i] = 100.0 * count[i] / C;
	}
	return analysis;
}

string CaesarShift(string str, int key) {
	string shifted = "";
	for (auto& chr : str) {

		int code = int(chr);
		if (code != 32 && code != 46) {
			code -= key;
			if (code < 65) code += 26;
			chr = char(code);
		}
		shifted += chr;
	}
	return shifted;
}
