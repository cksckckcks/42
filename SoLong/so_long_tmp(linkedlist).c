#include "so_long.h"

typedef struct s_data
{
	char			*line;
	struct s_data	*next;
}		t_data;

typedef struct s_map
{
	t_data	*head;
	t_data	*tail;
}		t_map;

t_map	*map_allocate(void)
{
	t_map	*ret;

	ret = (t_map*)malloc(sizeof(t_map));
	if (!ret)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	ret->head = NULL;
	ret->tail = NULL;
	return (ret);
}

void	free_map(t_map **map)
{
	t_data	*tmp;
	
	if ((*map)->head == NULL)
	{
		free((*map));
		return ;
	}
	tmp = (*map)->head;
	while (tmp)
	{
		tmp = tmp->next;
		free((*map)->head->line);
		free((*map)->head);
		(*map)->head = tmp;
	}
	free((*map));
}

void	add_map_data(t_map **map, char **data)
{
	t_data	*tmp;

	tmp = (t_data*)malloc(sizeof(t_data));
	if (!tmp)
	{
		free_map(map);
		write(1, "Error\n", 6);
		exit(1);
	}
	tmp->line = (*data);
	tmp->next = NULL;
	if ((*map)->head == NULL)
	{
		(*map)->head = tmp;
		(*map)->tail = tmp;
	}
	else 
	{
		(*map)->tail->next = tmp;
		(*map)->tail = tmp;
	}
}

int	input_file_check(char *name)
{
	int	i;

	i = 0;
	while (name[i] && name[i] != '.')
		i++;
	if (name[i + 1] == 'b' && name[i + 2] == 'e'\
		&& name[i + 3] == 'r' && name[i + 4] == '\0')
		return (1);
	return (0);
}

int	line_check(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != 'C'\
			&& str[i] != 'E' && str[i] != 'P')
			return (0);
		i++;
	}
	return (1);
}

int	line_length_check(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

t_map	*map_create(int fd)
{
	t_map	*ret;
	char	*str;
	int		line_length;

	ret = map_allocate();
	str = get_next_line(fd);
	if (str == NULL)
	{
		free_map(&ret);
		write(1, "Error\n", 6);
		exit(1);
	}
	line_length = line_length_check(str);
	while (str != NULL)
	{
		if (line_length != line_length_check(str) || !line_check(str))
		{
			free_map(&ret);
			write(1, "Map Error\n", 10);
			exit(1);
		}
		add_map_data(&ret, &str);
		str = get_next_line(fd);
	}
	return (ret);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_map	*map;

	if (argc != 2)
	{
		write(1, "./so_long filename.ber\n", 23);
		exit(1);
	}
	if (input_file_check(argv[1]) == 0)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	map = map_create(fd);
	free_map(&map);
}