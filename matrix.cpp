
#include <iostream>


struct Matrix{
    int** matrix = nullptr;
    size_t n;
    size_t m;
};
void Construct(Matrix& mat, size_t n, size_t m) {
    mat.n = n;
    mat.m = m;
    mat.matrix = new int*[n];
    for (size_t i = 0; i < n; ++i) {
        mat.matrix[i] = new int[m]();
    }
}
Matrix Copy(const Matrix& matrix){
        Matrix matc;
        Construct(matc, matrix.n, matrix.m);
        for (size_t i = 0; i < matrix.n; ++i) {
            for (size_t j = 0; j < matrix.m; ++j) {
                matc.matrix[i][j] = matrix.matrix[i][j];
            }
        }
        return matc;
}
Matrix Add(const Matrix& a, const Matrix& b){
    if((a.n != b.n) and (a.m != b.m)){
        Matrix empty;
        return empty;
    }
    else{
        Matrix mata;
        Construct(mata, a.n, a.m);
        for(size_t i = 0; i < a.n; ++i){
            for(size_t j = 0; j < a.m; ++j){
                mata.matrix[i][j] = a.matrix[i][j] + b.matrix[i][j];
            }
        }
        return mata;
    }
}
Matrix Sub(const Matrix& a, const Matrix& b){
    if((a.n != b.n) and (a.m != b.m)){
        Matrix empty;
        return empty;
    }
    else{
        Matrix mats;
        Construct(mats, a.n, a.m);
        for(size_t i = 0; i < a.n; ++i){
            for(size_t j = 0; j < a.m; ++j){
                mats.matrix[i][j] = a.matrix[i][j] - b.matrix[i][j];
            }
        }
        return mats;
    }
}
Matrix Mult(const Matrix& a, const Matrix& b){
    if(a.m != b.n){
        Matrix empty;
        return empty;
    }
    else{
        Matrix matm;
        Construct(matm, a.n, a.m);
        for(size_t i = 0; i < a.n; ++i){
            for(int j = 0; j < b.m; ++j)
            {
                matm.matrix[i][j] = 0;
                for(size_t f = 0; f < a.m; ++f){
                    matm.matrix[i][j] += a.matrix[i][f] * b.matrix[f][j];
                }
            }
        }
        return matm;
    }
}
void Transposition(Matrix& matriiix){
    Matrix matt;
    Construct(matt, matriiix.n, matriiix.m);
    for(size_t i = 0; i < matriiix.n; ++i){
        for(size_t j = 0; j < matriiix.m; ++j){
            matt.matrix[i][j] = matriiix.matrix[j][i];
        }
    }
    matriiix = matt;
}
void Destruct(Matrix& in) {
    for (size_t i = 0; i < in.n; ++i) {
        delete[] in.matrix[i];
    }
    delete[] in.matrix;
    in.matrix = nullptr;
    in.n = 0;
    in.m = 0;
}
int main(){
    size_t n, m;
    std::cout << "Введите кол строчек: " << std::endl;
    std::cin >> n;
    std::cout << "Введите кол столбцов: " << std::endl;
    std::cin >> m;
    Matrix mat1;
    Construct(mat1, n, m);
    std::cout << "Матрица 1:" << std::endl;
    for(size_t i = 0; i < n; ++i){
        for(size_t j = 0; j < m; ++j){
            std::cout << "Введите " << "[" << i << "]" << "[" << j << "] элемент" << std::endl;
            std::cin >> mat1.matrix[i][j];
        }
    }
    std::cout << "Матрица 2:" << std::endl;
    Matrix mat2;
    Construct(mat2, n, m);
    for(size_t i = 0; i < n; ++i){
        for(size_t j = 0; j < m; ++j){
            std::cout << "Введите " << "[" << i << "]" << "[" << j << "] элемент" << std::endl;
            std::cin >> mat2.matrix[i][j];
        }
    }
    Matrix sum = Add(mat1, mat2);
    Matrix sub = Sub(mat1, mat2);
    Matrix mult = Mult(mat1, mat2);
    std::cout << "Сумма:" << std::endl;
    for (size_t i = 0; i < sum.n; ++i) {
        for (size_t j = 0; j < sum.m; ++j) {
            std::cout << sum.matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Разность:" << std::endl;
    for (size_t i = 0; i < sum.n; ++i) {
        for (size_t j = 0; j < sum.m; ++j) {
            std::cout << sub.matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Умножение:" << std::endl;
    for (size_t i = 0; i < sum.n; ++i) {
        for (size_t j = 0; j < sum.m; ++j) {
            std::cout << mult.matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
        
}
