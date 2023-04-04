#include "cube3d.h"

void	player_turn(char **map, t_data *data, int x, int y)
{
	if (data->posX != 0)
		ft_say(3, "To many players", data);
	data->posX = x + 0.5;
	data->posY = y + 0.5;
	data->dirX = 1;
	data->dirY = 0;
	if (map[y][x] == 'N')
		data->n_pvrt = 30;
	else if (map[y][x] == 'W')
		data->n_pvrt = 20;
	else if (map[y][x] == 'S')
		data->n_pvrt = 10;
	else
		data->n_pvrt = 0;
}

void	chek_map(char **map, int x, int y, t_data *data)
{
	if (ft_strchr(" 012NSWE", map[y][x]) == NULL)
		ft_say(3, "Bad map character", data);
	if (map[y][x] == ' ' || map[y][x] == '1')
		return ;
	if (map[y - 1][x] == ' ' || map[y + 1][x] == ' '
			|| map[y][x - 1] == ' ' || map[y][x + 1] == ' ')
		ft_say(3, "Bad map *\\ _ /*", data);
	else if (x == 0 || x == (int)data->map.size_x - 1 || y == 0
		|| y == (int)data->map.size_y - 1)
		ft_say(3, "Bad map *\\ _ /*", data);
	else if (map[y][x] == '0' || map[y][x] == '2')
		return ;
	else if (strchr("ESWN", map[y][x]))
	{
		player_turn(map, data, x, y);
		data->map.karta[y][x] = '0';
	}
}

int	rewd(int as, char **av, int id, t_data *data)
{
	if (close(id) == -1)
		ft_say(3, "Cant close id", data);
	if (as == 3)
	{
		if (ft_strncmp("--save", *(av + 1), 7) == 0)
			return (1);
		else
			ft_say(2, "Wrong flag", data);
	}
	return (0);
}

int	smol_chek(int status, char **len, t_data *data, int i)
{
	if (i == 1)
	{
		if (status == 1 && !len)
			ft_say(3, "Nothing there", data);
		if (**len == 'R')
			return (1);
	}
	else
	{
		if (status >= 4)
			ft_say(2, "To many statuses", data);
		else if (status == 1)
			ft_say(2, "To few statuses", data);
	}
	return (0);
}

int	is_map_empty(unsigned int ln_len, char *len, t_data *data)
{
	if (data->map.karta[0] == NULL)
		ft_say(4, "Map rows (MAF)", data);
	if (data->map.size_x < ln_len)
		data->map.size_x = ln_len;
	data->map.size_y++;
	return (ft_strlen(len));
}
