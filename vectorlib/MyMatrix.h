#pragma once
#include "MyVector.h"
#include <iostream>

using namespace std;

template <class T>
class Matrix : public Vector <Vector<T> >
{
public:
	Matrix(int size = 1);
	Matrix(const Matrix<T>& m);
	virtual ~Matrix();

	Matrix<T>& operator = (Matrix<T>& m);
	Vector<T>& operator [] (int i);
	int Length();
	int operator == (Matrix<T>& m);
	Matrix<T> operator + (Matrix<T>& m);
	Matrix<T> operator - (Matrix<T>& m);
	Matrix<T> operator * (Matrix<T>& m);
	
	template <class T1>
	friend ostream& operator << (ostream& ostr, const Matrix<T1>& A);
	template <class T1>
	friend istream& operator >> (istream& istr, Matrix<T1>& A);
};

template<class T>
Matrix<T>::Matrix(int size)
{
	if (size <= 0) throw - 1;
	if (size > 0)
	{
		x = new Vector<T>[size];
		for (int i = 0; i < size; i++)
			x[i].ReSize(i + 1);
		length = size;
	}
}

template<class T>
Matrix<T>::Matrix(const Matrix<T>& m)
{
	length = m.length;
	x = new Vector<T>[length];
	for (int i = 0; i < length; i++)
		x[i].ReSize(i + 1);
	for (int i = 0; i < length; i++)
		x[i] = m.x[i];
}

template<class T>
Matrix<T>::~Matrix()
{
	if (x != nullptr)
	{
		delete[] x;
		x = nullptr;
	}
}

template<class T>
Matrix<T>& Matrix<T>::operator=(Matrix<T>& m)
{
	if (this == &m)
		return *this;

	length = m.length;
	if (x != NULL)
		delete[] x;
	x = new Vector<T>[length];
	for (int i = 0; i < length; i++)
		x[i].ReSize(i + 1);
	for (int i = 0; i < length; i++)
		x[i] = m.x[i];
	return *this;
}

template<class T>
Vector<T>& Matrix<T>::operator [] (int i)
{
	if ((i >= 0) && (i < length))
		return x[i];
	else throw - 1;
}

template<class T>
int Matrix<T>::Length()
{
	return length;
}

template<class T>
int Matrix<T>::operator==(Matrix<T>& m)
{
	if (this->Length() != m.Length())
		return 0;
	for (int i = 0; i < m.Length(); i++)
		for (int j = 0; j < m.Length(); j++)
		{
			if (i >= j)
			{
				if ((*this)[i][j] != m[i][j])
					return 0;
			}
		}
	return 1;
}

template<class T>
Matrix<T> Matrix<T>::operator+(Matrix<T>& m)
{
	if (this->Length() != m.Length()) throw - 1;
	Matrix<T> result (m.Length());
	for (int i = 0; i < result.Length(); i++)
		result[i] = (*this)[i] + m[i];
	return result;
}

template<class T>
Matrix<T> Matrix<T>::operator-(Matrix<T>& m)
{
	if (this->Length() != m.Length()) throw - 1;
	Matrix<T> result(m.Length());
	for (int i = 0; i < result.Length(); i++)
		result[i] = (*this)[i] - m[i];
	return result;
}

template<class T>
Matrix<T> Matrix<T>::operator*(Matrix<T>& m)
{
	if (this->Length() != m.Length()) throw - 1;
	Matrix<T> result(m.Length());

	for (int i = 0; i < result.Length(); i++)
		for (int j = 0; j < result.Length(); j++)
		{
			if (i >= j)
			{
				result[i][j] = 0;		
				for (int k = j; k < i+1; k++)
					result[i][j] = result[i][j] + ((*this)[i][k] * m[k][j]);
			}
		}
	return result;
}

template<class T1>
ostream& operator<<(ostream& ostr, const Matrix<T1>& A)
{
	for (int i = 0; i < A.length; i++)
		ostr << A.x[i] << endl;
	return ostr;
}

template<class T1>
istream& operator>>(istream& istr, Matrix<T1>& A)
{
	for (int i = 0; i < A.length; i++)
		istr >> A.x[i];
	return istr;
}
