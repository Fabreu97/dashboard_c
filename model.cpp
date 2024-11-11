#include "model.h"

FProcess::FProcess(int pid, string command, FProcess* parent):
    pid(pid), command(command), parent(parent)
{}

FProcess::~FProcess() {}

void FProcess::print() const {
    cout << "Process" << endl << "ID: " << this->pid << endl << "COMMAND: " << this->command << endl;
    if(this->parent != NULL) {
        cout << "Parent Process:" << endl;
        parent->print();
    } 
}

const bool is_numeric(const string& str) {
    size_t i = 0;
    if(str.size() > 0) {
        for(i = 0; i < str.size(); i++) {
            if(str[i] > '9' || str[i] < '0') {
                return false;
            }
        }
        return true;
    }
    return false;
}

void getPIDs(vector<string>& pids) {
    string path = "/proc";
    string aux;
    filesystem::directory_iterator it(path);
    filesystem::directory_iterator end;
    if(filesystem::exists(path) && filesystem::is_directory(path)) {
        while(it != end) {
            aux = it->path().string().substr(path.size() + 1);
            if(it->is_directory() && is_numeric(aux)) {
                pids.push_back(aux);
            }
            ++it;
        }
    } else {
        cerr << "O diretorio não existe ou não é válido!" << endl;
    }
}