#include "header_file.hpp"

int main(int argc, char** argv) {
    // Sample array to be processed
    double arr[7] = {2.43, -0.86, 7.19, 4.57, 1.68, 9.32, 5.75};
    
    // Create an instance of DataProcessor
    DataProcessor element_1(arr, 7);
    
    // Display various computed values
    std::cout << "Arr size: " << element_1.n_elements() << std::endl;
    std::cout << "Min value: " << element_1.min_value() << std::endl;
    std::cout << "Max value: " << element_1.max_value() << std::endl;
    std::cout << "Mean value: " << element_1.mean_value() << std::endl;
    std::cout << "Std value: " << element_1.std_value() << std::endl;

    return 0; // Exit program
}