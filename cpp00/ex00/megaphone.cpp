/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 18:41:24 by gude-cas          #+#    #+#             */
/*   Updated: 2024/04/02 16:25:37 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
    if (ac > 1)
    {
        for (int i = 1; i < ac; i++)
        {
            for (int j = 0; av[i][j]; j++)
                std::cout << (char)toupper(av[i][j]);
            if(i < ac - 1)
                std::cout << " ";
        }
        std::cout << std::endl;
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}
