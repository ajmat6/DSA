#include<iostream>
#include<thread>
#include<unistd.h> // providing an interface to the OS
using namespace std;

void taskA()
{
    for(int i=0; i<10; i++)
    {
        sleep(1); // to make a thread sleep when we have multiple threads in a program
        cout << "Task A: " << i;
        fflush(stdout); // to move the output to the console
    }
}

void taskB()
{
    for(int i=0; i<10; i++)
    {
        sleep(1);
        cout << "Task B: " << i;
        fflush(stdout);
    }
}

int main()
{
    thread t1(taskA);
    thread t2(taskB);

    return 0;
}