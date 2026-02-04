#ifndef DATAGENERATOR_HPP
#define DATAGENERATOR_HPP

#include <fstream>
#include <iostream>
#include <random>
#include <cmath>

namespace ml {

  class DataGenerator {
    public:


      static void generateSpiralData(const std::string& filename, int points_per_arm, double noise = 0.02) {
        std::ofstream file(filename);
        file << "x1,x2,y\n";

        std::mt19937 gen(42);
        std::normal_distribution<double> dist(0, noise);

        for (int arm = 0; arm < 2; ++arm) {
          for (int i = 0; i < points_per_arm; ++i) {
            // Polar coordinates
            double r = static_cast<double>(i) / points_per_arm;
            double t = 1.75 * static_cast<double>(i) / points_per_arm * 2.0 * M_PI + (arm * M_PI);

            // Convert to Cartesian + Noise
            double x1 = r * std::sin(t) + dist(gen);
            double x2 = r * std::cos(t) + dist(gen);

            file << x1 << "," << x2 << "," << arm << "\n";
          }
        }
        file.close();
        std::cout << "Generated " << points_per_arm * 2 << " spiral samples.\n";
      }
      // Generates a dataset where y=1 if x1^2 + x2^2 < radius^2
      static void generateCircleData(const std::string& filename, int num_samples, double noise_level = 0.05) {
        std::ofstream file(filename);
        if (!file.is_open()) {
          std::cerr << "Error: Could not create data file." << std::endl;
          return;
        }

        std::mt19937 gen(1337); // Fixed seed for reproducibility
        std::uniform_real_distribution<double> dist(-1.5, 1.5);
        std::normal_distribution<double> noise(0.0, noise_level);

        file << "x1,x2,y\n";

        double radius_sq = 1.0; // r=1.0

        for (int i = 0; i < num_samples; ++i) {
          double x1 = dist(gen);
          double x2 = dist(gen);

          // Determine label with a bit of noise
          double dist_sq = (x1 * x1) + (x2 * x2);
          int label = (dist_sq < radius_sq) ? 1 : 0;

          // Optional: Flip label occasionally to simulate sensor noise
          file << x1 + noise(gen) << "," << x2 + noise(gen) << "," << label << "\n";
        }

        file.close();
        std::cout << "Generated " << num_samples << " circle samples in " << filename << "\n";
      }

      static void generateXOR(const std::string& filename) {
        std::ofstream file(filename);
        file << "x1,x2,y\n0,0,0\n0,1,1\n1,0,1\n1,1,0\n";
        file.close();
      }
  };

}
#endif
