## Background

It is a common thing to simulate a communication scenario between two-part for some protocols in MPC or other fields which covers two parts participating in calculation. The ubiquitous solution is to build the implementation step by step in one program and  ignore the communication  deliberately in order to prove the correctness efficiently. To tell the true, this method is opportunistic but necessary when the time is pressed. However, when we go further and want to measure the performance of communication in the protocol, it is untoward indeed. Could we achieve this demand with the minimal code refactoring?

I take a crack at encapsulating the socket and other else to provide the simplified operation to transform your pseudo-interaction software into a real one. What's more, it provides some functions to test the performance of communication as well.

Of course, this is the prototype system. I am very happy  to accept your suggestions for more functions indeed.



## Project Structure



## Preparation

> Some knowledge used in this project

* C++
* make
* Linux
* (GMP Labrary)

## Use

## Example

