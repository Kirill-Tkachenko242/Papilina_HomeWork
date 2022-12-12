﻿// sort_race.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <vector>
#include <chrono>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "DataSetRegister.h"
#include "Participants.h"
#include <regex>

using namespace std;

string ParseName(string& method_name)
{
    transform(method_name.begin(), method_name.end(), method_name.begin(),
        [](unsigned char c) { return std::tolower(c); });

    auto res = regex_replace(method_name, std::regex("_by_"), "\t");
    if (res.length() == method_name.length())
    {
        res = regex_replace(res, std::regex("by"), "\t");
        if (res.length() == method_name.length())
            res = regex_replace(res, std::regex("_"), "\t");
    }
    return res;
}

#define RUN(x) {                \
    Run(#x, x, data);           \
}


static string team = "";
static string dataset = "";
static vector<string> logs;

template <typename T>
void Run(string method_name, Participant<T> p, vector<T> data)
{
    auto start = chrono::system_clock::now();
    vector<T> res = p(data);
    auto stop = chrono::system_clock::now();
    auto time = chrono::duration_cast<chrono::microseconds>(stop - start).count();

    ostringstream oss{};
    oss << "\"" << dataset << "\"\t"
        << data.size() << "\t"
        << team << "\t"
        << ParseName(method_name) << "\t"
        << ((data.size() == res.size() && is_sorted(res.begin(), res.end())) ? to_string(time) : "-1");
    logs.push_back(oss.str());
}

int main()
{
    {
        cout << endl << "Integer" << endl << endl;

        auto intDataSets = GenerateIntDataSets();
        while (!intDataSets.empty())
        {
            auto& ds = intDataSets.top();
            dataset = ds.description;
            auto& data = ds.data;
            
            team = "TkachenkoTeam";
            RUN(bubblesort_by_tkachenko);
            RUN(insertionSort_by_sheiko);
            RUN(merge_sort_by_medvedev);
            RUN(quick_sort_by_Loganov);
            RUN(shellsort_by_doronin);
            RUN(select_sort_by_lilichev);
            intDataSets.pop();
        }
    }
    {
        cout << endl << "Double" << endl << endl;
        auto doubleDataSets = GenerateDoubleDataSet();
        while (!doubleDataSets.empty())
        {
            auto& ds = doubleDataSets.top();
            dataset = ds.description;
            auto& data = ds.data;

            
            team = "TkachenkoTeam";
            RUN(bubblesort_by_tkachenko);
            RUN(insertionSort_by_sheiko);
            RUN(merge_sort_by_medvedev);
            RUN(quick_sort_by_Loganov);
            RUN(shellsort_by_doronin);
            RUN(select_sort_by_lilichev);
            doubleDataSets.pop();
        }
    }
    {
        ofstream fout("release.txt");
        for (auto& s : logs)
            fout << s << endl;
    }
}