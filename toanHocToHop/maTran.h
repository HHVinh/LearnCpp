#ifndef MATRAN_H
#define MATRAN_H

void taoMaTran(int** &arr, int n);
void inMaTran(int** arr, int n);
void themCanh(int** arr, int n, int src, int dest, int w);
bool kiemTraCanh(int** arr, int n, int src, int dest);
int layTrongSo(int** arr, int n, int src, int dest);

#endif
