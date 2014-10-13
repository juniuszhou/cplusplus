#include "stdlib.h"
#include<unistd.h>
#include "stdio.h"
#include "sched.h"
#include "signal.h"
#define FIBER_STACK 8192
#include <stdio.h>;
#include <sched.h>;
#include <signal.h>;
#include <iostream>
using namespace std;

int my_function(void * v)
{
        cout << "--- in new process ---" << endl;
}

int main ()
{
        void * stack;

        signal(SIGCHLD,SIG_IGN);

                stack=(void*)malloc(81920);
		//stack is downward, so need start from high address.
                clone(my_function,stack+80000,CLONE_VM|SIGCHLD,NULL);
                cout << "I am main" << endl;
		return 0;
}