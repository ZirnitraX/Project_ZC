/*
** EPITECH PROJECT, 2021
** Project_ZC
** File description:
** polevents
*/

#include "include/project.h"

void all_events(all_s *all)
{
    switch (all->evt.type)
    {
    case all->evt.Closed:
        all->wndw.close();
        break;
    }
}