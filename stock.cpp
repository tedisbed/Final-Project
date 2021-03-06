#include "stock.h"
#include <string>
#include <random>
#include <iostream>
#include <stdlib.h>
using namespace std;

stock::stock(double b, double price, string name,string type, default_random_engine & gen) : generator(gen) {

	stock_type = type;
	beta = b;
	stock_price = price;
	stock_name = name;
}

string stock::get_type(){
	return stock_type;
}

double stock::get_beta(){
	return beta;
}

double stock::get_price(){
	return stock_price;
}

string stock::get_stockName(){
	return stock_name;
}

void stock::recalc_price(){
	double random_chance = 0, company_quantitative = 0, company_qualitative = 0;
	double industry_news = 0, insutry_advance = 0;
	double economy_new = 0, economy_fedReserve_news = 0;
	double stock_change = 0;
	double stock_factor = 0;

	if (stock_price <= 0){
		stock_price = 0;
		return;
	}

	normal_distribution<double> distribution(stock_price, (stock_price/2));

	random_chance = distribution(generator);
	company_qualitative = distribution(generator);
	company_quantitative = distribution(generator);
	industry_news = distribution(generator);
	insutry_advance = distribution(generator);
	economy_new = distribution(generator);
	economy_fedReserve_news = distribution(generator);

	stock_change = (company_quantitative*.25)+(company_qualitative*.25)+(insutry_advance*.15)+(industry_news*.15)+(economy_fedReserve_news*.1)+(economy_new*.05)+(random_chance*.05);

	stock_change = stock_change - stock_price;

	stock_factor = stock_change / (stock_price / 2);

	stock_price = stock_price + (stock_factor * beta);

	if (stock_price <= 0){
		stock_price = 0;
	}
}















