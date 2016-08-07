#include <Python.h>

#define FNV1A_32_OFFSET   2166136261UL
#define FNV1A_32_PRIME    16777619

#define fnv1a_32(hash, p, metric, firstspace)   \
	hash = FNV1A_32_OFFSET; \
	for (p = metric; p < firstspace; p++) \
		hash = (hash ^ (unsigned int)*p) * FNV1A_32_PRIME;

static unsigned short
_fnv1a(const char *key, int len)
{
	unsigned int hash;
    const char *end = key + len;
	fnv1a_32(hash, key, key, end);
	return (unsigned short)((hash >> 16) ^ (hash & (unsigned int)0xFFFF));
}

static PyObject*
fnv1a(PyObject* self, PyObject* args) {
  const char *metric;
  int len;

  if (!PyArg_ParseTuple(args, "s", &metric)) {
    return NULL;
  }
  if (!PyArg_ParseTuple(args, "n", &len)) {
    return NULL;
  }

  return Py_BuildValue("i", _fnv1a(metric, len));
}

static PyMethodDef Fnv1aMethods[] = {
  {"fnv1a", fnv1a, METH_VARARGS, "Calculate the fnv1a hash."},
  {NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC
initfnv1a(void)
{
  (void) Py_InitModule("fnv1a", Fnv1aMethods);
}
