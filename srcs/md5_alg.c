/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_alg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 19:18:55 by uhand             #+#    #+#             */
/*   Updated: 2020/11/21 22:05:50 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/md5.h"

void	round_1(t_md *md)
{
	A = B + shift((A + f_ft(B, C, D) + X[0] + T[0]), 7);
	D = A + shift((D + f_ft(A, B, C) + X[1] + T[1]), 12);
	C = D + shift((C + f_ft(D, A, B) + X[2] + T[2]), 17);
	B = C + shift((B + f_ft(C, D, A) + X[3] + T[3]), 22);
	A = B + shift((A + f_ft(B, C, D) + X[4] + T[4]), 7);
	D = A + shift((D + f_ft(A, B, C) + X[5] + T[5]), 12);
	C = D + shift((C + f_ft(D, A, B) + X[6] + T[6]), 17);
	B = C + shift((B + f_ft(C, D, A) + X[7] + T[7]), 22);
	A = B + shift((A + f_ft(B, C, D) + X[8] + T[8]), 7);
	D = A + shift((D + f_ft(A, B, C) + X[9] + T[9]), 12);
	C = D + shift((C + f_ft(D, A, B) + X[10] + T[10]), 17);
	B = C + shift((B + f_ft(C, D, A) + X[11] + T[11]), 22);
	A = B + shift((A + f_ft(B, C, D) + X[12] + T[12]), 7);
	D = A + shift((D + f_ft(A, B, C) + X[13] + T[13]), 12);
	C = D + shift((C + f_ft(D, A, B) + X[14] + T[14]), 17);
	B = C + shift((B + f_ft(C, D, A) + X[15] + T[15]), 22);
}

void	round_2(t_md *md)
{
	A = B + shift((A + g_ft(B, C, D) + X[1] + T[16]), 5);
	D = A + shift((D + g_ft(A, B, C) + X[6] + T[17]), 9);
	C = D + shift((C + g_ft(D, A, B) + X[11] + T[18]), 14);
	B = C + shift((B + g_ft(C, D, A) + X[0] + T[19]), 20);
	A = B + shift((A + g_ft(B, C, D) + X[5] + T[20]), 5);
	D = A + shift((D + g_ft(A, B, C) + X[10] + T[21]), 9);
	C = D + shift((C + g_ft(D, A, B) + X[15] + T[22]), 14);
	B = C + shift((B + g_ft(C, D, A) + X[4] + T[23]), 20);
	A = B + shift((A + g_ft(B, C, D) + X[9] + T[24]), 5);
	D = A + shift((D + g_ft(A, B, C) + X[14] + T[25]), 9);
	C = D + shift((C + g_ft(D, A, B) + X[3] + T[26]), 14);
	B = C + shift((B + g_ft(C, D, A) + X[8] + T[27]), 20);
	A = B + shift((A + g_ft(B, C, D) + X[13] + T[28]), 5);
	D = A + shift((D + g_ft(A, B, C) + X[2] + T[29]), 9);
	C = D + shift((C + g_ft(D, A, B) + X[7] + T[30]), 14);
	B = C + shift((B + g_ft(C, D, A) + X[12] + T[31]), 20);
}

void	round_3(t_md *md)
{
	A = B + shift((A + h_ft(B, C, D) + X[5] + T[32]), 4);
	D = A + shift((D + h_ft(A, B, C) + X[8] + T[33]), 11);
	C = D + shift((C + h_ft(D, A, B) + X[11] + T[34]), 16);
	B = C + shift((B + h_ft(C, D, A) + X[14] + T[35]), 23);
	A = B + shift((A + h_ft(B, C, D) + X[1] + T[36]), 4);
	D = A + shift((D + h_ft(A, B, C) + X[4] + T[37]), 11);
	C = D + shift((C + h_ft(D, A, B) + X[7] + T[38]), 16);
	B = C + shift((B + h_ft(C, D, A) + X[10] + T[39]), 23);
	A = B + shift((A + h_ft(B, C, D) + X[13] + T[40]), 4);
	D = A + shift((D + h_ft(A, B, C) + X[0] + T[41]), 11);
	C = D + shift((C + h_ft(D, A, B) + X[3] + T[42]), 16);
	B = C + shift((B + h_ft(C, D, A) + X[6] + T[43]), 23);
	A = B + shift((A + h_ft(B, C, D) + X[9] + T[44]), 4);
	D = A + shift((D + h_ft(A, B, C) + X[12] + T[45]), 11);
	C = D + shift((C + h_ft(D, A, B) + X[15] + T[46]), 16);
	B = C + shift((B + h_ft(C, D, A) + X[2] + T[47]), 23);
}

void	round_4(t_md *md)
{
	A = B + shift((A + i_ft(B, C, D) + X[0] + T[48]), 6);
	D = A + shift((D + i_ft(A, B, C) + X[7] + T[49]), 10);
	C = D + shift((C + i_ft(D, A, B) + X[14] + T[50]), 15);
	B = C + shift((B + i_ft(C, D, A) + X[5] + T[51]), 21);
	A = B + shift((A + i_ft(B, C, D) + X[12] + T[52]), 6);
	D = A + shift((D + i_ft(A, B, C) + X[3] + T[53]), 10);
	C = D + shift((C + i_ft(D, A, B) + X[10] + T[54]), 15);
	B = C + shift((B + i_ft(C, D, A) + X[1] + T[55]), 21);
	A = B + shift((A + i_ft(B, C, D) + X[8] + T[56]), 6);
	D = A + shift((D + i_ft(A, B, C) + X[15] + T[57]), 10);
	C = D + shift((C + i_ft(D, A, B) + X[6] + T[58]), 15);
	B = C + shift((B + i_ft(C, D, A) + X[13] + T[59]), 21);
	A = B + shift((A + i_ft(B, C, D) + X[4] + T[60]), 6);
	D = A + shift((D + i_ft(A, B, C) + X[11] + T[61]), 10);
	C = D + shift((C + i_ft(D, A, B) + X[2] + T[62]), 15);
	B = C + shift((B + i_ft(C, D, A) + X[9] + T[63]), 21);
}

void md5_alg(t_md *md)
{
	while (read_block(md))
	{
		ft_memcpy(&(md->digest_buf[0]), &(md->digest[0]), 16);
		round_1(md);
		round_2(md);
		round_3(md);
		round_4(md);
		A += AA;
		B += BB;
		C += CC;
		D += DD;
	}

}
