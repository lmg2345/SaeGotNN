#pragma once
#include <vector>
#include <string>
using namespace std;


typedef vector<vector<double>> type_Weights_1d;

class Weights
{
public:
	Weights() {};
	virtual ~Weights() {};

	virtual double get_weight_value__double() { return 0.0; }
	
};

class Weights_1d_Layer :Weights
{
public:
	Weights_1d_Layer() {};
	~Weights_1d_Layer() {};

	void make_weights__(size_t before_number_of_nodes, size_t after_number_of_nodes, string layer_type);
	//전 Layer i번째 노드와 후 Layer j번째 노드를 연결하는 weight 값
	double get_weight_value__double(size_t i, size_t j);

private:
	type_Weights_1d weigths__Weights_1d;
};


/*
class Weights_Set
{
public:
	Weights_Set();
	~Weights_Set();

	void make_weights_set__();

private:
	vector<Weights_1d> weigths_set__1Weights_1d;
};
*/