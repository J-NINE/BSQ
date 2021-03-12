#include "stdbsq.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	if (!dst || !src)
		return (0);
	if (size > 0)
	{
		while (--size && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

  static char			**ft_malloc_error(char **tab)
    {
    	unsigned int	i;
    
    	i = 0;
    	while (tab[i])
    	{
    		free(tab[i]);
    		i++;
    	}
    	free(tab);
    	return (NULL);
    }
    
    static unsigned int	ft_get_nb_strs(char const *s, char c)
    {
    	unsigned int	i;
    	unsigned int	nb_strs;
    
    	if (!s[0])
    		return (0);
    	i = 0;
    	nb_strs = 0;
    	while (s[i] && s[i] == c) //c가 제일 앞에, 여러 개 연속으로 있을 때 패스
    		i++;
    	while (s[i])
    	{
    		if (s[i] == c)
    		{
    			nb_strs++;
    			while (s[i] && s[i] == c)
    				i++;
    			continue ;
    		}
    		i++;
    	}
    	if (s[i - 1] != c)
    		nb_strs++; //마지막이 c로 안 끝났으면 +1
    	return (nb_strs);
    }
    
    static void			ft_get_next_str(char **next_str, unsigned int *next_str_len,
    					char c)
    {
    	unsigned int i;
    
    	*next_str += *next_str_len; //실제 next_str 주소 ++
    	*next_str_len = 0;
    	i = 0;
    	while (**next_str && **next_str == c)
    		(*next_str)++;
    	while ((*next_str)[i]) //갯수 샐 때는 지역변수 i 이용
    	{
    		if ((*next_str)[i] == c)
    			return ;
    		(*next_str_len)++;
    		i++;
    	}
    }
    
    char				**ft_split(char const *s, char c, t_map *map)
    {
    	char			**tab;
    	char			*next_str;
    	unsigned int	next_str_len;
      unsigned int prev_str_len;
    	unsigned int	nb_strs;
    	unsigned int	i;
    
    	if (!s)
    		return (NULL);
    	nb_strs = ft_get_nb_strs(s, c);
      //row 검사
      if (nb_strs != map->row)
        return (NULL);
    	if (!(tab = (char **)malloc(sizeof(char *) * (nb_strs + 1))))
        return (ft_malloc_error(tab));
    	i = 0;
    	next_str = (char *)s;
    	next_str_len = 0;
    	while (i < nb_strs)
    	{
    		ft_get_next_str(&next_str, &next_str_len, c);
        //각 행의 길이가 같은지 확인 
        if (i == 0)
          prev_str_len = next_str_len;
        else
          if (prev_str_len != next_str_len)
            return (NULL);   		
        if (!(tab[i] = (char *)malloc(sizeof(char) * (next_str_len + 1))))
    			return (ft_malloc_error(tab));
    		ft_strlcpy(tab[i], next_str, next_str_len + 1);
    		i++;
    	}
    	tab[i] = NULL;
    	return (tab);
    }
    
int ft_strlen(char *str)
{
  int i;
  i = 0;
  while (str[i])
    i++;
  return (i);
}