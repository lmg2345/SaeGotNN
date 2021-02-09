#pragma once
#include "Layer.h"
#include "Weights.h"
#include <vector>
using namespace std;
class Neural_Network
{
public:
	Neural_Network() {};
	virtual ~Neural_Network() {};

	//virtual void forward_propagate__() {};
	//virtual void set_error__() {};
	//void back_propagate__();
	//double get_value__double();
	//void make_weights__();
	//void make_network__(vector<Layer> layers);

	//�� ���� Layer ���̿� �ִ� weights�� ����
	//void make_weights__(vector<Layer>& layers);






protected:
	size_t number_of_Layers__sizet = 0;
	size_t number_of_Weights__sizet = 0;


	


};


class Neural_Network_1d :Neural_Network
{
public:
	Neural_Network_1d(const vector<Layer_1d>& layers);
	~Neural_Network_1d() {};

	void initialize__();
	void forward_propagate__();
	//forward�� ����Ǿ��� �� i��° ����� output ���� ��ȯ
	double get_output__double(size_t i);
	//forward�� ����Ǿ��� �� i��° ����� error(��갪-����) ���� ��ȯ
	double get_error__double(size_t i);

private:
	vector<Layer_1d> layer_set__1Layer_1d;
	vector<Layer_1d> target_Layer_batchset__1Layer_1d;
	vector<Weights_1d_Layer> weights_set__1Weights_1d;
	vector<size_t> number_of_nodes_set__sizet;

	//�� ���� Layer ���̿� �ִ� weights�� ����
	void make_weights__(vector<Layer_1d>& layers);
};