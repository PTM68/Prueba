#include <iostream>
#include <stdio.h>
#include "VarDataRef.h"

VarDataRef * vVDRefInt[MAXNUMVARDATAREFS];//={NULL};

 VarDataRef::VarDataRef()
{
    _Var_id=0;
    _stable=0;
    _provisional=0;
    _status=STATUS_UNASIGNED;

} 
 VarDataRef::VarDataRef(int vId)
{
    _Var_id=vId;
    _stable=0;
    _provisional=0;
    _status=STATUS_UNASIGNED;
    vVDRefInt[_Var_id] = this;
    printf("Dentro del contructor: _Var_id: %i",_Var_id);
    printf(" address stored: %p \n",vVDRefInt[_Var_id]);
} 
void VarDataRef::set_value (int x) {
  _provisional = x;
  _status = STATUS_STABLE;
}

void VarDataRef::confirm_value (int x) {
    if (x == _provisional) {
        _stable = x;
        _status = STATUS_STABLE;
    }
    else
    {
        _provisional = x;
        _status = STATUS_PROVISIONAL;
    }
}

void VarDataRef::print_values() {
    printf(" _provisional: %i\n", _provisional);
    printf("      _stable: %i\n", _stable);
    printf("      _status: %o\n", _status);
}

unsigned char VarDataRef::get_status()
{
    return _status;
}