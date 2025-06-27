#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <map>

using namespace std;

// Carbon emission factors (kg CO2 per unit)
const double CAR_EMISSION = 0.2;    // per km
const double BUS_EMISSION = 0.1;    // per km
const double TRAIN_EMISSION = 0.05; // per km
const double BIKE_EMISSION = 0.005;  // per km
const double WALK_EMISSION = 0.0;    // per km
const double MEAT_MEAL_EMISSION = 3.0;    // per meal
const double VEG_MEAL_EMISSION = 1.5;     // per meal
const double VEGAN_MEAL_EMISSION = 1.0;   // per meal
const double ELECTRICITY_EMISSION = 0.5;  // per kWh

// Eco tips database
vector<string> transportTips = {
    "🚗 Consider carpooling to reduce emissions by up to 50%!",
    "🚌 Using public transport reduces traffic congestion and emissions.",
    "🚆 Trains are one of the most eco-friendly ways to travel long distances.",
    "🚲 Cycling is zero-emission and great for your health!",
    "🚶 Walking produces no emissions and keeps you fit."
};

vector<string> dietTips = {
    "🌱 Meatless Mondays can significantly reduce your carbon footprint.",
    "🥦 Local seasonal vegetables have lower transport emissions.",
    "🍎 Reducing food waste saves all the emissions from production and transport."
};

vector<string> energyTips = {
    "💡 Switch to LED bulbs - they use 75% less energy than incandescent.",
    "🌞 Use natural light whenever possible to reduce electricity use.",
    "❄️ Set your thermostat 1°C lower in winter to save energy."
};

// Function to display welcome message
void displayWelcome() {
    cout << "============================================\n";
    cout << "🌍 GREEN CITY, SMART LIVING: CARBON FOOTPRINT QUIZ 🌱\n";
    cout << "============================================\n\n";
    cout << "This quiz will help you understand your daily carbon emissions\n";
    cout << "and provide personalized tips to reduce your environmental impact.\n\n";
}

// Function to calculate transport emissions
double calculateTransportEmissions() {
    cout << "\n🚗 TRANSPORTATION 🚌\n";
    cout << "How do you typically commute to work/school?\n";
    cout << "1. Car\n2. Bus\n3. Train\n4. Bike\n5. Walk\n";
    cout << "Enter your choice (1-5): ";
    
    int transportChoice;
    cin >> transportChoice;
    
    if (transportChoice < 1 || transportChoice > 5) {
        cout << "Invalid choice. Defaulting to Car.\n";
        transportChoice = 1;
    }
    
    cout << "What is your daily round-trip commute distance in km? ";
    double distance;
    cin >> distance;
    
    double emissions = 0.0;
    string transportType;
    
    switch(transportChoice) {
        case 1:
            emissions = distance * CAR_EMISSION;
            transportType = "car";
            break;
        case 2:
            emissions = distance * BUS_EMISSION;
            transportType = "bus";
            break;
        case 3:
            emissions = distance * TRAIN_EMISSION;
            transportType = "train";
            break;
        case 4:
            emissions = distance * BIKE_EMISSION;
            transportType = "bike";
            break;
        case 5:
            emissions = distance * WALK_EMISSION;
            transportType = "walking";
            break;
    }
    
    cout << "🚦 Your daily commute by " << transportType << " produces " 
         << fixed << setprecision(2) << emissions << " kg of CO2.\n";
    
    return emissions;
}

// Function to calculate diet emissions
double calculateDietEmissions() {
    cout << "\n🍽️ DIET 🥗\n";
    cout << "How many meals per day typically contain meat? ";
    int meatMeals;
    cin >> meatMeals;
    
    cout << "How many vegetarian meals (no meat but may contain dairy/eggs)? ";
    int vegMeals;
    cin >> vegMeals;
    
    cout << "How many vegan meals (no animal products)? ";
    int veganMeals;
    cin >> veganMeals;
    
    double emissions = (meatMeals * MEAT_MEAL_EMISSION) + 
                      (vegMeals * VEG_MEAL_EMISSION) + 
                      (veganMeals * VEGAN_MEAL_EMISSION);
    
    cout << "🍴 Your daily diet produces " << fixed << setprecision(2) 
         << emissions << " kg of CO2.\n";
    
    return emissions;
}

// Function to calculate energy emissions
double calculateEnergyEmissions() {
    cout << "\n💡 ENERGY USE 🔌\n";
    cout << "What is your average daily electricity consumption in kWh? ";
    double electricity;
    cin >> electricity;
    
    double emissions = electricity * ELECTRICITY_EMISSION;
    
    cout << "⚡ Your daily energy use produces " << fixed << setprecision(2) 
         << emissions << " kg of CO2.\n";
    
    return emissions;
}

// Function to display results and tips
void displayResults(double transport, double diet, double energy) {
    double total = transport + diet + energy;
    double yearly = total * 365;
    
    cout << "\n============================================\n";
    cout << "🌱 YOUR CARBON FOOTPRINT RESULTS 🌍\n";
    cout << "============================================\n\n";
    
    cout << "🚗 Transportation: " << transport << " kg CO2/day\n";
    cout << "🍽️ Diet: " << diet << " kg CO2/day\n";
    cout << "💡 Energy: " << energy << " kg CO2/day\n";
    cout << "--------------------------------------------\n";
    cout << "🌍 TOTAL DAILY FOOTPRINT: " << total << " kg CO2\n";
    cout << "📅 YEARLY FOOTPRINT: " << yearly << " kg CO2\n\n";
    
    // Compare to averages
    double avgDaily = 16.0; // Average daily footprint in kg CO2 (varies by country)
    cout << "The average person in developed countries produces about " 
         << avgDaily << " kg CO2 per day.\n";
    
    if (total < avgDaily * 0.7) {
        cout << "🎉 Great job! Your footprint is lower than average!\n";
    } else if (total > avgDaily * 1.3) {
        cout << "⚠️ Your footprint is higher than average. Consider these tips:\n";
    } else {
        cout << "🔄 Your footprint is about average. You can still improve!\n";
    }
    
    // Display personalized tips
    cout << "\n============================================\n";
    cout << "💡 PERSONALIZED ECO TIPS 🌿\n";
    cout << "============================================\n\n";
    
    cout << "🚦 TRANSPORT TIP:\n";
    cout << transportTips[rand() % transportTips.size()] << "\n\n";
    
    cout << "🍴 DIET TIP:\n";
    cout << dietTips[rand() % dietTips.size()] << "\n\n";
    
    cout << "⚡ ENERGY TIP:\n";
    cout << energyTips[rand() % energyTips.size()] << "\n\n";
    
    cout << "Small changes can make a big difference over time! 🌎✨\n";
}

int main() {
    // Seed random number generator for tips
    srand(time(0));
    
    // Display welcome message
    displayWelcome();
    
    // Calculate emissions in each category
    double transport = calculateTransportEmissions();
    double diet = calculateDietEmissions();
    double energy = calculateEnergyEmissions();
    
    // Display results
    displayResults(transport, diet, energy);
    
    // End of program
    cout << "\nPress enter to exit...";
    cin.ignore();
    cin.get();
    
    return 0;
}