#ifndef MANUALSHIPPINGCONTAINER_HPP
#define MANUALSHIPPINGCONTAINER_HPP

#include <iostream>
#include <string>
#include "ShippingContainer.hpp"

using namespace std;

class ManualShippingContainer : public ShippingContainer
{
	private:
		string manifest;
	
	public:
		void setManifest(string nManifest);
		virtual string getManifest();
		
};

#endif