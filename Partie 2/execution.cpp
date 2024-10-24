#include <iostream>
#include "BinaryTree.h"
#include "CallOption.h"
#include "PutOption.h"

int main() {
    // Créer un arbre binaire de profondeur 3 pour stocker les résultats
    BinaryTree<double> tree;
    tree.setDepth(3);

    // Définir des valeurs dans l'arbre
    tree.setNode(0, 0, 80);
    tree.setNode(1, 0, 60);
    tree.setNode(1, 1, 40);
    tree.setNode(2, 0, 40);
    tree.setNode(2, 1, 20);
    tree.setNode(2, 2, 0);
    tree.setNode(3, 0, 40);
    tree.setNode(3, 1, 20);
    tree.setNode(3, 2, 0);
    tree.setNode(3, 3, 15);

    // Afficher l'arbre binaire
    std::cout << "Affichage de l'arbre binaire : " << std::endl;
    tree.display();

    // Créer une CallOption et une PutOption
    double expiry = 1.0;
    double strike = 50.0;
    
    CallOption callOption(expiry, strike);
    PutOption putOption(expiry, strike);

    // Exemple de calcul du payoff pour différents prix de l'actif sous-jacent
    double asset_price = 60.0;
    std::cout << "\nPrix de l'actif : " << asset_price << std::endl;
    std::cout << "Payoff de l'option Call : " << callOption.payoff(asset_price) << std::endl;
    std::cout << "Payoff de l'option Put : " << putOption.payoff(asset_price) << std::endl;

    asset_price = 40.0;
    std::cout << "\nPrix de l'actif : " << asset_price << std::endl;
    std::cout << "Payoff de l'option Call : " << callOption.payoff(asset_price) << std::endl;
    std::cout << "Payoff de l'option Put : " << putOption.payoff(asset_price) << std::endl;

    return 0;
}
