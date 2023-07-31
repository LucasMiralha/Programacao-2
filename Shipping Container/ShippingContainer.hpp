#ifndef SHIPPINGCONTAINER_HPP
#define SHIPPINGCONTAINER_HPP

#include <iostream>
#include <string>

using namespace std;

class ShippingContainer
{
	private:
		int id;
		string vazia = (" ");
	
	public:
		void setID(int nID);
		int getID();
		virtual string getManifest();
	
};

#endif