#include "model.h"

#define READ "r"

Process::Process(int pid, string command, char state, Process* parent):
    pid(pid), command(command), state(state), parent(parent)
{}

Process::~Process() {}

void Process::print() const {
    cout << "Process" << endl << "ID: " << this->pid << endl << "COMMAND: " << this->command << endl;
    if(this->parent != NULL) {
        cout << "Parent Process:" << endl;
        parent->print();
    }
    cout << endl;
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
void getLineReturnsWords(vector<string>& words, const string& line) {
    size_t i;
    string aux = "";
    for(i=0; i < line.size(); i++) {
        if(line[i] == ' ' || line[i] == '\n' || line[i] == '\0') {
            words.push_back(aux);
            aux = "";
        } else {
            aux.push_back(line[i]);
        }
    }
}

const int getStringInt(string number) {
    size_t i;
    int ans = 0;
    for(i = 0; i < number.size(); i++) {
        ans *= 10;
        ans = ans + (number[i] - '0');
    }
    return ans;
}

void getInfoProcess(vector<Process>& p) {
    vector<string> pids;
    vector<string>::iterator it;
    string path;
    getPIDs(pids);
    for(it = pids.begin(); it != pids.end(); ++it) {
        path = "/proc/" + *it + "/stat";
        ifstream file(path);
        string line;
        if(!file) {
            cerr << "Erro ao abrir o arquivo: " << path << endl;
            continue;
        }
        while(getline(file, line)) {
            vector<string> data_process;
            getLineReturnsWords(data_process, line);
            p.push_back(Process(getStringInt(data_process[0]), data_process[1], data_process[2][0], NULL));
        }
        file.close();
    }
}