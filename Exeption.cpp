/************************************************** Description *******************************************************/
/*
    File : Exeption.cpp
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
#include <future>
#include <cmath>
/************************************************** Defineds **********************************************************/
/*
    Nothing
*/
/************************************************** Names *************************************************************/
using namespace std;
/************************************************** Variables *********************************************************/
std::mutex Mutex_print;
void Task_1(std::promise<double> &&prms, double num, double denom);
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
    /* define input data */
    double num = 42.0, denom = 0.0;
    /* create promise and future */
    std::promise<double> prms;
    std::future<double> ftr = prms.get_future();
    /* start thread and pass promise as argument */
    thread t1(Task_1, std::move(prms), num, denom);
    // {
    /* retrieve result within try-catch-block */
    try {
        double result = ftr.get();
        Print("Result = " + std::to_string(result));
    }
    catch (std::runtime_error e) {
        Print(e.what());
    }
    // }
    /* Makes the main thread wait for the new threads to finish execution */
    t1.join();
    /* Exit */
    return 0;
}
/************************************************** Tasks *************************************************************/
/* Task 1 */
void Task_1(std::promise<double> &&prms, double num, double denom) {
    try {
        if (denom == 0)
            throw std::runtime_error("Exception from thread: Division by zero!");
        else
            prms.set_value(num / denom);
    }
    catch (...) {
        prms.set_exception(std::current_exception());
    }
}
/************************************************** Vectors ***********************************************************/
/*
    Nothing
*/
/**********************************************************************************************************************/
