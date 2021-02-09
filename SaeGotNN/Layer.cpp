#include "Layer.h"


Layer::Layer(string layer_type) :layer_type__string(layer_type)
{

}



Layer_1d::Layer_1d(string layer_type) : Layer(layer_type)
{

}

size_t Layer_1d::get_number_of_nodes__sizet()
{
	return number_of_nodes__sizet;
}


void Layer_1d::make_nodes(const size_t& number_of_nodes)
{	

	number_of_nodes__sizet = number_of_nodes;

	nodes__1double.resize(number_of_nodes);
	/*
	nodes__2double.push_back(nodes__1double);
	nodes__3double.push_back(nodes__2double);
	*/
}

double Layer_1d::get_node_value__double(size_t i)
{
	return nodes__1double[i];
}

void Layer_1d::set_node_value(const double& value, size_t i)
{

	if (number_of_nodes__sizet <= i)
	{
		printf("¿¡·¯");
	}
	else
	{
		nodes__1double[i] = value;
	}
}

string Layer_1d::get_layer_type__string()
{
	return layer_type__string;
}