#include <stdlib.h>
#include "fdf.h"


int main(void)
{
    void	*mlx_ptr;

    mlx_ptr = mlx_init();
    // mlx_destroy_display(mlx_ptr);
    free(mlx_ptr);
}