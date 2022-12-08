

# include <string.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

# include <stdlib.h>
#include "push.h"


void printi(int *tab,int *tab_b,int size,int indexa);
int	planarrays(int ac, char **av, t_arays *info,int anyfunc);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putstr_fd(char *s, int fd);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);

void doit(char *order,t_arays *info)
{
    if(ft_strlen(order)==3 && !ft_strncmp(order,"rra",3))
        rra(info->tab_a, info->f_e, info->x_a);
    if(ft_strlen(order)==3 && !ft_strncmp(order,"rrb",3))
        rrb(info->tab_b, info->f_e, info->x_a);
    if(ft_strlen(order)==3 && !ft_strncmp(order,"rrr",3))
        rrr(info->tab_a, info->tab_b, info->f_e, info->x_a);
    if(ft_strlen(order)==2 && !ft_strncmp(order,"pb",2))
        pb(info);
    if(ft_strlen(order)==2 && !ft_strncmp(order,"pa",2))
        pa(info);
    if(ft_strlen(order)==2 && !ft_strncmp(order,"ra",2))
        ra(info->tab_a, info->f_e, info->x_a);
    if(ft_strlen(order)==2 && !ft_strncmp(order,"rb",2))
        rb(info->tab_b, info->f_e, info->x_a);
    if(ft_strlen(order)==2 && !ft_strncmp(order,"rr",2))
        rr(info->tab_a, info->tab_b, info->f_e, info->x_a);
    if(ft_strlen(order)==2 && !ft_strncmp(order,"sa",2))
        sa(info);
    if(ft_strlen(order)==2 && !ft_strncmp(order,"sb",2))
        sb(info);
    if(ft_strlen(order)==2 && !ft_strncmp(order,"ss",2))
        ss(info);
    order[0]=0;
}

void    check_sort(t_arays info)
{
    int i;
    if(info.f_e!=info.x_a+1)
        {
            printf("KO");
            return;
        }

    i=0;
    while(i<info.x_a-1)
    {
        if(info.tab_a[i]<info.tab_a[i+1])
        {
            printf("KO");
            return;
        }
        i++;
    }
    printf("OK");
}

int main(int ac, char *av[])
{
	t_arays	info;

    char dd[50];
    char *order;
    order=strdup("");
    if (!planarrays(ac, av, &info,2))
		return (0);
    while(read(0, dd, 1)){
        dd[1]=0;
        
        if(dd[0]=='\n')
            doit(order,&info);
        else
            order=ft_strjoin(order,dd);
    }
    check_sort(info);
    return 0;
}
