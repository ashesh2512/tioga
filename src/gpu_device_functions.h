#ifndef GPU_DEVICE_FUNCTIONS_H
#define GPU_DEVICE_FUNCTIONS_H

#include "tioga_gpu.h"
#include <cmath>

#define NEQNS 3
#define maxStackSize 2048
#define d_fabs(a) (a > 0 ? a:-a)

// leave this as pifus native for now for 
// posterity sake, fix later
// 
//# define TIOGA_DEVICE_MIN(x,y)  (x) < (y) ? (x) : (y)
//# define TIOGA_DEVICE_MAX(x,y)  (x) > (y) ? (x) : (y)
# define TIOGA_DEVICE_BIGVALUE 1e15
# define TIOGA_DEVICE_TOL 1e-10
# define TIOGA_DEVICE_BASE 1

TIOGA_GPU_DEVICE
void invertMat3(double A[3][3],
  double f[3]);

TIOGA_GPU_DEVICE
void d_solvec(double a[NEQNS][NEQNS],double b[NEQNS],int *iflag,int n);

TIOGA_GPU_DEVICE
void d_newtonSolve(double f[7][3],double *u1,double *v1,double *w1);

TIOGA_GPU_DEVICE
void d_computeNodalWeights(double xv[8][3],double *xp,double frac[8],int nvert);

TIOGA_GPU_DEVICE	   
void d_checkContainment(double *x, int **vconn,int *nc, int *nv, int ntypes, int *elementList,
  int cellIndex[2], int adtElement, double *xsearch);

TIOGA_GPU_DEVICE
void d_searchIntersections_containment(int idx, int cellIndex[2],
  int *adtIntegers,
  double *adtReals,
  double *coord,
  double *xsearch,
  double *x, int *nc, int *nv,int ntypes,
  int *elementList,
  int **vconn,
  int nelem,
  int ndim,
  int *nchecks);

#endif /* GPU_DEVICE_FUNCTIONS_H */
