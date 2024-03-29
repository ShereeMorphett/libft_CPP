/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <smorphet@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:00:56 by smorphet          #+#    #+#             */
/*   Updated: 2023/09/20 10:59:55 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICharacter_HPP
# define ICharacter_HPP

# include <iostream>

class AMateria;

class ICharacter //Interface there for none instantiable
{
 	public:
		virtual void printFloor() const = 0;
		virtual ~ICharacter() {};
		virtual std::string const &getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

#endif
