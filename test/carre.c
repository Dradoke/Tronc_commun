#include <stdlib.h>
#include "../include/fdf.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y*data->line_length + x * (data->bits_per_pixel / 8));
    (*(unsigned int*)dst = color);
}

int main(void)
{
    void    *mlx;
    void    *mlx_win;
    t_data    img;
    int y;
    int x;
    int size;

    y = 0;
    x = 0;
    size = 300;
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Test");
    img.img = mlx_new_image(mlx, 1920,1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                &img.endian);
    my_mlx_pixel_put(&img, (0), (0), 0x00FF0000); //red
    while (x < size && y < size)
    {
        my_mlx_pixel_put(&img, (x + 1), (0), 0x00FF0000); //red
        my_mlx_pixel_put(&img, (0), (y + 1), 0x00FF0000); //red
        x++;
        y++;
    }
    my_mlx_pixel_put(&img, (size), (size), 0x00FF0000); //red
    while (x > 0 && y > 0)
    {
        my_mlx_pixel_put(&img, (x - 1), (size), 0x00FF0000); //red
        my_mlx_pixel_put(&img, (size), (y - 1), 0x00FF0000); //red
        y--;
        x--;
    }
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}
