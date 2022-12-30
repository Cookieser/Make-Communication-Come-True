## Background

It is a common thing to simulate a communication scenario between two-part for some protocols in MPC or other fields which covers two parts participating in calculation. The ubiquitous solution is to build the implementation step by step in one program and  ignore the communication  deliberately in order to prove the correctness efficiently. To tell the true, this method is opportunistic but necessary when the time is pressed. However, when we go further and want to measure the performance of communication in the protocol, it is untoward indeed. Could we achieve this demand with the minimal code refactoring?

I take a crack at encapsulating the socket and other else to provide the simplified operation to transform your pseudo-interaction software into a real one. What's more, it provides some functions to test the performance of communication as well.

Of course, this is the prototype system. I am very happy  to accept your suggestions for more functions indeed.



## Project Structure

* bin
  * client
  * server
  * simulate
* include
  * socket.h
  * Test.h
* source
  * ClientDetail.cpp
  * ServerDetail.cpp
* src
  * client.cpp
  * server.cpp
  * simulate.cpp
  * socket.cpp
* makefile
* README

## Preparation

> Some knowledge used in this project

* C++
* make
* Linux
* (GMP Labrary)

## Use

### Add

Add your specific protocol into `source/ClientDetail` and `source/ServerDetail` by this form 

Keep the naming format of the function to avoid problems, please.

```C++
	char* ClientTest::process1(char *strBuffer){

        // PROCESS ONE ...
    }

    char* ClientTest::process2(char *strBuffer){

        // PROCESS TWO ...
    }

    char* ClientTest::process3(char *strBuffer){

        // PROCESS THREE ...
    }
```

```C++
    char* ServerTest::process1(char *strBuffer){

        // PROCESS ONE ...
    }

    char* ServerTest::process2(char *strBuffer){

        // PROCESS TWO ...
    }

    char* ServerTest::process3(char *strBuffer){

        // PROCESS THREE ...
    }
 	......

```



### Modified declaration

Modify the file content on `ClientTest Class` and `ServerTest Class` in `include/Test.h` accordingly 

![image-20221230153043434](https://pic-1306483575.cos.ap-nanjing.myqcloud.com/images/image-20221230153043434.png)



### Compile

```shell
# Compile program
make

# Run
cd bin

# Start two terminals to executive command respectively
# Terminal one: ./server port
./server 5050

# Terminal two: ./client ip port
./client 127.0.0.1 5050

# simulate: provide the function to verify the correctness of your coding protocol
./simulate
```

## Example

![image-20221230153849082](https://pic-1306483575.cos.ap-nanjing.myqcloud.com/images/image-20221230153849082.png)

![image-20221230154045721](https://pic-1306483575.cos.ap-nanjing.myqcloud.com/images/image-20221230154045721.png)

![image-20221230154124118](https://pic-1306483575.cos.ap-nanjing.myqcloud.com/images/image-20221230154124118.png)
