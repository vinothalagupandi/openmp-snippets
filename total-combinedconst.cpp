#include<bits/stdc++.h>
#include <chrono>
#include<omp.h>
using namespace std;
using namespace std::chrono;

static long num_steps = 1000;
int main(){
    auto start = high_resolution_clock::now();
    int i,x,total,nthreads,constant;
    constant = 12;
    omp_set_num_threads(4);
    #pragma omp parallel for
    {
        int i,x,sum;
        for(i=0;i<num_steps;i++)
        {
            x = i + constant;
            sum +=+ x;
        }
        #pragma omp critical
        // cout<<uniqueID;
        total += sum * constant;
    }

    cout <<"Total : "<<total<<endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
    return 0;

}