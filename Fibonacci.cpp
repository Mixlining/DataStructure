//
// Created by QwQ on 2023/1/16.
//

#include "Fibonacci.h"
int Fibonacci(int num)
{
    if(num<=0)
    {
        return 0;
    } else if(num==1)
    {
        return 1;
    }
    else
        return Fibonacci(num-1)+ Fibonacci(num-2);

}


void Fibonacci_run() {
    int num;
    cout<<"enter the number you want"<<endl;
    cin>>num;
    cout<<"Fibonacci number: ";
    for (int i=0;i<num;i++)
    {
        cout<<Fibonacci(i)<<" ";
    }
    cout<<endl;
}
