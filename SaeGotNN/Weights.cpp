#include "Weights.h"

void Weights_1d_Layer::make_weights__(size_t before_number_of_nodes, size_t after_number_of_nodes, string layer_type)
{
	weigths__Weights_1d.resize(before_number_of_nodes);
	if (layer_type == "FullyConnected")
	{
		for (size_t i = 0; i < before_number_of_nodes; ++i)
		{
			weigths__Weights_1d[i].resize(after_number_of_nodes);
			for (size_t j = 0; j < after_number_of_nodes; ++j)
			{
				weigths__Weights_1d[i][j] = 1.0;
			}

		}
	}

}

double Weights_1d_Layer::get_weight_value__double(size_t i, size_t j)
{
	return weigths__Weights_1d[i][j];
}