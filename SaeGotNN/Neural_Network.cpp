#include "Neural_Network.h"


Neural_Network_1d::Neural_Network_1d(const vector<Layer_1d>& layers)
{
	number_of_Layers__sizet = layers.size();
	target_Layer_batchset__1Layer_1d.push_back(layers[number_of_Layers__sizet - 1]);

	//나중에 수정 필요
	number_of_Weights__sizet = number_of_Layers__sizet - 1;
	layer_set__1Layer_1d = layers;

	for (size_t i = 0;i < number_of_Layers__sizet;++i)
	{
		number_of_nodes_set__sizet.push_back(layer_set__1Layer_1d[i].get_number_of_nodes__sizet());
	}

}


void Neural_Network_1d::initialize__()
{
	make_weights__(layer_set__1Layer_1d);
}


void Neural_Network_1d::forward_propagate__()
{
	double tmp_value__double = 0;
	//나중에 수정 필요
	for (size_t l = 0; l < number_of_Weights__sizet; ++l)
	{
		Layer_1d& current_Layer = layer_set__1Layer_1d[l];
		Layer_1d& next_Layer = layer_set__1Layer_1d[l+1];

		Weights_1d_Layer& current_Weights = weights_set__1Weights_1d[l];
		//나중에 수정 필요
		for (size_t j = 0; j < number_of_nodes_set__sizet[l + 1]; ++j)
		{
			for (size_t i = 0; i < number_of_nodes_set__sizet[l]; ++i)			
			{
				tmp_value__double += current_Layer.get_node_value__double(i)* current_Weights.get_weight_value__double(i, j);				
			}
			next_Layer.set_node_value(tmp_value__double, j);
			tmp_value__double = 0;
		}

	}
}

double Neural_Network_1d::get_output__double(size_t i)
{
	return layer_set__1Layer_1d[number_of_Layers__sizet - 1].get_node_value__double(i);
}

double Neural_Network_1d::get_error__double(size_t i)
{
	double output__double = layer_set__1Layer_1d[number_of_Layers__sizet - 1].get_node_value__double(i);
	//나중에 수정필요(1batch 일때만 계산)
	double target__double = target_Layer_batchset__1Layer_1d[0].get_node_value__double(i);
	
	return output__double - target__double;
}

void Neural_Network_1d::make_weights__(vector<Layer_1d>& layers)
{
	
	size_t before_number_of_nodes__sizet = layers[0].get_number_of_nodes__sizet();
	for (size_t i=0; i < number_of_Layers__sizet - 1; ++i)
	{
		size_t after_number_of_nodes__sizet = layers[i+1].get_number_of_nodes__sizet();

		Weights_1d_Layer *tmp_weights;
		tmp_weights = new Weights_1d_Layer;

		tmp_weights->make_weights__(before_number_of_nodes__sizet, after_number_of_nodes__sizet, layers[i+1].get_layer_type__string());

		
		weights_set__1Weights_1d.push_back(*tmp_weights);

		before_number_of_nodes__sizet = after_number_of_nodes__sizet;
		delete tmp_weights;
	}
	
}