#pragma once
#include <ostream>
using namespace std;

struct Pair {
	int key;
	int frequency;
	friend ostream& operator<<(ostream& os, const Pair& p);
};