#include "FilterClass.h"
#include <string>
#include <iostream>
using namespace std;

FilterClass::FilterClass(string file, string pattern) 
{
    FilterClass::Open(file);

    FilterClass::SetFilter(pattern);
}

FilterClass::~FilterClass() 
{
    delete[] arr;
}

void FilterClass::Close() {
   cout << "[NOTFILE]" << endl;
   exit(EXIT_SUCCESS);
}

void FilterClass::Open(string file)
{
    string line;
    linesize = 0;

    ifstream MyFile(file);

    if (!MyFile.is_open())
    {
        FilterClass::Close();
    }
    else 
    {
        int i = 0;
        while (getline(MyFile, line))
        {
            arr[i] = line;

            if (linesize >= L-1)
            {
                FilterClass::arrExpansion(L, L * 3);
            }

            linesize++;
            i++;

        }
        if ((arr[1] < arr[0]) and (arr[linesize-1] < arr[linesize - 2]))
        {
            FilterClass::quickSort(0, linesize);
        }
    }
    MyFile.close();
}

void FilterClass::arrExpansion(int old_size, int new_size) {
    auto* new_a = new string[new_size];
    for (int i = 0; i < old_size; ++i)
        new_a[i] = arr[i];
    delete[] arr;
    arr = new_a;
}
           
void FilterClass::keyPrint(string key)
{
    int iu = 0;
    string* array = new string[KYY - KXX + 1];
    string key_rev(key.rbegin(), key.rend());

    for (int l = KXX; l < KYY + 1; l++) {
        string rev(arr[l].rbegin(), arr[l].rend());
        if ((strncmp(rev.c_str(), key_rev.c_str(), key.length())) == 0) 
        {
            array[iu] = arr[l];
            cout << array[iu] << '\n';
            iu++;
        }
    }
    delete[] array;
}

int FilterClass::binarySearch(string key)
{
    int n = linesize;
    int lower = 0;
    int upper = n - 1;

    while (lower <= upper) {
        int mid = lower + (upper - lower) / 2;
        if (key == (arr[mid]))
            return mid;
        if (key > (arr[mid]))
            lower = mid + 1;
        else
            upper = mid - 1;
    }


    if (strncmp(arr[lower].c_str(), key.c_str(), key.length()) == 0) {
        if (lower == 0)
        {
            lower++;
        }

        if (arr[lower - 1] < key)
        {
            KXX = lower;
        }


        for (lower; lower < n; lower++)
        {
            if ((strncmp(arr[lower].c_str(), key.c_str(), key.length())) == 0)
            {
                KYY = lower;
            }
        }
    }

    return -1;
}

int FilterClass::SetFilter(string pattern)
{
    int         metasymbols_tota_star = std::count(pattern.begin(), pattern.end(), METASYMBOLSTAR);
    int         metasymbols_total_ques = std::count(pattern.begin(), pattern.end(), METASYMBOLQUES);

    
    if ((metasymbols_tota_star == 0) and (metasymbols_total_ques == 0))
    {
        int result = binarySearch(pattern);
        if (result == -1)
        {
            cout << "[NOT!]" << std::endl;
            return -1;
        }
        cout << arr[result] << std::endl;
        return 0;
    }

    if (!(pattern.find(METASYMBOLSTAR) == -1)) {

        metaSymbolStar(pattern, metasymbols_tota_star);

    }

    if (!(pattern.find(METASYMBOLQUES) == -1))
    {
        metaSymbolQues(pattern, metasymbols_total_ques);
    }
    return 0;
}
  
int FilterClass::metaSymbolStar(string pattern, int metasymbols_tota_star)

{

    if ((metasymbols_tota_star > 1))
    {
        cout << "[NOT!]" << std::endl;
        return -1;
    }

    int  metasymbol_pos = pattern.find(FilterClass::METASYMBOLSTAR);
    string  pref = pattern.substr(0, metasymbol_pos);
    string  suf = pattern.substr(metasymbol_pos + 1);

    FilterClass::binarySearch(pref);
    FilterClass::keyPrint(suf);
    return 0;
}

int FilterClass::metaSymbolQues(string pattern, int metasymbols_total_ques)

{
    if ((metasymbols_total_ques > 1))
    {
        cout << "[WR!]" <<std::endl;
        return -1;
    }

    int  metasymbol_pos = pattern.find(METASYMBOLQUES);
    string  pref = pattern.substr(0, metasymbol_pos);
    string  suf = pattern.substr(metasymbol_pos + 1);
    int max = arr[0].length();

    if ((((metasymbols_total_ques == 1)) and (((pref.length() + suf.length()) < (max - 1)))))
    {
        cout << "[WR!]" << std::endl;
        return -1;
    }
    binarySearch(pref);
    FilterClass::keyPrint(suf);
    return 0;
}

void FilterClass::quickSort(int first, int last) {
    string mid, count;
    int f = first, l = last;
    mid = arr[(f + l) / 2];
    do {
        while (arr[f] < mid) f++;
        while (arr[l] > mid) l--;
        if (f <= l) {
            count = arr[f];
            arr[f] = arr[l];
            arr[l] = count;
            f++;
            l--;
        }
    } while (f < l);
    if (first < l) quickSort(first, l);
    if (f < last) quickSort(f, last);
}