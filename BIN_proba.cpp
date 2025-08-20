#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main() {
    std::string nazivDatoteke;
    
    // Unos naziva datoteke od korisnika
    std::cout << "Unesite naziv binarne datoteke: ";
    std::getline(std::cin, nazivDatoteke);
    
    // Otvaranje datoteke u binarnom modu za čitanje
    std::ifstream datoteka(nazivDatoteke, std::ios::binary);
    
    if (!datoteka.is_open()) {
        std::cerr << "Greska: Nije moguce otvoriti datoteku '" << nazivDatoteke << "'" << std::endl;
        return 1;
    }
    
    // Određivanje veličine datoteke
    datoteka.seekg(0, std::ios::end);
    std::streampos velicina = datoteka.tellg();
    datoteka.seekg(0, std::ios::beg);
    
    // Čitanje sadržaja datoteke u vektor znakova
    std::vector<char> nizZnakova(velicina);
    datoteka.read(nizZnakova.data(), velicina);
    
    // Zatvaranje datoteke
    datoteka.close();
    
    // Ispis sadržaja na ekran
    std::cout << "Sadrzaj datoteke:" << std::endl;
    std::cout.write(nizZnakova.data(), nizZnakova.size());
    std::cout << std::endl;
    
    return 0;
}