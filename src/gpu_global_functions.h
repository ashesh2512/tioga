#ifndef GPU_GLOBAL_FUNCTIONS_H
#define GPU_GLOBAL_FUNCTIONS_H

#include "tioga_gpu.h"
#include "TiogaMeshInfo.h"

TIOGA_GPU_GLOBAL
void g_reset_iblanks(TIOGA::MeshBlockInfo * m_info);

TIOGA_GPU_GLOBAL
void g_adt_search(TIOGA::MeshBlockInfo* m_info, 
  double *coord, double *adtExtents, int *adtIntegers, double *adtReals,
  int *elementList, int *donorId, double *xsearch,
  int ndim, int nelem, int nsearch, int myid);

#endif /* GPU_GLOBAL_FUNCTIONS_H */
