/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <smorphet@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 12:38:49 by smorphet          #+#    #+#             */
/*   Updated: 2023/09/20 15:47:34 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"


Brain	*Cat::getBrain() const
{
	return catBrain_;
}


void Cat::makeSound() const
{
    std::cout << COLOR_BLUE << "Meow! " << COLOR_RESET << std::endl ;
}


Cat& Cat::operator=(Cat const &right)
{
    *static_cast<Animal*>(this) = right; 
	*catBrain_ = *right.catBrain_;
    
    return *this;
}

Cat::Cat(): Animal("Cat") , catBrain_(new Brain)
{
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& Cpy)
{
    std::cout << "Cat Copy constructor called" << std::endl;
	catBrain_ = new Brain(*Cpy.catBrain_);
    *this = Cpy;
}

Cat::~Cat()
{
   	if (catBrain_)
		delete catBrain_;
    std::cout << "Cat destructor called" << std::endl;
}