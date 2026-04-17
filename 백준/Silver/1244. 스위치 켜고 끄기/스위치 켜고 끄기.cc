#include <iostream>
#include <cstring>

enum e_gender
{
	BOY = 1,
	GIRL
};

typedef struct
{
	int	gender;
	int	switch_num;
}	t_person;

// 남
//		스위치 번호가 자기가 받은 수의 배수 -> 스위치 상태 바꾸기
// 여
//		스위치 번호를 기준으로 좌우가 대칭이면서 가장 많은 스위치를 포함하는 구간을 찾아서, 그 구간에 속한 스위치 모두 바꾸기

void	change_switch(int *_switch, int size, t_person &student)
{
	int	i;
	int	left, right;

	if (student.gender == BOY)
	{
		for (i = 1; i <= size; ++i)
			if (i % student.switch_num == 0)
				_switch[i] = !_switch[i];
	}
	else
	{
		_switch[student.switch_num] = !_switch[student.switch_num];
		left = student.switch_num - 1;
		right = student.switch_num + 1;
		while (left >= 0 && right <= size)
		{
			if (_switch[left] == _switch[right])
			{
				_switch[left] = !_switch[left];
				_switch[right] = !_switch[right];
			}
			else
				break ;
			--left;
			++right;
		}
	}
}

int	main(void)
{
	t_person	student;
	int			_switch[101];
	int			i, switch_size, student_size;

	scanf(" %d", &switch_size);
	for (i = 1; i <= switch_size; ++i)
		scanf(" %d", &_switch[i]);
	scanf(" %d", &student_size);
	for (i = 0; i < student_size; ++i)
	{
		scanf(" %d %d", &student.gender, &student.switch_num);
		change_switch(_switch, switch_size, student);
	}
	for (i = 1; i <= switch_size; ++i)
	{
		printf("%d ", _switch[i]);
		if (i != 0 && i % 20 == 0)
			printf("\n");
	}
	return (0);
}
