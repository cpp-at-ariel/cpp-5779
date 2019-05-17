#pragma once
#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <deque>
#include <map>
using namespace std;


template<typename T>
ostream& operator<< (ostream& out, const vector<T>& c) {
	for (int i: c)
		out << i << ' ';
	return out;
}


template<typename T, unsigned long N>
ostream& operator<< (ostream& out, const array<T,N>& c) {
	for (int i: c)
		out << i << ' ';
	return out;
}

template<typename T>
ostream& operator<< (ostream& out, const set<T>& c) {
	for (int i: c)
		out << i << ' ';
	return out;
}

template<typename T>
ostream& operator<< (ostream& out, const list<T>& c) {
	for (int i: c)
		out << i << ' ';
	return out;
}

template<typename T>
ostream& operator<< (ostream& out, const deque<T>& c) {
	for (int i: c)
		out << i << ' ';
	return out;
}

template<typename K, typename V>
ostream& operator<< (ostream& out, const map<K,V>& c) {
	for (auto [k,v]: c)
		out << k << ":" << v << ' ';
	return out;
}

template<typename K, typename V>
ostream& operator<< (ostream& out, const map<set<K>,V>& c) {
	for (auto [k,v]: c)
		out << "{" << k << "}: " << v << endl;
	return out;
}
