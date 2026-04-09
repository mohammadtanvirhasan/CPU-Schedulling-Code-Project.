#include <stdio.h>

struct process {
    char p_id[10];
    int at, bt, priority;
    int ct, tat, wt;
};

int main() {
    struct process arr[] = {{"p1", 3, 2, 1}, {"p2", 5, 1, 3}, {"p3", 6, 7, 4}, {"p4", 3, 3, 1}};
    int n = 4;
    struct process swap;

    // Sorting Part: Priority, Arrival Time এবং Burst Time এর ভিত্তিতে
    for (int i = 0; i < n - 1; i++) {//Ekta kore process count hobe i diye. Ar eta 1st process theke suru hobe
        for (int j = i + 1; j < n; j++) {//i tomo process er sathe porer process gulo tulona korte

            // ১. প্রায়োরিটি অনুযায়ী সর্ট
            if (arr[i].priority > arr[j].priority) {
                swap = arr[i];
                arr[i] = arr[j];
                arr[j] = swap;
            }
            // Jodi priority same hoy Thkn jar arrival time kom se age asbe.
            else if (arr[i].priority == arr[j].priority) {
                if (arr[i].at > arr[j].at) {
                    swap = arr[i];
                    arr[i] = arr[j];
                    arr[j] = swap;
                }
                //Jodi arrival time  & priority same hoy, tobe SJF (jar Burst Time kom se age asbe)  use hobe
                else if (arr[i].at == arr[j].at && arr[i].priority == arr[j].priority) {
                    if (arr[i].bt > arr[j].bt) {
                        swap = arr[i];
                        arr[i] = arr[j];
                        arr[j] = swap;
                    }
                }
            }
        }
    }

    // Calculation Part
    int current_time = 0;//CPU r current time count korte


 //Current time jodi arrival time hote kom hoy thkn oi somoy ta CPU bose thakbe.  thkn time baray current time k arrival time porjonto neya hoy
    for (int i = 0; i < n; i++) {
        // CPU idle thakle time baray neya hoy. Ei if use kora hoy process ta jhkn asbe thkn theke kaj start korte
        if (current_time < arr[i].at) {
            current_time = arr[i].at;
        }

        arr[i].ct = current_time + arr[i].bt;
        //current_time = arr[i].ct; use hoy somoy k samne nite. Eta bujay ekta process ses hole arekta process oikhan theke start hobe
        current_time = arr[i].ct;

        printf("%s %d %d %d %d\n", arr[i].p_id, arr[i].at, arr[i].bt, arr[i].priority, arr[i].ct);
    }

    return 0;
}
