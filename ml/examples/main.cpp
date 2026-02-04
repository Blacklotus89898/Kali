#include <iostream>
#include <vector>
#include "core/Autograd.hpp"
#include "core/DataGenerator.hpp"
#include "core/DataLoader.hpp"
#include "layers/Linear.hpp"
#include "functions/Activations.hpp"
#include "functions/Loss.hpp"
#include "optim/RMSProp.hpp"

using namespace ml;

int main() {
    const std::string spiralFile = "spiral_data.csv";
    int n_points = 300; // 300 points per arm = 600 total
    
    DataGenerator::generateSpiralData(spiralFile, n_points, 0.01);
    auto [raw_X, raw_Y] = DataLoader::loadCSV(spiralFile, n_points * 2, 2, 1);

    auto X = std::make_shared<Variable>(raw_X);
    auto Y = std::make_shared<Variable>(raw_Y);

    // 2. Deeper Model: 2 -> 32 -> 16 -> 1
    Linear l1(2, 32);
    LeakyReLU a1(0.1);
    Linear l2(32, 16);
    LeakyReLU a2(0.1);
    Linear l3(16, 1);

    std::vector<Linear*> model_layers = {&l1, &l2, &l3};
    RMSProp optimizer(0.002); // Spiral is sensitive, lower LR helps
    
    std::cout << "Training on the Spiral Problem (3-Layer Network)...\n";

    for (int epoch = 0; epoch <= 1000; ++epoch) {
        // --- Forward (Deep Chain) ---
        auto h1 = a1.forward_autograd(l1.forward_autograd(X));
        auto h2 = a2.forward_autograd(l2.forward_autograd(h1));
        auto preds = l3.forward_autograd(h2);
        auto loss = MSE_Autograd(preds, Y);

        // --- Backward ---
        l1.zero_grad();
        l2.zero_grad();
        l3.zero_grad();
        loss->backward();

        // --- Step ---
        optimizer.step(model_layers);

        if (epoch % 100 == 0) {
            int correct = 0;
            for(int i=0; i < n_points * 2; ++i) {
                int p = (preds->data(i,0) > 0.5) ? 1 : 0;
                if (p == static_cast<int>(Y->data(i,0))) correct++;
            }
            std::cout << "Epoch " << epoch << " | Loss: " << loss->data.data[0] 
                      << " | Accuracy: " << (static_cast<double>(correct)/(n_points*2)) * 100 << "%\n";
        }
    }

    return 0;
}
