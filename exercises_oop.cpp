#include <iostream>
#include <cmath>

class DataProcessor {
public:    
    DataProcessor(double* data, int size) : size(size) {
        this -> data[size];
        for (int i = 0; i < size; ++i) {
            this->data[i] = data[i];    
        }
    }

    //copy constructor
    DataProcessor(const DataProcessor& other) : size(other.size) {
        this -> data = new double[other.size];
        for (int i = 0; i < size; ++i){
            data[i] = other.data[i];
        }
    }


    //copy assignment
    DataProcessor& operator = (const DataProcessor& other) {
        if (this != &other) {  // Prevent self-assignment
            delete[] data;  // Clean up old data

            size = other.size;
            data = new double[other.size];  // Allocate new memory
            for (int i = 0; i < other.size; ++i) {
                data[i] = other.data[i];    // Manually copy each element
            }
        }
        return *this;  // Return *this to allow chained assignments
    }

    //destructor
    ~DataProcessor() {
        delete[] data;
    }

    //methods
    int n_elements(){
        return size;
    }

    double min_value() const{
        double min = data[0];
        for (int i = 1; i<size; ++i){
            if (data[i] < min){
                min = data[i];
            }
        }
        return min;
    }

    double max_value() const{
        double max = data[0];
        for (int i = 1; i<size; ++i){
            if (data[i] > max){
                max = data[i];
            }
        }
        return max;
    }

    double mean_value() const{
        double cumsum = 0;
        for (int i=0; i<size; ++i){
            cumsum += data[i];
        }
        return cumsum / size;
    }

    double std_value() const{
        double mean = this->mean_value();
        double sum_diff = 0.;
        for (int i = 0; i<size; ++i){
            sum_diff += std::pow((data[i] - mean),2);
        }
        return sqrt(sum_diff / size);
    }

private:
    double* data;
    int size;
};

int main(int argc, char** argv){
    double arr[7] = {2.43, -0.86, 7.19, 4.57, 1.68, 9.32, 5.75};
    DataProcessor element_1(arr, 7);
    std::cout <<"Arr size: "<< element_1.n_elements() << std::endl;
    std::cout <<"Min value: "<< element_1.min_value() << std::endl;
    std::cout <<"Max value: "<< element_1.max_value() << std::endl;
    std::cout <<"Mean value: "<< element_1.mean_value() << std::endl;
    std::cout <<"Std value: "<< element_1.std_value() << std::endl;

    return 0;
}