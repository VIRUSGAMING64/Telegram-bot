
//Incluir las librerías necesarias
#include <bits/stdc++.h>
using namespace std;
//Definir la clase RedNeuronal
class RedNeuronal 
{
  //Atributos 
  int num_inputs;
  int num_outputs;
  int num_layers;
  vector<int> layer_sizes;
  vector<vector<vector<double>>> weights;
  vector<vector<double>> bias;
  
  //Métodos 
  vector<double> feedforward(vector<double> inputs);
  void backpropagation(vector<double> inputs, vector<double> outputs);
  void train(vector<vector<double>> inputs, vector<vector<double>> outputs, int num_iterations, double learning_rate);
  
public:
  //Constructor
  RedNeuronal(vector<int> layer_sizes);
  
  //Métodos públicos
  void predict(vector<double> inputs);
};

//Definir los métodos de la clase RedNeuronal
vector<double> RedNeuronal::feedforward(vector<double> inputs) {
  vector<double> output = inputs;
  //Iterar a través de cada capa
  for (int i = 0; i < num_layers; i++) {
    //Calcular la suma ponderada de los inputs 
    vector<double> weighted_sum;
    for (int j = 0; j < layer_sizes[i]; j++) {
      double sum = 0.0;
      for (int k = 0; k < layer_sizes[i - 1]; k++) {
        sum += weights[i][j][k] * output[k];
      }
      sum += bias[i][j];
      weighted_sum.push_back(sum);
    }
    
    //Calcular la salida de la capa output.
    //clear();
    for (int j = 0; j < layer_sizes[i]; j++) {
      double activation = 1.0 / (1.0 + exp(-weighted_sum[j]));
      output.push_back(activation);
    }
  }
  return output;
}

void RedNeuronal::backpropagation(vector<double> inputs, vector<double> outputs) {
  //Calcular la salida de la red
  vector<double> predicted_output = feedforward(inputs);
  
  //Calcular el error de la última capa
  vector<double> errors;
  for (int i = 0; i < num_outputs; i++) {
    errors.push_back(outputs[i] - predicted_output[i]);
  }
  
  //Calcular el error de cada capa
  for (int i = num_layers - 1; i > 0; i--) {
    //Calcular el error de la capa actual
    vector<double> layer_errors;
    for (int j = 0; j < layer_sizes[i]; j++) {
      double error = 0.0;
      for (int k = 0; k < layer_sizes[i + 1]; k++) {
        error += weights[i + 1][k][j] * errors[k];
      }
      layer_errors.push_back(error);
    }
    errors = layer_errors;
    //Actualizar los pesos de la capa actual
    for (int j = 0; j < layer_sizes[i]; j++) {
      for (int k = 0; k < layer_sizes[i - 1]; k++) {
        weights[i][j][k] += errors[j] * inputs[k];
      }
      bias[i][j] += errors[j];
    }
    
    //Actualizar los inputs para la siguiente iteración
    inputs = feedforward(inputs);
  }
}

void RedNeuronal::train(vector<vector<double>> inputs, vector<vector<double>> outputs, int num_iterations, double learning_rate) {
  //Inicializar el generador de números aleatorios
  srand(time(NULL));
  
  //Iterar durante el número de iteraciones deseadas
  for (int i = 0; i < num_iterations; i++) {
    //Elegir una muestra aleatoria
    int index = rand() % inputs.size();
    vector<double> input = inputs[index];
    vector<double> output = outputs[index];
    
    //Ejecutar el algoritmo de backpropagation
    backpropagation(input, output);
    
    //Actualizar el learning rate
    learning_rate *= 0.99;
  }
}

//Definir el constructor de la clase RedNeuronal
RedNeuronal::RedNeuronal(vector<int> layer_sizes) {
  num_inputs = layer_sizes[0];
  num_outputs = layer_sizes[layer_sizes.size() - 1];
  num_layers = layer_sizes.size();
  this->layer_sizes = layer_sizes;
  
  //Inicializar los pesos y bias aleatoriamente
  for (int i = 1; i < num_layers; i++) {
    vector<vector<double>> layer_weights;
    vector<double> layer_bias;
    for (int j = 0; j < layer_sizes[i]; j++) {
      vector<double> weights;
      for (int k = 0; k < layer_sizes[i - 1]; k++) {
        weights.push_back(2.0 * rand() / RAND_MAX - 1.0);
      }
      layer_weights.push_back(weights);
      layer_bias.push_back(2.0 * rand() / RAND_MAX - 1.0);
    }
    weights.push_back(layer_weights);
    bias.push_back(layer_bias);
  }
}

//Definir el método público predict
void RedNeuronal::predict(vector<double> inputs) {
  vector<double> outputs = feedforward(inputs);
  for (int i = 0; i < num_outputs; i++) {
    cout << outputs[i] << " ";
  }
  cout << endl;
}


int main() 
{
    RedNeuronal my({1,1,1});
    vector<vector<double> > i = 
    {
        {1,2,3,4,5}
    }
    vector<vector<double> > o = 
    {
        {1,2,3,4,5}
    }
    my.train()
}