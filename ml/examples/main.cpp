#include <iostream>
#include <string>
#include "core/DataGenerator.hpp"
#include "core/DataLoader.hpp"
#include "layers/Linear.hpp"
#include "functions/Activations.hpp"
#include "functions/Loss.hpp"

using namespace ml;

int main() {
    const std::string dataFile = "xor_data.csv";

    // 1. Generate the data file
    DataGenerator::generateXOR(dataFile);

    // 2. Load the data (4 samples, 2 inputs, 1 output)
    auto [X, Y] = DataLoader::loadCSV(dataFile, 4, 2, 1);

    // 3. Setup Model (2 -> 8 -> 1)
    // Using LeakyReLU to prevent "Dying ReLU" during Autograd testing
    Linear l1(2, 8);
    LeakyReLU a1(0.01); 
    Linear l2(8, 1);

    // RMSProp usually prefers a smaller, stable learning rate
    double lr = 0.01; 
    int epochs = 3000;

    std::cout << "Training from file: " << dataFile << " using RMSProp...\n";

    // 4. Training Loop
    for (int epoch = 0; epoch <= epochs; ++epoch) {
        // Forward
        Matrix z1 = l1.forward(X);
        Matrix h1 = a1.forward(z1);
        Matrix preds = l2.forward(h1);

        // Loss
        double loss = MSE::compute(preds, Y);

        // Backward (Manual Chain Rule)
        Matrix grad = MSE::backward(preds, Y);
        Matrix grad_l2 = l2.backward(grad);
        Matrix grad_a1 = a1.backward(grad_l2);
        l1.backward(grad_a1);

        // Update (Now uses RMSProp logic internally)
        l1.update(lr);
        l2.update(lr);

        if (epoch % 500 == 0) {
            std::cout << "Epoch " << epoch << " | Loss: " << loss << "\n";
        }
    }

    // 5. Performance Evaluation
    std::cout << "\n--- Performance Analysis ---\n";
    Matrix finalPreds = l2.forward(a1.forward(l1.forward(X)));
    int correct = 0;

    for (int i = 0; i < finalPreds.rows; ++i) {
        // Rounding logic for binary classification
        int prediction = (finalPreds(i, 0) > 0.5) ? 1 : 0;
        int target = static_cast<int>(Y(i, 0)); // Fixed static_cast syntax
        
        if (prediction == target) correct++;

        std::cout << "Input: [" << X(i,0) << "," << X(i,1) << "] "
                  << "Target: " << target << " | Prediction: " << finalPreds(i,0) 
                  << " -> " << (prediction == target ? "PASS" : "FAIL") << "\n";
    }

    std::cout << "---------------------------\n";
    std::cout << "Accuracy: " << (static_cast<double>(correct) / Y.rows) * 100.0 << "%\n";

    return 0;
}
