#include	"../includes/ohmylib.h"

#ifndef _WIN32
void	print_welcome()
{
	char LOADING[] = "\n\n\
                █   █▀█ ▄▀█ █▀▄ █ █▄ █ █▀▀\n\
                █▄▄ █▄█ █▀█ █▄▀ █ █ ▀█ █▄█ ▄ ▄ ▄\n\n\n";
	char GPA_CALCULATOR[] = "\n\n\
      █▀▀ █▀█ ▄▀█  █▀▀ ▄▀█ █   █▀▀ █ █ █   ▄▀█ ▀█▀ █▀█ █▀█\n\
      █▄█ █▀▀ █▀█  █▄▄ █▀█ █▄▄ █▄▄ █▄█ █▄▄ █▀█  █  █▄█ █▀▄\n\n\n";

	clear();
	print_color(LOADING, 214);
	system("sleep 0.6");
	clear();
	print_color(GPA_CALCULATOR, 162);
}
#else
void print_welcome()
{
	print_header("GPA CALCULATOR");
}
#endif

void	reset_data(t_student_data *data)
{
	bzero(data->student_id, 11);
	for (size_t i = 0; i < 10; i++)
	{
		bzero(data->subject[i], 31);
		data->grade[i] = 0;
		data->credit[i] = 0;
	}
}

int	is_dup(char *subject_name,t_student_data data)
{
	for (size_t i = 0; i < 10 && *data.subject[i]; i++)
		if (!strcmp(subject_name, data.subject[i]))
			return (1);
	return (0);
}


void	assign_grade(t_avg_data *dest, t_student_data src)
{
	size_t	i;
	float	total;
	float	credit;

	credit = 0;
	total = 0;
	i = 0;
	while (i < 10 && src.subject[i][0] != 0)
	{
		total += (src.grade[i] * src.credit[i]);
		credit += src.credit[i];
		i++;
	}
	strcpy(dest->student_id, src.student_id);
	dest->grade = total / credit;
	dest->credit = credit;
}
