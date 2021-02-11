#pragma once
#include <string>
#include <fstream>

using namespace std;
class FilterClass
{
public:
	FilterClass(string file, string pattern);
	~FilterClass();

	void Open(string file);
	void Close();
	int SetFilter(string pattern);



private:
	int L = 28;
	int linesize;
	int KXX;
	int	KYY;
	string* arr = new string[L];
	static const char  METASYMBOLSTAR = '*';
	static const char  METASYMBOLQUES = '?';

	void keyPrint(string key);
	void quickSort(int first, int last);
	int binarySearch(string key);
	int metaSymbolStar(string pattern, int metasymbols_tota_star);
	int metaSymbolQues(string pattern, int metasymbols_total_ques);
	void arrExpansion(int old_size, int new_size);
};

