#include "model.h"
#include <ctime>

int main() {
    clock_t start, end;
    double elapsed_time;
    FProcess* p = new FProcess(2501, "My process", NULL);
    p->print();
    cout << endl;
    vector<string> pids;
    start = clock();
    getPIDs(pids);
    end = clock();
    vector<string>::iterator it;
    for(it = pids.begin(); it != pids.end(); ++it) {
        cout << *it << endl;
    }
    elapsed_time = double(end - start) / CLOCKS_PER_SEC;
    cout << "Time: " << elapsed_time << endl;
    return 0;
}