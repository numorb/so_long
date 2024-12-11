#include "so_long.h"


int flood_filler(t_game *game, char ** flood_map, int x, int y)
{
    static int  collectables;
    static int  player;
    static int  exit;

    if (x >= 0 &&  x < game->map.size.width && y >= 0 && y < game->map.size.height)
    {
        if (game->map.mapping[y][x] == '1' || flood_map[y][x] == '1')
            return (0);
        if (game->map.mapping[y][x] == 'P')
            player++;
        if (game->map.mapping[y][x] == 'E')
            exit++;
        if (game->map.mapping[y][x] == 'C')
            collectables++;
        flood_map[y][x] = '1';
        if (flood_filler(game, flood_map, x, y - 1) ||
        flood_filler(game, flood_map, x - 1, y) ||
        flood_filler(game, flood_map, x, y + 1) ||
        flood_filler(game, flood_map, x + 1, y))
            return (1);
    }
    else
        return (1);
    if (collectables != game->character.collectables.count || exit != 1 || player != 1)
        return (1);
    return (0);
}

void    free_map(char **map, int size)
{
    int i;

    i = 0;
    while (i < size)
        free(map[i++]);
    free(map);
}

int    flood(t_game *game, int x, int y)
{
    char **flood_map;
    int i;

    i = 0;
    flood_map = malloc (sizeof(char *) * game->map.size.height);
    if (!flood_map)
        return (1);
    while (i < game->map.size.height)
        flood_map[i++] = ft_calloc (sizeof(char *), game->map.size.width);
    if (flood_filler (game, flood_map, x, y))
    {
        free_map(flood_map, game->map.size.height);
        ft_printf("Error\n");
        return (1);
    }
    free_map(flood_map, game->map.size.height);
    return (0);
}