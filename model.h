/*
 * This file contains functions for obtaining data and manipulating this data.
 *  Author: Fernando Abreu
 *  Date: 11/11/2024
 */


#ifndef INCLUDED_MODEL_H
#define INCLUDED_MODEL_H

#include <iostream>
#include <vector>
#include <string>
#include <filesystem>

#define PROC = "/proc"

using namespace std;

class FProcess {
    private:
        int pid;
        string command;
        FProcess* parent;

    public:
        FProcess(int pid = 0, string command = "", FProcess* parent = NULL);
        ~FProcess();

        void print() const; 
};

void getPIDs(vector<string>& pids);

#endif // INCLUDED_MODEL_H