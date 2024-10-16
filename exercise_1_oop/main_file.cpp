#include "header_file.hpp"

int main(int argc, char** argv) {
    // Sample array to be processed
    double arr_1[] = {2.43, -0.86, 7.19, 4.57, 1.68, 9.32, 5.75};
    double arr_2[] = {0.73, -0.45, 0.12, 0.88, -0.67, 0.34, -0.92};
    
    // Create an instance of DataProcessor
    DataProcessor element_1(arr_1, 7);
    DataProcessor element_2(arr_2, 7);
    
    // Display various computed values
    std::cout << "Arr size: " << element_1.n_elements() << std::endl;
    std::cout << "Min value: " << element_1.min_value() << std::endl;
    std::cout << "Max value: " << element_1.max_value() << std::endl;
    std::cout << "Mean value: " << element_1.mean_value() << std::endl;
    std::cout << "Std value: " << element_1.std_value() << std::endl;
    std::cout << "Printing the object: "<< element_1 << std::endl;
    std::cout << "Element in position 1: "<<element_1[1] << std::endl;
    DataProcessor element_3 = element_1 + element_2;
    std::cout << "Object number 3: " << element_3 << std::endl;

    return 0; // Exit program
}
