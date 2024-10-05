double **allocateMatrix(int m, int n) {

  double **mat = new double *[m];
  for (int i = 0; i < m; ++i) {
    mat[i] = new double[n];
  }
  return mat;
}