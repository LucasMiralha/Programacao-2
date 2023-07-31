#ifndef RFIDSHIPPINGCONTAINER_HPP
#define RFIDSHIPPINGCONTAINER_HPP

#include <iostream>
#include <string>
#include <vector>
#include "ShippingContainer.hpp"

using namespace std;

class RFIDShippingContainer : public ShippingContainer
{
	private:
		vector<string> registro;
		string manifest;
		
	public:
		void add(string nReg);
		virtual string getManifest();
	
};

#endif