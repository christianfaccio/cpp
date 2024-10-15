
#pragma once

#include <iostream>
#include <cmath>

class DataProcessor {
public:    
    // Constructor
    DataProcessor(double* data, int size);

    // Copy constructor
    DataProcessor(const DataProcessor& other);

    // Copy assignment operator
    DataProcessor& operator=(const DataProcessor& other);

    // Destructor
    ~DataProcessor();

    // Methods
    int n_elements() const;
    double min_value() const;
    double max_value() const;
    double mean_value() const;
    double std_value() const;

private:
    double* data; // Pointer to hold data
    int size; // Size of the data
};