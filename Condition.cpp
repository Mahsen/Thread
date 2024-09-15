/************************************************** Description *******************************************************/
/*
    File : Condition.cpp
    Programmer : Mohammad Lotfi
    Used : Example
    Design Pattern : Nothing
    Types of memory : Heap & Stack
    Total Tread : Nothing
    Site : https://www.mahsen.ir
    Tel : +989124662703
    Email : info@mahsen.ir
    Last Update : 2024/9/15
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
#include <queue>
#include <condition_variable>
/************************************************** Defineds **********************************************************/
/*
    Nothing
*/
/************************************************** Names *************************************************************/
using namespace std;
/************************************************** Variables *********************************************************/
std::mutex Mutex_print;
std::mutex Mutex_Message;
std::queue<string> Message;
std::condition_variable cv;
void Task_1(void);
void Task_2(void);
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
    /* Makes the main thread wait for the new threads to finish execution */
    t1.join();
    t2.join();
    /* Exit */
    return 0;
}
/************************************************** Tasks *************************************************************/
/* Task 1 */
void Task_1(void) {
    /* Loop forever */
    while(true) {
        std::unique_lock<std::mutex> lock(Mutex_Message);
        cv.wait(lock, [] { return !Message.empty(); });
        /* Check not empty */
        if(!Message.empty()) {  
            /* Print words */
            Print(Message.front());
            Message.pop();
        }
    }
}
/*--------------------------------------------------------------------------------------------------------------------*/
/* Task 2 */
void Task_2(void) {
    /* Loop to count 5 times */
    for(int Count=0; Count<5; Count++) {   
        std::unique_lock<std::mutex> lock(Mutex_Message);
        Message.push("Hi " + std::to_string(Count));
        cv.notify_one();
        /* Wait 100ms */
        usleep(100000);
    }
    /* Kill app */
    exit(0);
}
/************************************************** Vectors ***********************************************************/
/*
    Nothing
*/
/**********************************************************************************************************************/
