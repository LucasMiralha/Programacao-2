#include <iostream>
#include <string>
#include "ManualShippingContainer.hpp"

using namespace std;

void ManualShippingContainer::setManifest(string nManifest)
{
	manifest = nManifest;
}

string ManualShippingContainer::getManifest()
{
	return manifest;
}