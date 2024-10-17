#include "header_file.hpp"

int DataProcessor::n_instances = 0;

// Constructor
DataProcessor::DataProcessor(double* data, int size) : size(size) {
    this->data = new double[size]; // Dynamically allocate memory
    for (int i = 0; i < size; ++i) {
        this->data[i] = data[i];    
    }
    n_instances += 1;
}

// Copy constructor
DataProcessor::DataProcessor(const DataProcessor& other) : size(other.size) {
    this->data = new double[other.size]; // Allocate new memory
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i]; // Copy elements
    }
    n_instances += 1;
}

// Copy assignment operator
DataProcessor& DataProcessor::operator=(const DataProcessor& other) {
    if (this != &other) { // Prevent self-assignment
        delete[] data; // Clean up old data

        size = other.size;
        data = new double[other.size]; // Allocate new memory
        for (int i = 0; i < other.size; ++i) {
            data[i] = other.data[i]; // Manually copy each element
        }
    }
    n_instances += 1;
    return *this; // Return *this to allow chained assignments
}

// Destructor
DataProcessor::~DataProcessor() {
    delete[] data; // Free dynamically allocated memory
}

// Method to return the number of elements
int DataProcessor::n_elements() const {
    return size; // Return the number of elements
}

// Method to find the minimum value
double DataProcessor::min_value() const {
    double min = data[0]; // Initialize min to the first element
    for (int i = 1; i < size; ++i) {
        if (data[i] < min) {
            min = data[i]; // Update min if a smaller value is found
        }
    }
    return min; // Return minimum value
}

// Method to find the maximum value
double DataProcessor::max_value() const {
    double max = data[0]; // Initialize max to the first element
    for (int i = 1; i < size; ++i) {
        if (data[i] > max) {
            max = data[i]; // Update max if a larger value is found
        }
    }
    return max; // Return maximum value
}

// Method to calculate the mean value
double DataProcessor::mean_value() const {
    double cumsum = 0; // Initialize cumulative sum
    for (int i = 0; i < size; ++i) {
        cumsum += data[i]; // Sum up the values
    }
    return cumsum / size; // Return the mean value
}

// Method to calculate the standard deviation
double DataProcessor::std_value() const {
    double mean = this->mean_value(); // Get the mean value
    double sum_diff = 0; // Initialize sum of squared differences
    for (int i = 0; i < size; ++i) {
        sum_diff += std::pow((data[i] - mean), 2); // Sum squared differences
    }
    return std::sqrt(sum_diff / size); // Return standard deviation
}

// << Overloading
std::ostream& operator<<(std::ostream& os, const DataProcessor& other) {
    for(int i = 0; i<other.size; ++i){
        if (i==other.size-1){
            os << other.data[i];
        }
        else{
            os << other.data[i] << ", ";
        }
    };
    return os;
}

// [] Overloading
double& DataProcessor::operator[](const unsigned int index) const{
    return data[index];
}

// + Overloading
DataProcessor DataProcessor::operator+(const DataProcessor& other) const {
    if (this->size != other.size) {
        throw std::invalid_argument("Arrays must be of the same size");
    }

    DataProcessor result(new double[this->size], this->size); // Dynamically allocate
    for (int i = 0; i < this->size; ++i) {
        result[i] = this->data[i] + other.data[i];
    }
    return result; // Return by value
}

// Static get_n_instances() function
int DataProcessor::get_n_instances(){
    return n_instances;
}
