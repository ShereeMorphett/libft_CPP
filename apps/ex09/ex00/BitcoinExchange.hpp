/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <smorphet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:55:01 by smorphet          #+#    #+#             */
/*   Updated: 2023/11/02 20:32:39 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BitcoinExchange_HPP
# define BitcoinExchange_HPP
# include <iostream>
# include <map>
# include <string>
# include <fstream>
# include <sstream>

struct date
{
    int year;
    int month;
    int day;
    
    bool operator== (const date& right) const;
    bool operator!= (const date& right) const;
    bool operator< (const date& right) const;
};

class BitcoinExchange
{
	private:
		std::map<date, float> data_;
	public:
		void parseInitData();
		void handleInput(std::string fileName);
		BitcoinExchange ();
		BitcoinExchange( BitcoinExchange const & src );
		~BitcoinExchange();
		BitcoinExchange &	operator=( BitcoinExchange const & right);

};


std::ostream& operator<<( std::ostream& os , const date& right);
std::istream& operator>>(std::istream& is , const date& right);
#endif