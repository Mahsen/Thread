/************************************************** Description *******************************************************/
/*
    File : Atomic.cpp
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
#include <atomic>
/************************************************** Defineds **********************************************************/
/*
    Nothing
*/
/************************************************** Names *************************************************************/
using namespace std;
/************************************************** Variables *********************************************************/
std::mutex Mutex_print;
void Task_1(void);
void Task_2(void);
void Task_3(void);
std::atomic_long  Counter_1(0);
long Counter_2 = 0;
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
    /* Constructs the new threads and runs it */
    thread t1(Task_1);
    thread t2(Task_2);
    thread t3(Task_3);
    /* Makes the main thread wait for the new threads to finish execution */
    t1.join();
    t2.join();
    t3.join();
    /* Print number of core */
    Print("Atomic Counter_1 : " + std::to_string(Counter_1));
    Print("Normal Counter_2 : " + std::to_string(Counter_2));
    /* Exit */
    return 0;
}
/************************************************** Tasks *************************************************************/
/* Task 1 */
void Task_1(void) {
    /* Loop to count 1000000 times */
    for(long long int Count=0; Count<1000000; Count++) {  
        Counter_1++;
        Counter_2++;
    }
}
/*--------------------------------------------------------------------------------------------------------------------*/
/* Task 2 */
void Task_2(void) {
    /* Loop to count 1000000 times */
    for(long long int Count=0; Count<1000000; Count++) {  
        Counter_1++;
        Counter_2++;
    }
}
/*--------------------------------------------------------------------------------------------------------------------*/
/* Task 3 */
void Task_3(void) {
    /* Loop to count 1000000 times */
    for(long long int Count=0; Count<1000000; Count++) {   
        Counter_1++;
        Counter_2++;
    }
}
/************************************************** Vectors ***********************************************************/
/*
    Nothing
*/
/**********************************************************************************************************************/
