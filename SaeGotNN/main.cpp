#include <stdio.h>
#include <iostream>
#include <vector>
#include "Neural_Network.h"

using namespace std;
int main()
{
	Layer_1d Layer1("FullyConnected");
	Layer_1d Layer2("FullyConnected");
	Layer_1d Layer3("FullyConnected");
	
	Layer1.make_nodes(4);
	Layer1.set_node_value(0, 0);
	Layer1.set_node_value(1, 1);
	Layer1.set_node_value(2, 2);
	Layer1.set_node_value(3, 3);

	Layer2.make_nodes(2);

	Layer3.make_nodes(3);
	Layer3.set_node_value(10, 0);
	Layer3.set_node_value(15, 1);
	Layer3.set_node_value(13, 2);

	vector<Layer_1d> Layers;
	Layers.push_back(Layer1);
	Layers.push_back(Layer2);
	Layers.push_back(Layer3);

	Neural_Network_1d nn(Layers);
	nn.initialize__();
	nn.forward_propagate__();
	double a = nn.get_output__double(1);
	double b = nn.get_error__double(1);

	cout << a << endl;
	return 0;
}