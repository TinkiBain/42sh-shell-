/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_spec_symbol.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 17:15:52 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/07 19:12:44 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			check_spec_symbol(char c)
{
	if (c == '#' || c == '%' || c == '!' || c == '@' || c == '"' || c == '\''
			|| c == '^' || c == '*'
			|| c == '=' || c == '/' || c == '\\' || c == '.' || c == ' ')
		return (0);
	return (1);
}

int			check_spec_symboli_dq(char c)
{
	if (c == '#' || c == '%' || c == '!' || c == '@' || c == '"'
			|| c == '^' || c == '*'
			|| c == '=' || c == '/' || c == '\\' || c == '.' || c == '$')
		return (0);
	return (1);
}
