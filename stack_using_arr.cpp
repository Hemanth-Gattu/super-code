#include<bits/stdc++.h>

using namespace std;
class Stack {
  int size;
  int * arr;
  int top;
  public:
    Stack() {
      top = -1;
      size = 1000;
      arr = new int[size];//intialise array size
    }
  void push(int x) {
    top++;//ctr for topmost element
    arr[top] = x;//store at top
  }
  int pop() {
    int x = arr[top];//store topmost element
    top--;//decrease counter for top
    return x;
  }
  int Top() {
    return arr[top];
  }
  int Size() {
    return top + 1;
  }
};
