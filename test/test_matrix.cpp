#include <../gtest/gtest.h>
#include <MyMatrix.h>

TEST(Matrix, can_create_matrix_with_default_size)
{
	ASSERT_NO_THROW(Matrix<int> m1);
}


TEST(Matrix, can_not_create_matrix_with_negative_size)
{
	ASSERT_ANY_THROW(Matrix<int> m1(-1));
}

TEST(Matrix, can_get_length)
{
	Matrix<double> m(12);
	EXPECT_EQ(12, m.Length());
}

TEST(Matrix, can_create_matrix_with_any_size)
{
	Matrix<int> m1(3);
	for (int i = 0; i < m1.Length(); i++)
		EXPECT_TRUE(m1[i].Length() == Vector<int>(i+1, 1).Length());
}

TEST(Matrix, can_copy_matrix)
{
	Matrix<int> m1(3);
	Matrix<int> m2(m1);
	for (int i = 0; i < m2.Length(); i++)
		EXPECT_TRUE(m1[i] == m2[i]);
}

TEST(Matrix, can_found_a_member_of_matrix)
{
	Matrix<int> m1(3);
	m1[1][2] = 9;
	EXPECT_EQ(9, m1[1][2]);
}

TEST(Matrix, can_use_operator_equal)
{
	Matrix<int> m1(3);
	Matrix<int> m2(2);
	m2 = m1;
	for (int i = 0; i < m2.Length(); i++)
		EXPECT_TRUE(m1[i] == m2[i]);
}

TEST(Matrix, can_use_operator_plus)
{
	Matrix<int> m1(2);
	Matrix<int> m2(2);
	Matrix<int> m3;

	for (int i = 0; i < m1.Length(); i++)
		for (int j = 0; j < m1.Length(); j++)
			if (i >= j)
				m1[i][j] = 1;
	for (int i = 0; i < m2.Length(); i++)
		for (int j = 0; j < m2.Length(); j++)
			if (i >= j)
				m2[i][j] = -3;

	m3 = m1 + m2;
	for (int i = 0; i < m3.Length(); i++)
		EXPECT_TRUE(m3[i] == Vector<int>(i+1, -2));
}

TEST(Matrix, can_not_use_operator_plus_with_different_size_of_matrix)
{
	Matrix<int> m1(2);
	Matrix<int> m2(7);
	Matrix<int> m3;

	ASSERT_ANY_THROW(m3 = m1 + m2);
}

TEST(Matrix, can_use_operator_minus)
{
	Matrix<int> m1(2);
	Matrix<int> m2(2);
	Matrix<int> m3;

	for (int i = 0; i < m1.Length(); i++)
		for (int j = 0; j < m1.Length(); j++)
			if (i >= j)
				m1[i][j] = 1;
	for (int i = 0; i < m2.Length(); i++)
		for (int j = 0; j < m2.Length(); j++)
			if (i >= j)
				m2[i][j] = -3;

	m3 = m1 - m2;
	for (int i = 0; i < m3.Length(); i++)
		EXPECT_TRUE(m3[i] == Vector<int>(i + 1, 4));
}

TEST(Matrix, can_not_use_operator_minus_with_different_size_of_matrix)
{
	Matrix<int> m1(2);
	Matrix<int> m2(7);
	Matrix<int> m3;

	ASSERT_ANY_THROW(m3 = m1 - m2);
}

TEST(Matrix, can_use_operator_multiplication)
{	
	Matrix<int> m1(4);
	Matrix<int> m2(4);
	Matrix<int> m3;
	
	for (int i = 0; i < m1.Length(); i++)
		for (int j = 0; j < m1.Length(); j++)
		{
			if (i == j)
			{
				m1[i][j] = -2;
				m2[i][j] = 4;
			}
			else if (i > j)
			{
				m1[i][j] = 1;
				m2[i][j] = -1;
			}
		}

	m1[1][0] = 3;
	m1[3][2] = -3;
	m2[2][1] = 6;
	m2[3][2] = -4;

	m3 = m1 * m2;

	for (int i = 0; i < m3.Length(); i++)
		for (int j = 0; j < m3.Length(); j++)
			if (i == j)
				EXPECT_EQ(-8, m3[i][j]);
	EXPECT_EQ(14, m3[1][0]);
	EXPECT_EQ(5, m3[2][0]);
	EXPECT_EQ(8, m3[3][0]);
	EXPECT_EQ(-8, m3[2][1]);
	EXPECT_EQ(-12, m3[3][1]);
	EXPECT_EQ(-4, m3[3][2]);
}

TEST(Matrix, can_not_use_operator_multiplication_with_different_size_of_matrix)
{
	Matrix<int> m1(4);
	Matrix<int> m2(2);

	ASSERT_ANY_THROW(m1*m2);
}

TEST(Matrix, two_matrix_can_be_compare_with_equal_size)
{
	Matrix<int> m1(2);
	Matrix<int> m2(2);
	Matrix<int> m3(2);

	for (int i = 0; i < m1.Length(); i++)
		for (int j = 0; j < m1.Length(); j++)
			if (i >= j)
			{
				m1[i][j] = 1;
				m2[i][j] = 1;
				m3[i][j] = -1;
			}


	EXPECT_TRUE(m1 == m2);
	EXPECT_FALSE(m1 == m3);
}

TEST(Matrix, two_matrix_can_be_compare_with_different_size)
{
	Matrix<int> m1(3);
	Matrix<int> m2(2);

	for (int i = 0; i < m1.Length(); i++)
		for (int j = 0; j < m1.Length(); j++)
			if (i >= j)
				m1[i][j] = 1;

	for (int i = 0; i < m2.Length(); i++)
		for (int j = 0; j < m2.Length(); j++)
			if (i >= j)
				m2[i][j] = 1;

	EXPECT_FALSE(m1 == m2);
}