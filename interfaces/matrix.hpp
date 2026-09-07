#pragma once
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Matrix{
    private:
int rows;
int columns;
vector<double> data;
    public:
Matrix(int r, int c,vector<double> d);
Matrix(int rows, int columns);


int getRows() const;
int getcolumns() const;
vector<double> getData() const;
double at(int row, int col) const;


void set(int row, int col, double value);
void setRows(const int &rows);
void setColumns(const int &columns);
void setData(const vector<double> &data);


Matrix add(const Matrix &mat1)const ;
Matrix subtract(const Matrix &mat1)const ;
Matrix multiply(const Matrix &mat1)const ;
Matrix matmul(const Matrix &mat1)const ;
Matrix transpose()const;
Matrix scalarmultiply(double k)const;

Matrix operator+(const Matrix& mat3)const;
Matrix operator-(const Matrix& mat3)const;
Matrix operator*(const Matrix& mat3)const;

};