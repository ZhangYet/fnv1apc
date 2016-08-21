%module fnv1apc
%{
  #define SWIG_FILE_WITH_INIT
  #include "fnv1apc.h"
%}
unsigned short fnv1a(const char*, int);
