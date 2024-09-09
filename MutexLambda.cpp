/************************************************** Description *******************************************************/
/*
    File : MutexLambda.cpp
    Programmer : Mohammad Lotfi
    Used : Example
    Design Pattern : Nothing
    Types of memory : Heap & Stack
    Total Tread : Nothing
    Site : https://www.mahsen.ir
    Tel : +989124662703
    Email : info@mahsen.ir
    Last Update : 2024/9/9
*/
/************************************************** Warnings **********************************************************/
/*
    Nothing
*/
/************************************************** Wizards ***********************************************************/
/*
    Nothing
*/
/************************************************** Includes **********************************************************/
#include <string>
#include <iostream>
#include <thread>
#include <unistd.h>
#include <mutex>  
/************************************************** Defineds **********************************************************/
/*
    Nothing
*/
/************************************************** Names *************************************************************/
using namespace std;
/************************************************** Variables *********************************************************/
std::mutex Mutex_print;
/************************************************** Opjects ***********************************************************/
/*
    Nothing
*/
/************************************************** Functions *********************************************************/
void Print(string str) {
    /* Lock untile return of block */
    std::lock_guard<std::mutex> guard(Mutex_print);
    /* Show on console */
    std::cout << str << endl;
}
/*--------------------------------------------------------------------------------------------------------------------*/
int main() {
    /* Print number of core */
    unsigned int NumOfCore = std::thread::hardware_concurrency();
   // Print("Number of cores : " + std::to_string(NumOfCore));
    /* Constructs the new threads and runs it */
    thread t1([] {
        /* Loop to count 10 times */
        for(int Count=0; Count<10; Count++) {  
            /* Print words */
            Print("Task_1 Count : " + std::to_string(Count));
            /* Wait 100 ms */
            usleep(1000);
        }
    });
    thread t2([] {
        /* Loop to count 10 times */
        for(int Count=0; Count<10; Count++) {  
            /* Print words */
            Print("Task_2 Count : " + std::to_string(Count));
            /* Wait 100 ms */
            usleep(1000);
        }
    });
    /* Makes the main thread wait for the new threads to finish execution */
    t1.join();
    t2.join();
    /* Exit */
    return 0;
}
/************************************************** Tasks *************************************************************/
/*
    Nothing
*/
/************************************************** Vectors ***********************************************************/
/*
    Nothing
*/
/**********************************************************************************************************************/
