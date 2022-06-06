#pragma once
//reverse_matrix_class_shape.h
#include<iostream>

class matrix {
	double** matrix_n1;
	double** matrix_n2;
	int matrix_size;

public:
	matrix();
	void set_my_m1(double** m1);
	double** get_my_mat_n1();

	void set_my_m2(double** m2);
	double** get_my_mat_n2();
	
	void set_my_num(int num_val);
	int get_my_num();

	void matrix_size_get();
	void new_matrix();
	void delete_matrix();

	void matrix_return(double** mymatrix, int n);
	void matrix_n1_Init();
};

class cofactor_deploy{

	matrix for_cofactor_matrix;
	double** matrix_1;
	int n;
	//double det;
	//변수 추가

public:
	cofactor_deploy();
	void return_matrix();
	void return_co_matrix();

	double** get_matrix();
	int get_num();

	double** Submatrix(double** matrix_1, int n, int x, int y);
	
	double determinant_0th(double** matrix_1, int n);
	
	double** cofactor_matrix(double**matrix_1, int n);
};


class reverse_matrix_cofactor {
	cofactor_deploy mymatrix1;
	matrix mymatrix2;

	double** matrix_1;
	//= mymatrix.get_my_mat_n1();

	int n;
	//= mymatrix.get_my_num();
public:
	reverse_matrix_cofactor(cofactor_deploy temp1, matrix temp2);
	double** cofactor_adjoint_matrix(double det, double**, int);
};


class reverse_matrix_gauss {
	matrix mymatrix1;
	cofactor_deploy mymatrix2;
	double** matrix_1;
	double** matrix_2;
	int n;
		//= mymatrix.get_my_num();
	
public:
	reverse_matrix_gauss(cofactor_deploy temp2, matrix temp1);
	double** matrix_rev_return(double det, double**, double**, int);
};



