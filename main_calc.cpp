#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"reverse_matrix_class_shape.h"
using namespace std;

int main(void)
{
	matrix m1;
	cofactor_deploy m2;
	reverse_matrix_gauss m3(m2,m1);
	reverse_matrix_cofactor m4(m2, m1);
	int size_of_matrix;
	int run_num1 = 1;
	int run_num2 = 1;

	m1.matrix_size_get();
	size_of_matrix = m1.get_my_num();

	//==================================================================================================
	m1.new_matrix();
	//==================================================================================================
	m1.matrix_n1_Init();
	//두 행렬들의 출력
	m1.matrix_return(m1.get_my_mat_n1(), m1.get_my_num());
	m1.matrix_return(m1.get_my_mat_n2(), m1.get_my_num());
	//==================================================================================================
	//여인수 전개
	cout<<"[determinant_testing...] : " << m2.determinant_0th(m1.get_my_mat_n1(), m1.get_my_num()) <<" 입니다.\n" << endl;

	//역행렬 구하기
		//가우스 일루미네이션
Line1:
	cout<<"가우스 조던 소거법으로 역행렬을 출력하시겠습니까? [input : 1(yes)/0(no)] : ";
	cin >> run_num1;
	if(run_num1 == 1)
	{
		m3.matrix_rev_return(m2.determinant_0th(m1.get_my_mat_n1(), m1.get_my_num()) , m1.get_my_mat_n1(), m1.get_my_mat_n2(), m1.get_my_num());
	}
	else if (run_num1 == 0)
	{
		cout << "[가우스 조던 소거법을 이용한 역행렬 연산을 진행하지 않습니다...]" << endl;
	}
	else {
		cout<<"[숫자를 정확히 입력해 주십시오]" << endl;
		goto Line1;
	}
	
	//행렬식으로 역행렬구하기
Line2:
	cout << "여인수전개법으로 역행렬을 출력하시겠습니까? [input : 1(yes)/0(no)] : ";
	cin >> run_num2;
	if (run_num2 == 1)
	{
		m4.cofactor_adjoint_matrix(m2.determinant_0th(m1.get_my_mat_n1(), m1.get_my_num()),m2.cofactor_matrix(m1.get_my_mat_n1(),m1.get_my_num()),m1.get_my_num());
	}
	else if(run_num2 == 0)
	{
		cout<<"[여인수 전개법을 이용한 역행렬 연산을 진행하지 않습니다...]" << endl;
	}
	else {
		cout << "[숫자를 정확히 입력해 주십시오]" << endl;
		goto Line2;
	}
	//==================================================================================================
	m1.delete_matrix();
	//==================================================================================================
	return 0;
}
