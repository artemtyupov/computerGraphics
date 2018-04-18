#pragma once

#include <iostream>
#include <cmath>

#define ALPH "qwertyuiopasdfghjklzxcvbnméöóêåíãøùçõúôûâàïğîëäæıÿ÷ñìèòüáş\/|?!@#$%^&*()¹;:*=¸`~"
#define PI 3.141592

using namespace System;
using namespace System::Windows::Forms;


struct cord
{
	double x;
	double y;
	cord *next;
};

struct treangle
{
	cord *first;
	cord *second;
	cord *third;
	double len_a, len_b, len_c;
	double len_median, len_height;
	double angle;
	cord *V;
	treangle *next;
};



void change_table(DataGridView^ table, cord *head);
cord* add(cord *head, String^ x, String^ y);
cord* remove_one(cord *head, cord *to_remove);
void remove_all(cord *head);
void change(cord *head, cord *to_change, double new_x, double new_y);
cord *find_for_cord(cord *head, double x, double y);
double find_len(cord *first, cord *second);
int check_treangle(cord *ptr1, cord *ptr2, cord *ptr3);
treangle *create_treangle(cord *ptr1, cord *ptr2, cord *ptr3);
treangle *make_treangles(cord *head);
double take_one_angle(treangle *ptr, cord *first, cord *second, cord *third);
double find_angle(treangle *ptr);
treangle *find_min_angle(treangle *head);
cord* add_double(cord *head, double x, double y, double xrmv, double yrmv);
int count_list(cord *head);
treangle *delete_smooth(treangle *head);