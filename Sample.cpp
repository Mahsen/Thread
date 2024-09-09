/************************************************** Description *******************************************************/
/*
    File : Sample.cpp
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
void Task_1(void);
void Task_2(void);
/************************************************** Opjects ***********************************************************/
/*
    Nothing
*/
/************************************************** Functions *********************************************************/
int main() {
    /* Print number of core */
    unsigned int NumOfCore = std::thread::hardware_concurrency();
    std::cout << "Number of cores : " << NumOfCore << endl;
    /* Constructs the new threads and runs it */
    thread t1(Task_1);
    thread t2(Task_2);
    /* Makes the main thread wait for the new threads to finish execution */
    t1.join();
    t2.join();
    /* Exit */
    return 0;
}
/************************************************** Tasks *************************************************************/
/* Task 1 */
void Task_1(void) {
    /* Loop to count 10 times */
    for(int Count=0; Count<10; Count++) {  
        /* Print words */
        cout << "Task_1 Count : " << Count << std::endl;
        /* Wait 100 ms */
        usleep(100000);
    }
}
/*--------------------------------------------------------------------------------------------------------------------*/
/* Task 2 */
void Task_2(void) {
    /* Loop to count 10 times */
    for(int Count=0; Count<10; Count++) {   
        /* Print words */
        cout << "Task_2 Count : " << Count << std::endl;
        /* Wait 100 ms */
        usleep(100000);
    }
}
/************************************************** Vectors ***********************************************************/
/*
    Nothing
*/
/**********************************************************************************************************************/
