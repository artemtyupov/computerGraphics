#include "funcs.h"
#include <stdlib.h>
#include<vcclr.h>

void AddRecordToTable(cord* ptr, DataGridView^ table, int num)
{
	table->Rows->Insert(num,
		String::Format("{0:0.0###}", ptr->x),
		String::Format("{0:0.0###}", ptr->y));
}

void change_table(DataGridView^ table, cord* head)
{
	table->Rows->Clear();
	cord *ptr = head;
	int pos = 0;
	for (; ptr; ptr = ptr->next)
	{
		AddRecordToTable(ptr, table, pos++);
	}
}

cord* add(cord *head, String^ x, String^ y)
{

	String ^alph = ALPH;
	array<Char>^anyOf = alph->ToCharArray();
	if (x->LastIndexOfAny(anyOf) != -1 || y->LastIndexOfAny(anyOf) != -1)
	{
		MessageBox::Show("Введите цифры");
		return nullptr;
	}
	else
	{
		x = x->Replace('.',',');
		y = y->Replace('.',',');
		double dbl_x = Convert::ToDouble(x);
		double dbl_y = Convert::ToDouble(y);
		cord *check = find_for_cord(head, dbl_x, dbl_y);
		if (check == nullptr)
		{
			cord *ptr = new cord;
			ptr->x = dbl_x;
			ptr->y = dbl_y;
			if (head == nullptr)
			{
				head = ptr;
				head->next = nullptr;
				return head;
			}
			else 
			{
				ptr->next = head;
			}
			return ptr;
		}
		else
		{
			MessageBox::Show("Такая точка уже существует");
			return head;
		}
	}
}

cord* add_double(cord *head, double x, double y, double xrmv, double yrmv)
{
	cord *ptr = new cord;
	ptr->x = x;
	ptr->y = y;
	cord *check = find_for_cord(head, x, y);
	if (check == nullptr)
	{
		if (head == nullptr)
		{
			head = ptr;
			head->next = nullptr;
			return head;
		}
		else 
		{
			ptr->next = head;
		}
		return ptr;
	}
	else
	{
		head = add_double(head, xrmv, yrmv, 0, 0);
		MessageBox::Show("Такая точка уже существует");
		return head;
	}
}

cord* remove_one(cord *head, cord *to_remove)
{
	cord *ptr = head->next;
	cord *ptr_sec;
	int cnt = count_list(head);
	if (head == to_remove && cnt == 1)
	{
		head = nullptr;
		return head;
	}
	if (head == to_remove)
	{
		ptr = head->next;
		free(head);
		return ptr;
	}
	if (ptr == to_remove)
	{
		head->next = head->next->next;
		free(ptr);
		return head;

	}
	while (ptr->next)
	{	
		if (ptr->next == to_remove)
		{
			ptr_sec = ptr->next;
			ptr->next = ptr->next->next;
			free(ptr_sec);
			return head;
		}
		ptr = ptr->next;
	}
	return head;
}

void remove_all(cord *head)
{
	if (!head)
		return;
	cord *ptr = head;
	for (; ptr; ptr = ptr->next)
	{
		if (!ptr->next)
			remove_one(ptr, ptr);
		cord *ptr_next = ptr->next;
		free(ptr);
		ptr = ptr_next;
	}
}

void change(cord *head, cord *to_change, double new_x, double new_y)
{
	cord *ptr = head;
	for (; ptr; ptr = ptr->next)
	{	
		if (ptr == to_change)
		{
			ptr->x = new_x;
			ptr->y = new_y;
		}
	}
}

cord *find_for_cord(cord *head, double x, double y)
{
	cord *ptr = head;
	for (; ptr; ptr = ptr->next)
	{	
		if ((ptr->x == x) && (ptr->y == y))
		{
			return ptr;
		}
	}
	return NULL;
}

int count_list(cord *head)
{
	int result = 0;
	for (cord *ptr = head; ptr; ptr = ptr->next)
	{
		result++;
	}
	return result;
}

double find_len(cord *first, cord *second)
{
	return sqrt(pow(abs(first->x - second->x), 2) + pow(abs(first->y - second->y), 2));
}

int check_treangle(cord *ptr1, cord *ptr2, cord *ptr3)
{
	double len1 = find_len(ptr1, ptr2);
	double len2 = find_len(ptr2, ptr3);
	double len3 = find_len(ptr3, ptr1);
	if ((len1 + len2 > len3 && len2 + len3 > len1 && len3 + len1 > len2) 
		&& ((ptr1->x - ptr3->x) * (ptr2->y - ptr3->y) - (ptr2->x - ptr3->x) * (ptr1->y - ptr3->y) != 0))
		return 0;
	else return -1;
}

