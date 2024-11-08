#include "BlackScholesMCPricer.h"
#include <stdexcept>    
#include <vector>

BlackScholesMCPricer::BlackScholesMCPricer(Option* option, double initial_price, double interest_rate, double volatility)
    : option_(option), initial_price_(initial_price), interest_rate_(interest_rate), volatility_(volatility), nb_paths_generated(0), price_estimate(0.0), variance(0.0) {}

void BlackScholesMCPricer::generate(int nb_paths) {
    double sum_payoffs = 0.0;
    double sum_payoffs_squared = 0.0;

    for (int i = 0; i < nb_paths; ++i) {
        double ST; 
        if (option_->isAsianOption()) {
            std::vector<double> prices;
            for (double t : option_->getTimeSteps()) {
                double random_value = MT::rand_norm();
                double price = initial_price_ * std::exp((interest_rate_ - 0.5 * volatility_ * volatility_) * t + volatility * std::sqrt(t) * random_value);
                prices.push_back(price);
            }
            ST = option->payoffPath(prices);
        } else {  // Pour une option européenne
            double random_value = MT::rand_norm();
            ST = initial_price * std::exp((interest_rate - 0.5 * volatility * volatility) + volatility * random_value);
        }

        double payoff = option->payoff(ST) * std::exp(-interest_rate);
        sum_payoffs += payoff;
        sum_payoffs_squared += payoff * payoff;
    }

    nb_paths_generated += nb_paths;
    double mean_payoff = sum_payoffs / nb_paths;
    price_estimate = (price_estimate * (nb_paths_generated - nb_paths) + mean_payoff * nb_paths) / nb_paths_generated;

    variance = (sum_payoffs_squared / nb_paths - mean_payoff * mean_payoff) / nb_paths;
}

// Retourne le nombre de trajectoires générées
int BlackScholesMCPricer::getNbPaths() const {
    return nb_paths_generated;
}

// Retourne l'estimation courante du prix de l'option
double BlackScholesMCPricer::operator()() const {
    if (nb_paths_generated == 0) {
        throw std::logic_error("Aucune trajectoire n'a été générée pour estimer le prix.");
    }
    return price_estimate;
}

// Calcule l'intervalle de confiance à 95 %
std::vector<double> BlackScholesMCPricer::confidenceInterval() const {
    if (nb_paths_generated == 0) {
        throw std::logic_error("Aucune trajectoire n'a été générée pour calculer l'intervalle de confiance.");
    }
    double margin_of_error = 1.96 * std::sqrt(variance / nb_paths_generated);
    return {price_estimate - margin_of_error, price_estimate + margin_of_error};
}
