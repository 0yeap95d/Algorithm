#include <iostream>
#include <cstring>
#define SIZE 201
using namespace std;

string maxValues[SIZE];
string minValues[SIZE];

void setMaxValue() {
	for (int i = 2; i < SIZE; i++) {
		string maxValue = "";
		if (i % 2 == 0)
			for (int j = 0; j < i / 2; j++) maxValues[i] += '1';
		else {
			maxValues[i] += '7';
			for (int j = 0; j < (i / 2) - 1; j++) maxValues[i] += '1';
		}
	}
}

string sumString(string str1, string str2) {
	string result;

	int cnt[10] = { 0, };
	for (char ch : str1) cnt[ch - '0']++;
	for (char ch : str2) cnt[ch - '0']++;

	cnt[0] += cnt[6], cnt[6] = 0;
	if (cnt[0] == str1.size() + str2.size()) cnt[0]--, cnt[6]++;

	for (int i = 0; i < 10; i++) 
		while (cnt[i]--) 
			result += i + '0';

	if (result[0] == '0') {
		for (int i = 1; i < result.size(); i++) {
			if (result[i] != '0') {
				if (result[i] <= '6') swap(result[0], result[i]);
				else result[0] = '6';
				break;
			}
		}
	}

	return result;
}

bool strCompare(string str1, string str2) {
	for (int i = 0; i < str1.size(); i++) {
		if (str1[i] > str2[i]) return true;
		if (str1[i] < str2[i]) return false;
	}
	return false;
}

void setMinValue() {
	minValues[2] = "1";
	minValues[3] = "7";
	minValues[4] = "4";
	minValues[5] = "2";
	minValues[6] = "6";
	minValues[7] = "8";
	minValues[8] = "10";

	for (int i = 9; i < SIZE; i++) {
		minValues[i] = sumString(minValues[7], minValues[i - 7]);
		for (int x = 6; x >= 2; x--) {
			string temp = sumString(minValues[x], minValues[i - x]);
			if (minValues[i].size() < temp.size()) break;
			if (strCompare(minValues[i], temp)) minValues[i] = temp;
		}
	}
}

int main() {

	setMaxValue();
	setMinValue();

	int testcase;
	cin >> testcase;

	int n;
	while (testcase--) {
		cin >> n;
		cout << minValues[n] << " " << maxValues[n] << "\n";
	}

	return 0;
}