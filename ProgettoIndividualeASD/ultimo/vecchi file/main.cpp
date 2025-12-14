#include <iostream>
#include "network.h"

int main() {
    network::Network net = network::createEmptyNetwork();



    // Test: aggiungere membri
    std::cout << "Aggiungo membri: Alice, Bob e Carol." << std::endl;
    network::addMember("Alice", net);
    network::addMember("Bob", net);
    network::addMember("Carol", net);

    // Test: diventare amici
    std::cout << "Alice e Bob diventano amici." << std::endl;
    if (network::becomeFriends("Alice", "Bob", net)) {
        std::cout << "Alice e Bob sono ora amici." << std::endl;
    } else {
        std::cout << "Errore nel far diventare amici Alice e Bob." << std::endl;
    }

    // Test: verificare se sono amici
    if (network::areFriends("Alice", "Bob", net)) {
        std::cout << "Alice e Bob sono amici." << std::endl;
    } else {
        std::cout << "Alice e Bob non sono amici." << std::endl;
    }

    // Test: creare un gruppo
    std::cout << "Alice crea un gruppo chiamato 'Amici'." << std::endl;
    if (network::createGroup("Alice", "Amici", net)) {
        std::cout << "Gruppo 'Amici' creato con successo." << std::endl;
    } else {
        std::cout << "Errore nella creazione del gruppo 'Amici'." << std::endl;
    }

    // Test: unire un membro ad un gruppo
    std::cout << "Carol si unisce al gruppo 'Amici'." << std::endl;
    if (network::joinGroup("Carol", "Amici", net)) {
        std::cout << "Carol è ora membro del gruppo 'Amici'." << std::endl;
    } else {
        std::cout << "Errore nel far unire Carol al gruppo 'Amici'." << std::endl;
    }

    // Test: eliminare un membro
    std::cout << "Elimino Alice dalla network." << std::endl;
    if (network::deleteMember("Alice", net)) {
        std::cout << "Alice eliminata con successo." << std::endl;
    } else {
        std::cout << "Errore nell'eliminazione di Alice." << std::endl;
    }

    // Test: eliminare un gruppo
    std::cout << "Elimino il gruppo 'Amici'." << std::endl;
    if (network::deleteGroup("Amici", net)) {
        std::cout << "Gruppo 'Amici' eliminato con successo." << std::endl;
    } else {
        std::cout << "Errore nell'eliminazione del gruppo 'Amici'." << std::endl;
    }

    // Test: lasciare un'amicizia
    std::cout << "Bob e Carol lasciano l'amicizia." << std::endl;
    if (network::leaveFriendship("Bob", "Carol", net)) {
        std::cout << "Bob e Carol non sono più amici." << std::endl;
    } else {
        std::cout << "Errore nel lasciare l'amicizia tra Bob e Carol." << std::endl;
    }

    // Test: network vuota
    if (network::isEmpty(net)) {
        std::cout << "La network è vuota." << std::endl;
    } else {
        std::cout << "La network non è vuota." << std::endl;
    }



    return 0;
}

