/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 20:22:55 by ggrimes           #+#    #+#             */
/*   Updated: 2020/03/03 21:04:13 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	pf_pre_p(t_printf *restrict pf, intmax_t nb, size_t len)
{
	size_t		res_len;
	char		is_prec;

	if ((int)len < pf->prec || (!pf->prec && !nb))
		res_len = pf->prec;
	else
		res_len = len;
	is_prec = (pf->flags & PF_FL_ZERO) && pf->prec == -1;
	if (!(pf->flags & PF_FL_MINUS))
		pf_add_symb(pf, is_prec ? '0' : ' ', res_len + 2);
	ft_memcpy(pf->buff + pf->buff_len, "0x", 2);
	pf->buff_len += 2;
	while (len++ < res_len)
		pf->buff[pf->buff_len++] = '0';
	return (res_len);
}

void			pf_handle_p(t_printf *restrict pf, intmax_t nb, char *str)
{
	size_t	len;

	len = ft_strlen(str);
	pf_check_mem(pf, pf->width + len + 3);
	len = pf_pre_p(pf, nb, len);
	pf_add_str_2_buff(pf, str, len);
	if (pf->flags & PF_FL_MINUS)
		pf_add_symb(pf, ' ', len + 2);
	ft_strdel(&str);
}
