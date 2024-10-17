
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

    // Overloading Operators as Friends
    friend std::ostream& operator<<(std::ostream& os, const DataProcessor& other);
    DataProcessor operator+(const DataProcessor& other) const;
    double& operator[](const unsigned int index) const;

    // Static get_n_instances() function
    static int get_n_instances();


private:
    double* data; // Pointer to hold data
    int size; // Size of the data
    static int n_instances; // Number of objects created
};
