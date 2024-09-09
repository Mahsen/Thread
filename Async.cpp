/************************************************** Description *******************************************************/
/*
    File : Async.cpp
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
#include <future>
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
    /* Example of lambda */
    auto Factorial = [](long long int n) -> long long int {
        long long int Value = 1;
        for( ; n; n--) {
            Value *= n;
        }
        return Value;
    };
    /* Constructs the new tasks */    
    auto Task_1 = std::async(Factorial, 20);
    auto Task_2 = std::async(Factorial, 14);
    /* using task */
    Print(std::to_string(Task_1.get()));
    Print(std::to_string(Task_2.get()));
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
