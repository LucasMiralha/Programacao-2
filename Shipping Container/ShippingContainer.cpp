#include <iostream>
#include <string>
#include "ShippingContainer.hpp"

using namespace std;

void ShippingContainer::setID(int nID)
{
	id = nID;
}

int ShippingContainer::getID()
{
	return id;
}

string ShippingContainer::getManifest()
{
	return vazia;
}