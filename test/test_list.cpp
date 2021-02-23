#include "list.h"
#include <gtest.h>

TEST(Tlist, can_create_list)
{
	ASSERT_NO_THROW(List<int> list);
}

TEST(Tlist, can_copy_list)
{
	List<int> list1;
	ASSERT_NO_THROW(List<int> list2(list1));
}

TEST(Tlist, can_get_true_size)
{
	List<int> list;
	int first = 1;
	int second = 2;
	list.Insert_at_First(first);
	list.Insert_at_First(second);
	EXPECT_EQ(list.get_size(), 2);
	ASSERT_NO_THROW(list.get_size());
}

TEST(Tlist, check_empty) {
	List<int> list;
	list.Insert_at_First(1);
	EXPECT_EQ(list.empty(), false);
}

TEST(Tlist, check_empty1) {
	List<int> list;
	EXPECT_EQ(list.empty(), true);
}

TEST(Tlist, can_insert_first_element) {
	List<int> list;
	int num = 2;
	ASSERT_NO_THROW(list.Insert_at_First(num));
}

TEST(Tlist, can_insert_element) {
	List<int> list;
	int num1 = 1, num2 = 2, num3 = 3;
	list.Insert_at_First(num1);
	list.Insert_at_First(num2);
	List<int>::iterator it(list.get_first());
	++it;
	ASSERT_NO_THROW(list.Insert(*it, num3));
}

TEST(Tlist, can_delete_first_element) {
	List<int> list;
	list.Insert_at_First(7);
	ASSERT_NO_THROW(list.DeleteFirst());
	EXPECT_EQ(list.get_size(), 0);
}

TEST(Tlist, can_delete_node) {
	List<int> list;
	List<int>::iterator it = list.begin();
	int num = 3;
	list.Insert_at_First(1);
	list.Insert_at_First(2);
	list.Print();
	ASSERT_NO_THROW(list.Delete(*it));
	list.Print();
}

TEST(Tlist, can_search_node) {
	List<int> list;
	int num1 = 1, num2 = 2, num3 = 3;
	list.Insert_at_First(num1);
	list.Insert_at_First(num2);
	list.Insert_at_First(num3);
	List<int>::iterator iter1(list.get_first());
	++iter1;
	EXPECT_EQ(iter1, list.Search(num2));
}

TEST(Iterator, can_create) {
	ASSERT_NO_THROW(List<int>::iterator iter);
}

TEST(Iterator, can_copy) {
	List<int>::iterator iter2;
	ASSERT_NO_THROW(List<int>::iterator iter1(iter2));
}

TEST(Iterator, operator_plus_plus_is_correct)
{
	List<int> list;
	list.Insert_at_First(1);
	list.Insert_at_First(2);
	list.Insert_at_First(3);
	list.Print();
	List<int>::iterator iter1(list.get_first());
	++iter1;
	EXPECT_EQ(iter1->data, 2);
	List<int>::iterator iter2(iter1++);
	EXPECT_EQ(iter2->data, 2);
	EXPECT_EQ(iter1->data, 1);
}

TEST(Iterator, operator_equal_is_correct)
{
	List<int> list;
	list.Insert_at_First(1);
	list.Insert_at_First(2);
	list.Insert_at_First(3);
	List<int>::iterator iter1(list.get_first());
	++iter1;
	List<int>::iterator iter2(iter1);
	EXPECT_EQ(iter2 == iter1, true);
}

TEST(Iterator, operator_not_equal_is_correct)
{
	List<int> list;
	list.Insert_at_First(1);
	list.Insert_at_First(2);
	list.Insert_at_First(3);
	List<int>::iterator iter1(list.get_first());
	++iter1;
	List<int>::iterator iter2(iter1++);
	EXPECT_EQ(iter2 != iter1, true);
}