/*
** EPITECH PROJECT, 2021
** Project_Zt
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

void custom_events(all_s *all)
{
    switch (all->state)
    {
    case menust:
        menu_events(all);
        break;
    case settingsst:
        settings_events(all);
        break;
    default:
        break;
    }  
}