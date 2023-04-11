#pragma once

#include <iostream>
#include <stdio.h>

#define MAXNUMVARDATAREFS 100
#define STATUS_STABLE 0000
#define STATUS_PROVISIONAL 0101
#define STATUS_UNASIGNED 0077

class VarDataRef;


class VarDataRef {
  protected:
    int _Var_id;
    int _stable;
    int _provisional;
    unsigned char _status;
  public:
    VarDataRef();
    VarDataRef(int);
    void set_value (int);
    void print_values();
    void confirm_value (int );
    unsigned char get_status();
};


extern VarDataRef * vVDRefInt[];

class VDRColls {
    
public:
//   int HostUPD(&VarDataRef);
};

