#include <stdio.h>
#include <stdint.h>
#define NUM_FLAG_HOLDERS 2
#define SIZE_FLAG_HOLDERS 32
uint32_t flags_holder[NUM_FLAG_HOLDERS];	//32x2=64 flags total

enum flag_types
{
	flag1,
	flag2,
	flag3,
	flag4,
	flag5,
	flag6,
	flag7,
	flag8,
	flag9,
	flag10,
	flag11,
	flag12,
	flag13,
	flag14,
	flag29 = 28,
	flag30,
	flag31,
	flag32,
	flag33,
	flag60 = 59,
	number_of_flags
};
void set_flag(enum flag_types flag)
{
	if (flag <= 31)
		flags_holder[0] |= ((uint32_t) 1 << flag);
	else if (flag <= 63)
	{
		flag -= 31;
		flags_holder[1] |= ((uint32_t) 1 << flag);
	}
}
void clear_flag(enum flag_types flag)
{
	if (flag <= 31)
		flags_holder[0] &= ~((uint32_t) 1 << flag);
	else if (flag <= 63)
	{
		flag -= 31;
		flags_holder[1] &= ~((uint32_t) 1 << flag);
	}
}
_Bool get_flag(enum flag_types flag)
{
	if (flag <= 31)
		return flags_holder[0] &((uint32_t) 1 << flag);
	else if (flag <= 63)
	{
		flag -= 31;
		return flags_holder[1] &((uint32_t) 1 << flag);
	}
	return 0;
}
void print_flags(void)
{
	printf("**************Printing All HIGH Flags *******************\n");
	printf("flags holder 0: 0x%08X\n", flags_holder[0]);
	printf("flags holder 1: 0x%08X\n", flags_holder[1]);
	printf("*********************************************************\n");
	printf("Individual HIGH flags:\n");
	for (uint16_t flagCounter = 1; flagCounter <= number_of_flags; flagCounter++)
	{
		if (get_flag(flagCounter))
		{
			printf("flag%d \n", flagCounter + 1);
		}
	}
	printf("*********************************************************\n");
}
int main()
{
	printf("total number of flags=%d\n", number_of_flags);
	set_flag(flag2);
	set_flag(flag12);
	set_flag(flag33);
	set_flag(flag60);
	print_flags();
	printf("*********************************************************\n");
	get_flag(flag14) ? printf("flag14 is HIGH\n") : printf("flag14 is LOW\n");
	get_flag(flag60) ? printf("flag60 is HIGH\n") : printf("flag60 is LOW\n");
	printf("*********************************************************\n");
	printf("Now try to clear flag60\n");
	clear_flag(flag60);
	get_flag(flag60) ? printf("flag60 is HIGH\n") : printf("flag60 is LOW\n");
	return 0;
}
