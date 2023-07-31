#include <iostream>
#include <string>
#include <vector>
#include "ShippingContainer.hpp"
#include "ManualShippingContainer.hpp"
#include "RFIDShippingContainer.hpp"

using namespace std;

int main()
{
	int i;
	ShippingContainer* containers[6];
	ManualShippingContainer mContainers[3];
	RFIDShippingContainer rfContainers[3];
	  
	mContainers[0].setID(473);
	mContainers[0].setManifest("1 caixa de maca. 2 caixas de pera");
	
	mContainers[1].setID(220);
	mContainers[1].setManifest("1 Toyota Corolla 2012");
	
	mContainers[2].setID(420);
	mContainers[2].setManifest("10 caixas de bananas. 4 caixas de macas");
	
	rfContainers[0].setID(176);
	rfContainers[0].add("Caixa de maca");
	rfContainers[0].add("Caixa de maca");
	rfContainers[0].add("Caixa de pera");
	rfContainers[0].add("Caixa de pera");
	
	rfContainers[1].setID(99);
	rfContainers[1].add("Caixa de maca");
	rfContainers[1].add("Caixa de graviola");
	rfContainers[1].add("Caixa de pera");
	rfContainers[1].add("Caixa de pera");
	rfContainers[1].add("Caixa de graviola");
	
	rfContainers[2].setID(599);
	rfContainers[2].add("Caixa de banana");
	rfContainers[2].add("Caixa de maca");
	rfContainers[2].add("Caixa de pera");
	
	containers[0] = &mContainers[0];
	containers[1] = &mContainers[1];
	containers[2] = &mContainers[2];
	
	containers[3] = &rfContainers[0];
	containers[4] = &rfContainers[1];
	containers[5] = &rfContainers[2];
	
	for(i = 0; i < 6; i++)
	{
		cout << "ID: " << containers[i]->getID() << endl;
		cout << "Manifesto: " << containers[i]->getManifest() << endl;
		cout << endl;
	}
	
	return 0;
}