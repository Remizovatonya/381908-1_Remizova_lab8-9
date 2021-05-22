#include "TStackList.h"
#include <fstream>
#include <../gtest/gtest.h>

TEST(TStackList, can_create_stack_list)
{
    ASSERT_NO_THROW(TStackList<int>());
}

TEST(TStackList, can_push_any_elements)
{
    TStackList<int> S;
    S.push(1);
    S.push(2);
    EXPECT_EQ(2, S.Get());
}

TEST(TStackList, can_pop_any_elements)
{
    TStackList<int> S;
    S.push(1);
    S.push(2);
    S.push(3);
    S.pop();
    S.pop();
    EXPECT_EQ(1, S.Get());
}

//äîï çàäàíèÿ

TEST(TStackList, can_find_max_element)
{
    TStackList<int> S;
    S.push(1);
    S.push(2);
    S.push(-1);
    EXPECT_EQ(2, S.GetMaxElem());
}

TEST(TStackList, can_find_min_element)
{
    TStackList<int> S;
    S.push(1);
    S.push(2);
    S.push(-1);
    EXPECT_EQ(-1, S.GetMinElem());
}

TEST(TStackList, can_write_stack_list_to_file)
{
    const int size = 9;
    TStackList<int> S;
    for (int i = 0; i < size / 2; i++)
        S.push(i);
    S.WriteToFile("output_s.txt");
    string expS = "0123";
    string Stack = "";
    ifstream fin("output_s.txt");
    fin >> Stack;
    fin.close();
    EXPECT_EQ(expS, Stack);
}
