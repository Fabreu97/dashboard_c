#include "model.h"
#include <ctime>

int main() {
    clock_t start, end;
    vector<Process> list_p;
    size_t i;
    start = clock();
    getInfoProcess(list_p);
    end = clock();
    for(i=0; i < list_p.size(); i++) {
        list_p[i].print();
    }
    double elapsed_time = double(end - start) / CLOCKS_PER_SEC;
    cout << "Time: " << elapsed_time << endl;
    return 0;
}