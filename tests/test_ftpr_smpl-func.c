/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ftpr_smpl-func.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 14:52:29 by fmaurer           #+#    #+#             */
/*   Updated: 2024/07/13 14:55:20 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#ifdef BONUS
# include "../ft_printf_bonus.h"
#else
# include "../ft_printf.h"
#endif

// colors
#define RED "\033[1;31m"
#define GRN "\033[1;32m"
#define YLO "\033[1;33m"
#define RST "\033[0m"

static int FAIL = 0;

void test_ftpr_smpl()
{
	printf(YLO "\n---- test_ftpr ----\n\n" RST);
	int rft = 0;
	int rog = 0;

	// #1
	printf(YLO "-- ftpr_test #1 --\n" RST);
	printf(YLO "-- ft_printf:%s\n", RST);
	rft = ft_printf("Hello 42!\n");
	printf(YLO "-- printf:\n" RST);
	rog = printf("Hello 42!\n");
	printf(YLO "--\n\n" RST);
	if (rft != rog) {
		printf(RED "#1 Error!\n" RST);
		printf(RED "rft = %d\nshould be: %d\n\n" RST, rft, rog);
		FAIL = 1;
	}
	// #2
	printf(YLO "-- ftpr_test #2 --\n" RST);
	printf(YLO "-- ft_printf:%s\n", RST);
	rft = ft_printf("");
	printf(YLO "-- printf:\n" RST);
	rog = printf("");
	printf(YLO "--\n\n" RST);
	if (rft != rog) {
		printf(RED "#2 Error!\n" RST);
		printf(RED "rft = %d\nshould be: %d\n\n" RST, rft, rog);
		FAIL = 1;
	}
	// #3
	printf(YLO "-- ftpr_test #3 --\n" RST);
	printf(YLO "-- ft_printf:%s\n", RST);
	rft = ft_printf("%s", NULL);
	printf(YLO "\n-- printf:\n" RST);
	rog = printf("%s", NULL);
	printf(YLO "\n--\n\n" RST);
	if (rft != rog) {
		printf(RED "#3 Error!\n" RST);
		printf(RED "rft = %d\nshould be: %d\n\n" RST, rft, rog);
		FAIL = 1;
	}
	// #4
	printf(YLO "-- ftpr_test #4 --\n" RST);
	printf(YLO "-- ft_printf:%s\n", RST);
	rft = ft_printf("%s%s", NULL);
	printf(YLO "\n-- printf:\n" RST);
	rog = printf("%s%s", NULL);
	printf(YLO "\n--\n\n" RST);
	if (rft != rog) {
		printf(RED "#4 Error!\n" RST);
		printf(RED "rft = %d\nshould be: %d\n\n" RST, rft, rog);
		FAIL = 1;
	}
	// #5
	printf(YLO "-- ftpr_test #5 --\n" RST);
	printf(YLO "-- ft_printf:%s\n", RST);
	rft = ft_printf("%s%i%d%c%p%x%X", "atat", 42, -123, '%', NULL, 42, 42);
	printf(YLO "\n-- printf:\n" RST);
	rog = printf("%s%i%d%c%p%x%X", "atat", 42, -123, '%', NULL, 42, 42);
	printf(YLO "\n--\n\n" RST);
	if (rft != rog) {
		printf(RED "#5 Error!\n" RST);
		printf(RED "rft = %d\nshould be: %d\n\n" RST, rft, rog);
		FAIL = 1;
	}
	// #6
	printf(YLO "-- ftpr_test #6 --\n" RST);
	printf(YLO "-- ft_printf:%s\n", RST);
	rft = ft_printf("%i%d%x%X", INT_MAX, INT_MAX, INT_MAX, INT_MAX);
	printf(YLO "\n-- printf:\n" RST);
	rog = printf("%i%d%x%X", INT_MAX, INT_MAX, INT_MAX, INT_MAX);
	printf(YLO "\n--\n\n" RST);
	if (rft != rog) {
		printf(RED "#6 Error!\n" RST);
		printf(RED "rft = %d\nshould be: %d\n\n" RST, rft, rog);
		FAIL = 1;
	}
	// #7
	printf(YLO "-- ftpr_test #7 --\n" RST);
	printf(YLO "-- ft_printf:%s\n", RST);
	rft = ft_printf("%i%d%x%X", INT_MIN, INT_MIN, INT_MIN, INT_MIN);
	printf(YLO "\n-- printf:\n" RST);
	rog = printf("%i%d%x%X", INT_MIN, INT_MIN, INT_MIN, INT_MIN);
	printf(YLO "\n--\n\n" RST);
	if (rft != rog) {
		printf(RED "#7 Error!\n" RST);
		printf(RED "rft = %d\nshould be: %d\n\n" RST, rft, rog);
		FAIL = 1;
	}
	// #8
	printf(YLO "-- ftpr_test #8 --\n" RST);
	printf(YLO "-- ft_printf:%s\n", RST);
	rft = ft_printf(NULL);
	printf(YLO "\n-- printf:\n" RST);
	rog = printf(NULL);
	printf(YLO "\n--\n\n" RST);
	if (rft != rog) {
		printf(RED "#8 Error!\n" RST);
		printf(RED "rft = %d\nshould be: %d\n\n" RST, rft, rog);
		FAIL = 1;
	}
	// #9
	printf(YLO "-- ftpr_test #9 --\n" RST);
	printf(YLO "-- ft_printf:%s\n", RST);
	rft = ft_printf(NULL, 42);
	printf(YLO "\n-- printf:\n" RST);
	rog = printf(NULL, 42);
	printf(YLO "\n--\n\n" RST);
	if (rft != rog) {
		printf(RED "#9 Error!\n" RST);
		printf(RED "rft = %d\nshould be: %d\n\n" RST, rft, rog);
		FAIL = 1;
	}
	// #10
	printf(YLO "-- ftpr_test #10 --\n" RST);
	printf(YLO "-- ft_printf:%s\n", RST);
	rft = ft_printf("!(\"=)(§&!)==(=)!\"");
	printf(YLO "\n-- printf:\n" RST);
	rog = printf("!(\"=)(§&!)==(=)!\"");
	printf(YLO "\n--\n\n" RST);
	if (rft != rog) {
		printf(RED "#10 Error!\n" RST);
		printf(RED "rft = %d\nshould be: %d\n\n" RST, rft, rog);
		FAIL = 1;
	}
	// #11
	printf(YLO "-- ftpr_test #11 --\n" RST);
	printf(YLO "-- ft_printf:%s\n", RST);
	rft = ft_printf("!(\"%s=)(§%s&!)==(=)!\"%s", GRN, RED, RST);
	printf(YLO "\n-- printf:\n" RST);
	rog = printf("!(\"%s=)(§%s&!)==(=)!\"%s", GRN, RED, RST);
	printf(YLO "\n--\n\n" RST);
	if (rft != rog) {
		printf(RED "#11 Error!\n" RST);
		printf(RED "rft = %d\nshould be: %d\n\n" RST, rft, rog);
		FAIL = 1;
	}
	// #12
	printf(YLO "-- ftpr_test #12 --\n" RST);
	printf(YLO "-- ft_printf:%s\n", RST);
	rft = ft_printf("%u", INT_MIN + 1);
	printf(YLO "\n-- printf:\n" RST);
	rog = printf("%u", INT_MIN + 1);
	printf(YLO "\n--\n\n" RST);
	if (rft != rog) {
		printf(RED "#12 Error!\n" RST);
		printf(RED "rft = %d\nshould be: %d\n\n" RST, rft, rog);
		FAIL = 1;
	}
	// #13
	printf(YLO "-- ftpr_test #13 --\n" RST);
	printf(YLO "-- ft_printf:%s\n", RST);
	rft = ft_printf("%p", NULL);
	printf(YLO "\n-- printf:\n" RST);
	rog = printf("%p", NULL);
	printf(YLO "\n--\n\n" RST);
	if (rft != rog) {
		printf(RED "#13 Error!\n" RST);
		printf(RED "rft = %d\nshould be: %d\n\n" RST, rft, rog);
		FAIL = 1;
	}
	// #14
	char miep = 'j';
	char *moep = &miep;
	printf(YLO "-- ftpr_test #14 --\n" RST);
	printf(YLO "-- ft_printf:%s\n", RST);
	rft = ft_printf("%p", moep);
	printf(YLO "\n-- printf:\n" RST);
	rog = printf("%p", moep);
	printf(YLO "\n--\n\n" RST);
	if (rft != rog) {
		printf(RED "#14 Error!\n" RST);
		printf(RED "rft = %d\nshould be: %d\n\n" RST, rft, rog);
		FAIL = 1;
	}
	// #15
	printf(YLO "-- ftpr_test #15 --\n" RST);
	printf(YLO "-- ft_printf:%s\n", RST);
	rft = ft_printf("%");
	printf(YLO "\n-- printf:\n" RST);
	rog = printf("%");
	printf("rft = %d, rog = %d", rft, rog);
	printf(YLO "\n--\n\n" RST);
	if (rft != rog) {
		printf(RED "#15 Error!\n" RST);
		printf(RED "rft = %d\nshould be: %d\n\n" RST, rft, rog);
		FAIL = 1;
	}
	// #16
	printf(YLO "-- ftpr_test #16 --\n" RST);
	printf(YLO "-- ft_printf:%s\n", RST);
	rft = ft_printf("adsjfk %s %", "atat");
	printf(YLO "\n-- printf:\n" RST);
	rog = printf("adsjfk %s %", "atat");
	printf("rft = %d, rog = %d", rft, rog);
	printf(YLO "\n--\n\n" RST);
	if (rft != rog) {
		printf(RED "#16 Error!\n" RST);
		printf(RED "rft = %d\nshould be: %d\n\n" RST, rft, rog);
		FAIL = 1;
	}
}
