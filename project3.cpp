#include <iostream>
#include <vector>
#include <iomanip> // For setting precision


// Class for Sieve Analysis
class SieveAnalysis {
public:
    void inputSieveData() {
        int numSieves;
        std::cout << "Enter number of sieves: ";
        std::cin >> numSieves;
        sieveSizes.resize(numSieves);
        weights.resize(numSieves);


        std::cout << "Enter sieve sizes (in mm):\n";
        for (int i = 0; i < numSieves; ++i) {
            std::cin >> sieveSizes[i];
        }


        std::cout << "Enter weights retained on each sieve (in grams):\n";
        for (int i = 0; i < numSieves; ++i) {
            std::cin >> weights[i];
        }
    }


    void calculate() {
        totalWeight = 0;
        cumulativeWeights.clear();
        cumulativePercentages.clear();
        
        for (double weight : weights) {
            totalWeight += weight;
        }


        double cumulativeWeight = 0;
        for (size_t i = 0; i < weights.size(); ++i) {
            cumulativeWeight += weights[i];
            cumulativeWeights.push_back(cumulativeWeight);
            cumulativePercentages.push_back((cumulativeWeight / totalWeight) * 100);
        }
    }


    void displayResults() {
        std::cout << "\nSieve Analysis Results:\n";
        std::cout << std::setw(15) << "Sieve Size (mm)" << std::setw(20) << "Cumulative Weight (g)" << std::setw(30) << "Cumulative Percentage (%)\n";
        for (size_t i = 0; i < sieveSizes.size(); ++i) {
            std::cout << std::setw(15) << sieveSizes[i] << std::setw(20) << cumulativeWeights[i] << std::setw(30) << cumulativePercentages[i] << '\n';
        }
    }


private:
    std::vector<double> sieveSizes;
    std::vector<double> weights;
    double totalWeight;
    std::vector<double> cumulativeWeights;
    std::vector<double> cumulativePercentages;
};


// Class for Consistency Test
class ConsistencyTest {
public:
    void inputConsistencyData() {
        std::cout << "Enter liquid limit (in %): ";
        std::cin >> liquidLimit;


        std::cout << "Enter plastic limit (in %): ";
        std::cin >> plasticLimit;
    }


    void calculate() {
        plasticityIndex = liquidLimit - plasticLimit;
    }


    void displayResults() {
        std::cout << "\nConsistency Test Results:\n";
        std::cout << "Liquid Limit: " << liquidLimit << " %\n";
        std::cout << "Plastic Limit: " << plasticLimit << " %\n";
        std::cout << "Plasticity Index: " << plasticityIndex << " %\n";
    }


private:
    double liquidLimit;
    double plasticLimit;
    double plasticityIndex;
};


// Class for Soil Test (Compaction Test)
class SoilTest {
public:
    void inputSoilData() {
        std::cout << "Enter soil moisture content (in %): ";
        std::cin >> moistureContent;


        std::cout << "Enter dry density (in g/cm^3): ";
        std::cin >> dryDensity;
    }


    void calculate() {
        // Simple example of calculating maximum dry density based on input
        // In real scenarios, you'd use more complex formulas and data
        maxDryDensity = dryDensity; // This is a placeholder
    }


    void displayResults() {
        std::cout << "\nSoil Compaction Test Results:\n";
        std::cout << "Soil Moisture Content: " << moistureContent << " %\n";
        std::cout << "Dry Density: " << dryDensity << " g/cm^3\n";
        std::cout << "Max Dry Density: " << maxDryDensity << " g/cm^3\n";
    }


private:
    double moistureContent;
    double dryDensity;
    double maxDryDensity;
};


int main() {
    SieveAnalysis sieve;
    ConsistencyTest consistency;
    SoilTest soil;


    // Input data
    sieve.inputSieveData();
    consistency.inputConsistencyData();
    soil.inputSoilData();


    // Perform calculations
    sieve.calculate();
    consistency.calculate();
    soil.calculate();


    // Display results
    sieve.displayResults();
    consistency.displayResults();
    soil.displayResults();


    return 0;
}





