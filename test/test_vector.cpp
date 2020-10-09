#include <../gtest/gtest.h>
#include <MyVector.h>

TEST(Vector, can_create_vecrot_with_default_constrant)
{
	ASSERT_NO_THROW(Vector<int> v1);
}

TEST(Vector, can_get_size)
{
	Vector<double> v1(10);

	EXPECT_EQ(1, v1.Length());
}


TEST(Vector, can_use_operator_index_for_vectors)
{

	Vector<double> v1(7.85);

	EXPECT_EQ(7.85, v1[0]);
}

TEST(Vector, can_create_vector_eith_size_one)
{
	Vector<double> v1(5.1);

	EXPECT_EQ(1, v1.Length());
	EXPECT_EQ(5.1, v1[0]);
}

TEST(Vector, can_create_vector_with_one_value)
{
	Vector<int> v1(5, 10);

	EXPECT_EQ(5, v1.Length());
	for (int i = 0; i < v1.Length(); i++)
		EXPECT_EQ(10, v1[i]);
}

TEST(Vector, can_copy_vector)
{
	Vector<int> v1(3, 1);
	Vector<int> v2(v1);

	EXPECT_EQ(3, v2.Length());
	for (int i = 0; i < v2.Length(); i++)
		EXPECT_EQ(1, v2[i]);
}

TEST(Vector, can_use_operator_plus_for_vectors)
{
	Vector <int> v1(3, 1);
	Vector <int> v2(3, -1);

	Vector <int> v3 = v1 + v2;

	EXPECT_EQ(3, v3.Length());
	for (int i = 0; i < v3.Length(); i++)
		EXPECT_EQ(0, v3[i]);

}


TEST(Vector, can_use_operator_minus_for_vectors)
{
	Vector <int> v1(3, 1);
	Vector <int> v2(3, -1);

	Vector <int> v3 = v1 - v2;

	EXPECT_EQ(3, v3.Length());
	for (int i = 0; i < v3.Length(); i++)
		EXPECT_EQ(2, v3[i]);

}

TEST(Vector, can_use_operator_multiplication_for_vectors)
{
	Vector <int> v1(4, 2);
	Vector <int> v2(3,  7);

	Vector <int> v3 = v1 * v2;

	EXPECT_EQ(3, v3.Length());
	for (int i = 0; i < v3.Length(); i++)
		EXPECT_EQ(14, v3[i]);
}

TEST(Vector, can_use_operator_division_for_vectors)
{
	Vector <double> v1(4, 5);
	Vector <double> v2(3, 2);

	Vector <double> v3 = v1 / v2;

	EXPECT_EQ(3, v3.Length());
	for (int i = 0; i < v3.Length(); i++)
		EXPECT_EQ(2.5, v3[i]);
}


TEST(Vector, can_use_operator_plus_plus_for_vectors)
{
	Vector<int> v1(5, 7);
	++v1;

	EXPECT_EQ(5, v1.Length());
	for (int i = 0; i < v1.Length(); i++)
		EXPECT_EQ(8, v1[i]);
}

TEST(Vector, can_use_operator_minus_minus_for_vectors)
{
	Vector<int> v1(5, 7);
	--v1;

	EXPECT_EQ(5, v1.Length());
	for (int i = 0; i < v1.Length(); i++)
		EXPECT_EQ(6, v1[i]);
}


TEST(Vector, can_use_operator_plus_equal_for_vectors)
{
	Vector<int> v1(5, 7);
	Vector<int> v2(4, 2);

	v1+=v2;

	EXPECT_EQ(4, v1.Length());
	for (int i = 0; i < v1.Length(); i++)
		EXPECT_EQ(9, v1[i]);
}


TEST(Vector, can_use_operator_minus_equal_for_vectors)
{
	Vector<int> v1(5, 7);
	Vector<int> v2(4, 2);

	v1 -= v2;

	EXPECT_EQ(4, v1.Length());
	for (int i = 0; i < v1.Length(); i++)
		EXPECT_EQ(5, v1[i]);
}

TEST(Vector, two_vectors_can_be_compare)
{
	Vector<int> v1(5, 7);
	Vector<int> v2(4, 2);

	Vector<int> v3(5, 7);
	Vector<int> v4(5, 7);

	EXPECT_TRUE(v3 == v4);
	EXPECT_FALSE(v1 == v2);
}

TEST(Vector, can_ReSize)
{
	Vector<int> v1(5, 7);
	Vector<int> v2(5, 7);
	v1.ReSize(4);
	v2.ReSize(7);

	EXPECT_EQ(4, v1.Length());
	for (int i = 0; i < v1.Length(); i++)
		EXPECT_EQ(7, v1[i]);

	EXPECT_EQ(7, v2.Length());
	for (int i = 0; i < 5; i++)
		EXPECT_EQ(7, v2[i]);
}