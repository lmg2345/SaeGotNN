#pragma 
#include <vector>
#include <string>
using namespace std;

class Layer
{
public:
	Layer(string layer_type);
	virtual ~Layer() {};



	virtual double get_node_value__double() { return 0.0; };
	virtual size_t get_number_of_nodes__size_t() { return 0; };

	virtual void make_nodes(const int& number_of_nodes) {};

	//i, j, k 번째 노드의 값 설정
	virtual void set_node_value() {};
	virtual string get_layer_type__string() {
		return layer_type__string
			;
	};

protected:
	string layer_type__string;

/*
protected:
	vector<double> nodes__1double;
	vector<vector<double>> nodes__2double;
	vector<vector<vector<double>>> nodes__3double;
	size_t number_of_nodes__sizet = 0;
*/
};


class Layer_1d :Layer
{
public:
	Layer_1d(string layer_type);
	~Layer_1d() {};

	size_t get_number_of_nodes__sizet();
	void make_nodes(const size_t& number_of_nodes);
	double get_node_value__double(size_t i);

	//i, j, k 번째 노드의 값 설정
	void set_node_value(const double& value, size_t i);
	string get_layer_type__string();
private:
	vector<double> nodes__1double;
	size_t number_of_nodes__sizet = 0;
};