treangle *create_treangle(cord *ptr1, cord *ptr2, cord *ptr3)
{
	treangle *ptr = new treangle;
	ptr->first = ptr1;
	ptr->second = ptr2;
	ptr->third = ptr3;
	ptr->next = NULL;
	return ptr;
}

treangle *make_treangles(cord *head)
{
	cord *ptr1, *ptr2, *ptr3;
	treangle *head_tr = NULL, *ptr;
	for (ptr1 = head; ptr1; ptr1 = ptr1->next)
	{
		for (ptr2 = head; ptr2; ptr2 = ptr2->next)
		{
			for (ptr3 = head; ptr3; ptr3 = ptr3->next)
			{
				if (check_treangle(ptr1, ptr2, ptr3) == 0)
				{
					ptr = create_treangle(ptr1, ptr2, ptr3);
					if ((head_tr) == NULL)
					{
						head_tr = ptr;
					}
					else
					{
						ptr->next = head_tr;
						head_tr = ptr;
					}
				}
			}
		}
	}
	return head_tr;
}

int compare_cords(treangle *ptr1, treangle *ptr2)
{
	//1 = 1, 2 = 2, 3 = 3
	if (ptr1->first == ptr2->first && ptr1->second == ptr2->second && ptr1->third == ptr2->third)
		return 0;

	//1 = 2, 2 = 3, 3 = 1
	if (ptr1->first == ptr2->second && ptr1->second == ptr2->third && ptr1->third == ptr2->first)
		return 0;

	//1 = 3, 2 = 2, 3 = 1
	if (ptr1->first == ptr2->third && ptr1->second == ptr2->second && ptr1->third == ptr2->first)
		return 0;

	//1 = 1, 2 = 3, 3 = 2
	if (ptr1->first == ptr2->first && ptr1->second == ptr2->third && ptr1->third == ptr2->second)
		return 0;

	//1 = 2, 2 = 1, 3 = 3
	if (ptr1->first == ptr2->second && ptr1->second == ptr2->first && ptr1->third == ptr2->third)
		return 0;

	//1 = 3, 2 = 1, 3 = 2
	if (ptr1->first == ptr2->third && ptr1->second == ptr2->first && ptr1->third == ptr2->second)
		return 0;

	//1 = 1, 2 = 2, 3 = 3
	if (ptr1->first == ptr2->first && ptr1->second == ptr2->second && ptr1->third == ptr2->third)
		return 0;
	return -1;
}

treangle *delete_smooth(treangle *head)
{
	treangle *ptr = head;
	treangle *ptr_next;
	for (; ptr; ptr = ptr->next)
	{
		ptr_next = ptr->next;
		if (!ptr->next)
			break;
		if (compare_cords(ptr, ptr->next) == 0)
		{
			ptr_next = ptr->next;
			ptr->next = ptr->next->next;
			ptr = ptr->next;
			free(ptr_next);
		}

	}
	return head;
}

double take_one_angle(treangle *ptr, cord *first, cord *second, cord *third)
{
	double a = find_len(first, second);
	double b = find_len(second, third); // cord second - вершина
	if (a == b)
	{
		return PI;
	}
	double c = find_len(third, first); //медиана и высота падают на c
	ptr->len_a = a; ptr->len_b = b; ptr->len_c = c;
	double median = (0.5) * sqrt(2 * pow(a, 2) + 2 * pow(b, 2) - c);
	ptr->len_median = median;
	double p = (a + b + c) / 2;
	double S = sqrt(p * (p - a) * (p - b) * (p - c));
	double height = S * 2 / c;
	ptr->len_height = height;
	double ost = sqrt(pow(median, 2) - pow(height, 2)); //3 сторона в треугольнике с высотой и медианой
	double p_ost = (median + height + ost) / 2;
	double S_ost = sqrt(p_ost * (p_ost - ost) * (p_ost - median) * (p_ost - height));
	double result = asin(2 * S_ost / (height * median));
	return result;
}

double find_angle(treangle *ptr)
{
	double angle1 = take_one_angle(ptr, ptr->first, ptr->second, ptr->third);
	double angle2 = take_one_angle(ptr, ptr->second, ptr->third, ptr->first);
	double angle3 = take_one_angle(ptr, ptr->third, ptr->first, ptr->second);
	if (angle1 <= angle2 && angle1 <= angle3)
	{
		ptr->V = ptr->second;
		return angle1;
	}
	if (angle2 <= angle1 && angle2 <= angle3)
	{
		ptr->V = ptr->third;
		return angle2;
	}
	ptr->V = ptr->first;
	return angle3;
}

treangle *find_min_angle(treangle *head)
{
	treangle *ptr = head, *result;
	double min = PI;
	for (; ptr; ptr = ptr->next)
	{
		double angle = find_angle(ptr);
		ptr->angle = angle;
		if (angle <= min)
		{
			min = angle;
			result = ptr;
		} 
	}
	return result;
}

