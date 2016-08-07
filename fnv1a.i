%module fnv1a
%{
  #define SWIG_FILE_WITH_INIT
  #include "fnv1amodule.h"
%}
unsigned short fnv1a(const char*, int);
