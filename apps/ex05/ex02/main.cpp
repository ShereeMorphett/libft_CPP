/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <smorphet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 08:24:44 by smorphet          #+#    #+#             */
/*   Updated: 2023/10/01 17:27:31 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Color.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"


void testingBureaucrat();
void testingForm();

void testingInteractionShrub()
{
	Bureaucrat dude("dude", 1);
	ShrubberyCreationForm shrub("a target here");
	try
	{
		dude.executeForm(shrub);
		dude.signForm(shrub);
		dude.executeForm(shrub);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void testingInteractionPresident()
{
	Bureaucrat dude("dude", 1);
	PresidentialPardonForm prezzie("PresidentialPardon");
	try
	{
		dude.executeForm(prezzie);
		dude.signForm(prezzie);
		dude.executeForm(prezzie);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void testingInteractionRobo()
{
	Bureaucrat dude("dude", 1);
	RobotomyRequestForm robo("RobotomyRequest");

	try
	{
		dude.executeForm(robo);
		dude.signForm(robo);
		dude.executeForm(robo);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}




int main()
{
	std::cout << COLOR_GREEN << "Basic Bureaucrat tests\n" << COLOR_RESET << std::endl;
	testingBureaucrat();
	std::cout << COLOR_GREEN << "\nBasic Form tests\n" << COLOR_RESET << std::endl;
	testingForm();
	std::cout << COLOR_GREEN << "\nTesting Interaction- Shrubs\n" << COLOR_RESET << std::endl;
	testingInteractionShrub();
	std::cout << COLOR_GREEN << "\nTesting Interaction- President\n" << COLOR_RESET << std::endl;
	testingInteractionPresident();
	std::cout << COLOR_GREEN << "\nTesting Interaction- Robo\n" << COLOR_RESET << std::endl;
	testingInteractionRobo();
	std::cout << COLOR_RED << "\nEnd of tests......\n" << COLOR_RESET << std::endl;

	
	
	return 0;
}