#include <iostream>
#include<vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include<deque>
#include<sstream>
#include<set>
#include <unordered_set>
using namespace std;
class kniga {
public:
	string name;
	string god;
	string nazv;
	string izdat;

	int chist;
	kniga() {}
	kniga(string n, string g, string naz, string iz, int ch) :name(n), god(g), nazv(naz), izdat(iz), chist(ch) {}
	kniga(kniga& copy) {
		this->name = copy.name;
		this->god = copy.god;
		this->nazv = copy.nazv;
		this->izdat = copy.izdat;

		this->chist = copy.chist;
	}
	kniga(kniga&& perem) {
		swap(this->name, perem.name);
		swap(this->god, perem.god);
		swap(this->nazv, perem.nazv);
		swap(this->izdat, perem.izdat);

		swap(this->chist, perem.chist);

	}
	kniga& operator=(const kniga& k1) {
		this->name = k1.name;
		this->god = k1.god;
		this->nazv = k1.nazv;
		this->izdat = k1.izdat;

		this->chist = k1.chist;
	}
	bool operator == (const kniga & k) const {
		return this->name == k.name;
	}
	bool operator<(const kniga& k) const {
		return this->name < k.name;
	}
	friend ostream& operator<<(ostream& o, const kniga& k) {
		cout << k.name << ": " << k.god << k.nazv << "," << k.izdat << "," << k.chist << endl;
		return o;
	}
};
struct hashworker {
	size_t operator()(const kniga& k1) const {
		return hash<string>()(k1.name);
	}
};
bool comp(const kniga& k1, const kniga& k2) {
	return (k1.name < k2.name);
}

int main()
{
	vector<kniga> spisok;
	ifstream input("input.txt");
	set<kniga> set1;
	unordered_set<kniga, hashworker> set2;
	string name, nazv, izdat, god;int chist;
	int izdat;
	while (getline(input, name)) {
		input >> nazv >> izdat >> chist;
		input.ignore();
		spisok.push_back(kniga(name, god, nazv, izdat, chist));
		set1.insert(kniga(name, god, nazv, izdat, chist));
		set2.insert(kniga(name, god, nazv, izdat, chist));
	}

	ofstream output("output.txt");
	output << "Original container:" << endl;
	cout << "Original container:" << endl;
	for (const auto& x : spisok) {
		output << x << endl;
	}

	deque<kniga> copied_spisok;
	copied_spisok.resize(spisok.size());
	copy(spisok.begin(), spisok.end(), copied_spisok.begin());
	sort(spisok.begin(), spisok.end(), comp);

	output << "Sorted container:" << endl;
	cout << "Sorted container:" << endl;
	for (const auto& x : spisok) {
		output << x << endl;
	}
	output << "Copied container:" << endl;
	cout << "Copied container:" << endl;
	for (const auto& x : copied_spisok) {
		output << x << endl;
	}
	cout << "test for set1" << endl;
	for (const auto& x : set1) {
		output << x << endl;
	}
	cout << "test for set2" << endl;
	for (const auto& x : set2) {
		output << x << endl;
	}

}