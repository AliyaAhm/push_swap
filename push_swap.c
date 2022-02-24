/*#include "push_swap.h"

int    main(int argc, char **argv)
{
    t_strct *swap_strct;
    
    if (argc != 1)
    {
        swap_strct = (t_strct *)malloc(sizeof(t_strct));
        if (!swap_strct)
            return (0);
        init_struct(swap_strct);
        if (read_arr(argc, argv, swap_strct))
            if (check_seq(swap_strct->begin_stack_a))
                ft_process(swap_strct);
        stack_clear(swap_strct->begin_stack_a);
        stack_clear(swap_strct->begin_stack_b);
        free (swap_strct);
    }
    return (0);
}
*/