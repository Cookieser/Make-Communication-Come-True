#include<iostream>
#include"../include/Test.h"

void simulate(int num,int capacity)
{

    char strBuffer[capacity];

    memset(strBuffer,0,sizeof(strBuffer));


    ServerTest serverTest;

    ClientTest clientTest;

    string command=" ";

    for (int i = 1; i <= num; ++i) {

        command="process"+ to_string(i);

        cout<<"---------------------------"<<endl;

        cout<<i<<":"<<endl;

        clientTest.manipulate(command,strBuffer);

        cout<<"SEND: "<<strBuffer<<endl;

        // This is the communication process using the socket

        cout<<"ACCEPT: "<<strBuffer<<endl;

        serverTest.manipulate(command,strBuffer);

        cout<<"SEND: "<<strBuffer<<endl;

        // This is the communication process using the socket

        cout<<"ACCEPT: "<<strBuffer<<endl;


    }

    cout<<"---------------------------"<<endl;

    cout<<"---------------------------"<<endl;

    cout<< "Server-Volume: "<< serverTest.getTotalVolume() <<" byte"<<endl;

    cout<< "Client-Volume: "<< clientTest.getTotalVolume() <<" byte"<<endl;

    cout<< "Total-Volume: "<< serverTest.getTotalVolume()+clientTest.getTotalVolume() <<" byte"<<endl;

    cout<<"---------------------------"<<endl;

    cout<<"---------------------------"<<endl;


}

int main(){

// A demo can help test the correctness of your protocol, where we ignore the real communication process.
simulate(3,1024);

}


