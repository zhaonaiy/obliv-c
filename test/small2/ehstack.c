// ehstack.c
// NUMERRORS 1
// build a small exception-handling stack, verify field annotation works

#ifndef CCURED
  #define __CANPOINTTOSTACK
#endif

struct Entry {
  struct Entry *next __CANPOINTTOSTACK;
  int *otherPointer;     // not allowed to point at stack
  int x;
};

int *somePtr;

int main(int argc, char **argv)
{
  struct Entry e1, e2;
  int *wildGuy;

  // make everybody wild
  wildGuy = (int*)&somePtr;
  wildGuy = (int*)&e1;
  wildGuy = (int*)&e2;

  // I want to allow this
  e1.next = &e2;

  // but not this
  e1.otherPointer = &e2.x;      // ERROR(1): Stack address

  return 0;
}

