/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 14:27:14 by wtalea            #+#    #+#             */
/*   Updated: 2019/09/29 13:22:32 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <sys/param.h>
#include <errno.h>
#include "libft.h"
#include "ft_test.h"

#define NUM 0
#define CUTOFF 1
#define CUTLIM 2
#define NEG 3
#define ACC 4
#define CHAR 0
#define ANY 1

static	void		check_true(long nums[4], int base, int chars[2])
{
	if (nums[ACC] < nums[CUTOFF] || (nums[ACC] == nums[CUTOFF] &&
				chars[CHAR] > nums[CUTLIM]))
	{
		chars[ANY] = -1;
		nums[ACC] = LONG_MIN;
		errno = ERANGE;
	}
	else
	{
		chars[ANY] = 1;
		nums[ACC] *= base;
		nums[ACC] -= chars[CHAR];
	}
}

static	void		check_false(long nums[4], int base, int chars[2])
{
	if (nums[ACC] > nums[CUTOFF] || (nums[ACC] == nums[CUTOFF]
				&& chars[CHAR] > nums[CUTLIM]))
	{
		chars[ANY] = -1;
		nums[ACC] = LONG_MAX;
		errno = ERANGE;
	}
	else
	{
		chars[ANY] = 1;
		nums[ACC] *= base;
		nums[ACC] += chars[CHAR];
	}
}

static	void		start_work_strtol(long nums[4], int base, const char *cp)
{
	extern	int	errno;
	int			chars[2];

	ft_bzero(chars, (sizeof(int) * 2));
	while (1)
	{
		chars[CHAR] = *(cp++);
		if (ft_isdigit(chars[CHAR]))
			chars[CHAR] -= '0';
		else if (ft_isalpha(chars[CHAR]))
			chars[CHAR] -= ft_isupper(chars[CHAR]) ? 'A' - 10 : 'a' - 10;
		else
			break ;
		if (chars[CHAR] >= base)
			break ;
		if (chars[ANY] < 0)
			continue ;
		if (nums[NEG])
			check_true(nums, base, chars);
		else
			check_false(nums, base, chars);
	}
}

static	void		check_cut_off(long nums[4], int base, const char *cp)
{
	nums[CUTOFF] = nums[NEG] ? LONG_MIN : LONG_MAX;
	nums[CUTLIM] = nums[CUTOFF] % base;
	nums[CUTOFF] /= base;
	if (nums[NEG])
	{
		if (nums[CUTOFF] > 0)
		{
			nums[CUTLIM] -= base;
			nums[CUTOFF] += 1;
		}
		nums[CUTLIM] = -nums[CUTLIM];
	}
	start_work_strtol(nums, base, cp);
}

long				ft_strtol(const char *str, char **endptr, int base)
{
	const	char	*cp;
	long			nums[5];

	ft_bzero(nums, (sizeof(long) * 5));
	cp = str;
	if (str)
	{
		while (ft_isspace((unsigned char)*(cp)))
			cp = ++cp == ++str ? cp : cp;
		if (*cp == '-')
			nums[NEG] = (((long)((*cp == '-') || (*cp == '+'))
						? *(++cp) : 1) * 0) + 1;
		if ((base == 0 || base == 16) && *cp == '0' &&
				*(cp + 1) && (*(cp + 1) == 'x' || *(cp + 1) == 'X'))
		{
			cp += 2;
			base = 16;
		}
		if (base == 0)
			base = *cp == '0' ? 8 : 10;
	}
	check_cut_off(nums, base, cp);
	if (endptr != 0)
		*endptr = ((char*)cp - 1);
	return (nums[ACC]); //Why not NUM?
}
