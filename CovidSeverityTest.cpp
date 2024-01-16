#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "CovidSeverity.h"

class CovidSeverityTest : public testing::Test {

};

TEST_F(CovidSeverityTest, Test1)
{
	int n1 = 10;
    int a1_temp[7][2] = {{1, 2}, {1, 3}, {2, 4}, {4, 6}, {2, 8}, {6, 9}, {7, 10}};
    int** a1 = (int**)malloc(7*sizeof(int*));
    for(int i = 0; i < 7; i++) {
        a1[i] = a1_temp[i];
    }
	int b1[3] = {3, 8, 5};
	arr_int actual = covidSeverity(n1, a1, b1, 7, 3);
    int expected_temp[] = {35, 10, 0};

    arr_int expected;
    expected.size = 3;
    expected.arr = (int*) malloc((expected.size)*sizeof(int));
    for(int i = 0; i < expected.size; i++) {
        expected.arr[i] = expected_temp[i];
    }


    ASSERT_EQ(expected.size, actual.size);
    for(int i = 0; i < expected.size; i++) {
        EXPECT_EQ(expected.arr[i], actual.arr[i]);
    }
}

TEST_F(CovidSeverityTest, Test2)
{
    int n1 = 10;
    int a1_temp[5][2] = {{10,7},{3,6},{2,10},{5,6},{10,8}};
    int** a1 = (int**)malloc(5*sizeof(int*));
    for(int i = 0; i < 5; i++) {
        a1[i] = a1_temp[i];
    }
    int b1[4] = {4,9,2,8};
    arr_int actual = covidSeverity(n1, a1, b1, 5, 4);
    int expected_temp[] = {28, 10, 10, 0, 0};

    arr_int expected;
    expected.size = 5;
    expected.arr = (int*) malloc((expected.size)*sizeof(int));
    for(int i = 0; i < expected.size; i++) {
        expected.arr[i] = expected_temp[i];
    }

    ASSERT_EQ(expected.size, actual.size);
    for(int i = 0; i < expected.size; i++) {
        EXPECT_EQ(expected.arr[i], actual.arr[i]);
    }
}

TEST_F(CovidSeverityTest, Test3)
{
    int n1 = 10;
    int a1_temp[5][2] = {{9,4},{6,7},{2,8},{3,10},{8,10}};
    int** a1 = (int**)malloc(5*sizeof(int*));
    for(int i = 0; i < 5; i++) {
        a1[i] = a1_temp[i];
    }
    int b1[4] = {5,3,7,2};
    arr_int actual = covidSeverity(n1, a1, b1, 5, 4);
    int expected_temp[] = {30, 15, 10, 0, 0};

    arr_int expected;
    expected.size = 5;
    expected.arr = (int*) malloc((expected.size)*sizeof(int));
    for(int i = 0; i < expected.size; i++) {
        expected.arr[i] = expected_temp[i];
    }

    ASSERT_EQ(expected.size, actual.size);
    for(int i = 0; i < expected.size; i++) {
        EXPECT_EQ(expected.arr[i], actual.arr[i]);
    }
}

TEST_F(CovidSeverityTest, Test4)
{
    int n1 = 6;
    int a1_temp[4][2] = {{1,5},{2,5},{1,4},{4,6}};
    int** a1 = (int**)malloc(4*sizeof(int*));
    for(int i = 0; i < 4; i++) {
        a1[i] = a1_temp[i];
    }
    int b1[3] = {2,6,5};
    arr_int actual = covidSeverity(n1, a1, b1, 4, 3);
    int expected_temp[] = {40, 0};

    arr_int expected;
    expected.size = 2;
    expected.arr = (int*) malloc((expected.size)*sizeof(int));
    for(int i = 0; i < expected.size; i++) {
        expected.arr[i] = expected_temp[i];
    }

    ASSERT_EQ(expected.size, actual.size);
    for(int i = 0; i < expected.size; i++) {
        EXPECT_EQ(expected.arr[i], actual.arr[i]);
    }
}

TEST_F(CovidSeverityTest, Test5)
{
    int n1 = 6;
    int a1_temp[5][2] = {{1,6},{5,1},{6,4},{4,3},{5,3}};
    int** a1 = (int**)malloc(5*sizeof(int*));
    for(int i = 0; i < 5; i++) {
        a1[i] = a1_temp[i];
    }
    int b1[2] = {4,3};
    arr_int actual = covidSeverity(n1, a1, b1, 5, 2);
    int expected_temp[] = {33, 0};

    arr_int expected;
    expected.size = 2;
    expected.arr = (int*) malloc((expected.size)*sizeof(int));
    for(int i = 0; i < expected.size; i++) {
        expected.arr[i] = expected_temp[i];
    }

    ASSERT_EQ(expected.size, actual.size);
    for(int i = 0; i < expected.size; i++) {
        EXPECT_EQ(expected.arr[i], actual.arr[i]);
    }
}
