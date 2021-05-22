#include "TQueueList.h"
#include <fstream>
#include <../gtest/gtest.h>

TEST(TQueueList, can_create_queue_list)
{
    ASSERT_NO_THROW(TQueueList<int>());
}

TEST(TQueueList, can_push_any_elements)
{
    TQueueList<int> Q;
    Q.push(1);
    Q.push(2);
    EXPECT_EQ(1, Q.Get());
}

TEST(TQueueList, can_pop_any_elements)
{
    TQueueList<int> Q;
    Q.push(1);
    Q.push(2);
    Q.push(3);
    Q.push(4);
    Q.pop();
    Q.pop();
    Q.push(5);
    Q.pop();
    EXPECT_EQ(4, Q.Get());
}


TEST(TQueueList, can_find_max_element)
{
    TQueueList<int> Q;
    Q.push(1);
    Q.push(2);
    Q.push(-1);
    EXPECT_EQ(2, Q.GetMaxElem());
}

TEST(TQueueList, can_find_min_element)
{
    TQueueList<int> Q;
    Q.push(1);
    Q.push(2);
    Q.push(-1);
    EXPECT_EQ(-1, Q.GetMinElem());
}

TEST(TQueueList, can_write_queue_list_to_file)
{
    const int size = 9;
    TQueueList<int> Q;
    for (int i = 0; i < size / 2; i++)
        Q.push(i);
    Q.WriteToFile("output_q.txt");
    string expS = "0123";
    string Queue = "";
    ifstream fin("output_q.txt");
    fin >> Queue;
    fin.close();
    EXPECT_EQ(expS, Queue);
}