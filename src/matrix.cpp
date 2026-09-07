#include "matrix.hpp"
#include <cmath>
#include <cstdlib>
#include <vector>
using namespace std;
Matrix Matrix::add(const Matrix &mat2) const{
    int r1 = rows;
    int c1 = columns;
    int r2 = mat2.getRows();
    int c2 = mat2.getcolumns();
    if (r1 != r2 || c1 != c2) {
        throw std::invalid_argument("Matrix::add - shape is different, cannot perform the operation");
    }
    vector<double> data2 = mat2.getData();
    vector<double> datanew(r1*c1,0);

        for(int i = 0; i<r1*c1;i++){
            datanew[i] = data[i]+data2[i];
        }
        Matrix sum(r1,c1,datanew);
    return sum;
}
Matrix Matrix::subtract(const Matrix &mat2) const{
    int r1 = rows;
    int c1 = columns;
    int r2 = mat2.getRows();
    int c2 = mat2.getcolumns();
    if (r1 != r2 || c1 != c2) {
        throw std::invalid_argument("Matrix::subtract - shape is different, cannot perform the operation");
    }
    vector<double> data2 = mat2.getData();
    vector<double> datanew(r1*c1,0);

        for(int i = 0; i<r1*c1;i++){
            datanew[i] = data[i]-data2[i];
        }
        Matrix difference(r1,c1,datanew);
    return difference;
}
Matrix Matrix::multiply(const Matrix &mat2) const{
    int r1 = rows;
    int c1 = columns;
    int r2 = mat2.getRows();
    int c2 = mat2.getcolumns();
    if (r1 != r2 || c1 != c2) {
        throw std::invalid_argument("Matrix::multiply - shape is different, cannot perform the operation");
    }
    vector<double> data2 = mat2.getData();
    vector<double> datanew(r1*c1,0);

        for(int i = 0; i<r1*c1;i++){
            datanew[i] = data[i]*data2[i];
        }
        Matrix product(r1,c1,datanew);
    return product;
}
//matmul should be here leaving a comment so i can come back later and continue working
Matrix Matrix::transpose()const{
    int r1 = rows;
    int c1 = columns;
    Matrix transpose(c1,r1);
    for(int i = 0; i<r1;i++){
        for(int j = 0;j<c1;j++){
            transpose.set(j,i,this->at(i,j));
        }
    }
    return transpose;
}
#include "matrix.hpp"
#include <cmath>
#include <cstdlib>
#include <vector>
using namespace std;
Matrix Matrix::add(const Matrix &mat2) const{
    int r1 = rows;
    int c1 = columns;
    int r2 = mat2.getRows();
    int c2 = mat2.getcolumns();
    if (r1 != r2 || c1 != c2) {
        throw std::invalid_argument("Matrix::add - shape is different, cannot perform the operation");
    }
    vector<double> data2 = mat2.getData();
    vector<double> datanew(r1*c1,0);

        for(int i = 0; i<r1*c1;i++){
            datanew[i] = data[i]+data2[i];
        }
        Matrix sum(r1,c1,datanew);
    return sum;
}
Matrix Matrix::subtract(const Matrix &mat2) const{
    int r1 = rows;
    int c1 = columns;
    int r2 = mat2.getRows();
    int c2 = mat2.getcolumns();
    if (r1 != r2 || c1 != c2) {
        throw std::invalid_argument("Matrix::subtract - shape is different, cannot perform the operation");
    }
    vector<double> data2 = mat2.getData();
    vector<double> datanew(r1*c1,0);

        for(int i = 0; i<r1*c1;i++){
            datanew[i] = data[i]-data2[i];
        }
        Matrix difference(r1,c1,datanew);
    return difference;
}
Matrix Matrix::scalarmultiply(const double k) const{
    int r1 = rows;
    int c1 = columns;
    vector<double> datanew(r1*c1,0);

        for(int i = 0; i<r1*c1;i++){
            datanew[i] = data[i]*k;
        }
        Matrix scalarproduct(r1,c1,datanew);
    return scalarproduct;
}
//operator overloading 
Matrix Matrix::operator+(const Matrix& mat3) const {
    return add(mat3);
}

Matrix Matrix::operator-(const Matrix& mat3) const {
    return subtract(mat3);
}

Matrix Matrix::operator*(const Matrix& mat3) const {
    return matmul(mat3);
    //have to make a function for matmul xD
}
