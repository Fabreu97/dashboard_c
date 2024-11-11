/*
 * This file contains functions for obtaining data and manipulating this data.
 *  Author: Fernando Abreu
 *  Date: 11/11/2024
 */

/*
 * state (R is running, S is sleeping, D is sleeping in an uninterruptible wait, Z is zombie, T is traced or stopped)
 */

#ifndef INCLUDED_MODEL_H
#define INCLUDED_MODEL_H

#include "auxiliary_functions.h"
#include <fstream>
#include <filesystem>

#define PROC = "/proc"
#define LABEL_PROCESS ("PID", "COMMAND", "STATE", "PARENT PROCESS") // label das informações
using namespace std;

class Process {
    private:
        int pid;
        string command;
        char state;
        Process* parent;

    public:
        Process(int pid = 0, string command = "", char state='U',Process* parent = NULL);
        ~Process();

        void print() const; 
};

const bool is_numeric(const string& str);
void getPIDs(vector<string>& pids);
void getLineReturnsWords(vector<string>& words, const string& line);
const int getStringInt(string number);
void getInfoProcess(vector<Process>& p);

#endif // INCLUDED_MODEL_H