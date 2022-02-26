/*
** EPITECH PROJECT, 2021
** common
** File description:
** tests1.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test (my_printf, i, .init = cr_redirect_stdout)
{
    cr_assert_stdout_eq_str("common");
}
