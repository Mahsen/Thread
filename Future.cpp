/************************************************** Description *******************************************************/
/*
    File : Future.cpp
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
void Task_1(std::promise<double> &&prms, double input);
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
    double inputData = 42.0;
    /* create promise and future */
    std::promise<double> prms;
    std::future<double> ftr = prms.get_future();
    /* start thread and pass promise as argument */
    thread t1(Task_1, std::move(prms), inputData);
    // {
    /* wait for result to become available */
    auto status = ftr.wait_for(std::chrono::milliseconds(1000));
    /* result is ready  */
    if (status == std::future_status::ready) {
        Print("Result = " + std::to_string(ftr.get()));
    }
    /* timeout has expired or function has not yet been  */
    else if (status == std::future_status::timeout || status == std::future_status::deferred)
    {
        Print("Result unavailable");
    }
    // }
    /* Makes the main thread wait for the new threads to finish execution */
    t1.join();
    /* Exit */
    return 0;
}
/************************************************** Tasks *************************************************************/
/* Task 1 */
void Task_1(std::promise<double> &&prms, double input) {
    usleep(2000); // for show
    double output = sqrt(input);
    prms.set_value(output);
}
/************************************************** Vectors ***********************************************************/
/*
    Nothing
*/
/**********************************************************************************************************************/
